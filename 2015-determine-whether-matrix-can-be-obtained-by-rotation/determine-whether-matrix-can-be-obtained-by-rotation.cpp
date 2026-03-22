class Solution {
public:
    vector<vector<int>> fn(vector<vector<int>>& mat){
        int n=mat.size();
        vector<vector<int>>ans(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[j][n-i-1]=mat[i][j];
            }
        }
        return ans;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<vector<int>>ans=mat;
        for(int i=0;i<4;i++){
            if(ans==target) return 1;
            ans=fn(ans);
        }
        return 0;
    }
};