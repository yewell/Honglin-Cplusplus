#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std；

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t ret = 0, start = 0;
        unordered_map<char, size_t> trace;
        for (size_t i = 0; i < s.size(); ++i) {
            auto found = trace.find(s[i]);
            if (found != trace.end() && found->second >= start) {
                ret = max(ret, i - start);
                start = found->second + 1;
            }
            trace[s[i]] = i;
        }
        return max(ret, s.size() - start);
    }
};
