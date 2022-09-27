#include <string>;
using namespace std;

class Solution {
private:
    char findNearestNeighbor(string dominoes, string::size_type i) {
        int low = i - 1;
        int high = i + 1;
        bool isFallingAwayLow = false;
        bool isFallingAwayHigh = false;
        while ((low >= 0 || high < dominoes.length()) && (!isFallingAwayLow || !isFallingAwayHigh)) {
            if (low >= 0 && dominoes[low] == 'L') {
                isFallingAwayLow = true;
            }
            if (high < dominoes.size() && dominoes[high] == 'R') {
                isFallingAwayHigh = true;
            }
            bool isFallingFromLow = low >= 0 && dominoes[low] == 'R';
            bool isFallingFromHigh = high < dominoes.size() && dominoes[high] == 'L';
            // Both dominoes fall each side on domino
            if (isFallingFromLow && !isFallingAwayLow && isFallingFromHigh && !isFallingAwayHigh) {
                return '.';
            }
            else if (isFallingFromLow && !isFallingAwayLow) {
                return 'R';
            }
            else if (isFallingFromHigh && !isFallingAwayHigh) {
                return 'L';
            }
            low--;
            high++;
        }
        return '.';
    }
public:
    string pushDominoes(string dominoes) {
        string final_state = dominoes;
        for (int i = 0; i < dominoes.length(); i++) {
            if (dominoes[i] == '.') {
                final_state[i] = findNearestNeighbor(dominoes, i);
            }
        }
        return final_state;
    }
};