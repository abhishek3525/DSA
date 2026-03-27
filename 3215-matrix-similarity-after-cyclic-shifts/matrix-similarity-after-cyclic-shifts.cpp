class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();;
        for(int i=0;i<n;i++){
            int ptr1=0;
            int ptr2=k%m;
            while(ptr1<m){
                if(mat[i][ptr1]!=mat[i][ptr2]) return 0;
                ptr1++;
                ptr2=(ptr2+1)%m;
            }
        }
        return 1;

    }
};