class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n=nums.size();
        vector<long long >res;
        res.push_back(1LL*nums[0]);
        for(int i=1;i<n;i++){
            long long no=1LL*nums[i];
            while(!res.size()==0 and no==res.back()){
                no=res.back()*2;
                res.pop_back();
            }
            res.push_back(no);
        }
        return res;
    }
};