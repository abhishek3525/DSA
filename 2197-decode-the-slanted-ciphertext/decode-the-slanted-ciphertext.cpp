class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        if (rows == 0)
            return "";

        int cols = s.size() / rows;
        string ans = "";

        for (int startCol = 0; startCol < cols; startCol++) {
            int i = 0, j = startCol;

            while (i < rows && j < cols) {
                ans.push_back(s[i * cols + j]);
                i++;
                j++;
            }
        }
        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};