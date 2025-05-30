class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> sub;
        int left = 0;
        int maxLength = 0;

        for (int i = 0; i < s.size(); i++) {
            while (sub.find(s[i]) != sub.end()) {
                sub.erase(s[left]);
                left++;
            }
            sub.insert(s[i]);
            maxLength = max(maxLength, i - left + 1);
        }

        return maxLength;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool ss[128]{};
        int ans = 0;
        for (int i = 0, j = 0; j < s.size(); ++j) {
            while (ss[s[j]]) {
                ss[s[i++]] = false;
            }
            ss[s[j]] = true;
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};