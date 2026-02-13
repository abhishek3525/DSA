class Solution {
public:
    
    int getMaxSingle(string& s, char target) {
        int maxLen = 0;
        int currentLen = 0;
        for (char c : s) {
            if (c == target) {
                currentLen++;
            } else {
                currentLen = 0;
            }
            maxLen = max(maxLen, currentLen);
        }
        return maxLen;
    }

    int getMaxDouble(string& s, char c1, char c2) {
        int maxLen = 0;
        int diff = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != c1 && s[i] != c2) {
                mp.clear();
                mp[0] = i;
                diff = 0;
                continue;
            }

            if (s[i] == c1) diff++;
            else diff--;

            if (mp.count(diff)) {
                maxLen = max(maxLen, i - mp[diff]);
            } else {
                mp[diff] = i;
            }
        }
        return maxLen;
    }

    int getMaxTriple(string& s) {
        int maxLen = 0;
        int a = 0, b = 0, c = 0;
        map<pair<int, int>, int> mp;
        mp[{0, 0}] = -1;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a') a++;
            else if (s[i] == 'b') b++;
            else c++;

            int diff1 = a - b;
            int diff2 = b - c;

            if (mp.count({diff1, diff2})) {
                maxLen = max(maxLen, i - mp[{diff1, diff2}]);
            } else {
                mp[{diff1, diff2}] = i;
            }
        }
        return maxLen;
    }

    int longestBalanced(string s) {
        int ans = 0;

        ans = max(ans, getMaxSingle(s, 'a'));
        ans = max(ans, getMaxSingle(s, 'b'));
        ans = max(ans, getMaxSingle(s, 'c'));

        ans = max(ans, getMaxDouble(s, 'a', 'b'));
        ans = max(ans, getMaxDouble(s, 'a', 'c'));
        ans = max(ans, getMaxDouble(s, 'b', 'c'));

        ans = max(ans, getMaxTriple(s));

        return ans;
    }
};
