#include <string>;
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int right_index = -2;
        for (int i = 0; i < dominoes.length(); i++) {
            if (dominoes[i] == '.') {
                continue;
            }
            else if (dominoes[i] == 'R') {
                if (right_index >= 0) {
                    while(right_index++ < i) {
                        dominoes[right_index] = 'R';
                    }
                }
                right_index = i;
            }
            else if (dominoes[i] == 'L') {
                // Collapse all dominoes
                int left_index = i;
                while (--left_index > right_index + 1 && dominoes[left_index] == '.') {
                    if (right_index >= 0) {
                        right_index++;
                        dominoes[right_index] = 'R';
                    }
                    dominoes[left_index] = 'L';
                }
                right_index = -2;
            }
        }
        // Clean up any right ones not yet fallen
        if (right_index >= 0) {
            while(right_index++ < dominoes.length()) {
                dominoes[right_index] = 'R';
            }
        }
        return dominoes;
    }
};