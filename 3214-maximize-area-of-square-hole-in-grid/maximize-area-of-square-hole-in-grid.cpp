class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int diff1 = 1;
        int diff2 = 1;

        for (int i = 0; i < hBars.size(); ) {
            int j = i + 1;
            while (j < hBars.size() && hBars[j] == hBars[j - 1] + 1) {
                j++;
            }
            diff1 = max(diff1, j - i + 1);
            i = j;
        }

        for (int i = 0; i < vBars.size(); ) {
            int j = i + 1;
            while (j < vBars.size() && vBars[j] == vBars[j - 1] + 1) {
                j++;
            }
            diff2 = max(diff2, j - i + 1);
            i = j;
        }

        int side = min(diff1, diff2);
        return side * side;
    }
};
