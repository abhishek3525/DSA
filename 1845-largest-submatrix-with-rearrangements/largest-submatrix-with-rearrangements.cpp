class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                if(matrix[i][j]==0) continue;
                matrix[i][j]+=matrix[i-1][j];
            }
        }
        int ans=0;
        vector<int>v;
        for(int i=0;i<n;i++){
            v=matrix[i];
            sort(v.begin(),v.end());
            for(int j=0;j<m;j++){
                ans=max(ans,(v[j]*(m-j)));
            }
        }
        return ans;
    }
};