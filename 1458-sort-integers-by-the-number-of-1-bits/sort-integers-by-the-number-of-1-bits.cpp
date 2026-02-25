class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>v;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int bits=__builtin_popcount(arr[i]);
            v.push_back({bits,arr[i]});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            arr[i]=v[i].second;
        }
        return arr;
    }
};