#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length()==0) return 0;
        int global_max = 0;
        unordered_map<char, int> letter_pos;
        for (int i = 0, j = 0; i < s.length(); i++) {
            if (letter_pos.count(s[i])) {
                // Letter already appeared
                j = max(j, letter_pos.at(s[i])+1);
            }
            letter_pos[s[i]] = i;
            global_max = max(global_max, i-j+1);
        }
        return global_max;
    }
};