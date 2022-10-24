#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  bool containsDupes(string str) {
    unordered_set<char> seenCharacters;
    for (auto &character : str) {
      if (seenCharacters.count(character)) {
        return true;
      } else {
        seenCharacters.insert(character);
      }
    }
    return false;
  }
  int getMaxLength(string curr, vector<string> vectorStrings) {
    vector<int> lengths;
    auto it = vectorStrings.begin();
    while (it != vectorStrings.end()) {
      if (containsDupes(curr + *it)) {
        it = vectorStrings.erase(it);
        continue;
      }
      lengths.push_back(getMaxLength(curr + *it, vector<string>(it + 1, vectorStrings.end())));
      it++;
    }
    if (vectorStrings.empty()) {
      return curr.length();
    }
    auto it_max = max_element(lengths.begin(), lengths.end());
    if (it_max != lengths.end()) {
      return *it_max;
    } else {
      return 0;
    }
  }
  int maxLength(vector<string>& arr) {
    return getMaxLength("", arr);
  }
};