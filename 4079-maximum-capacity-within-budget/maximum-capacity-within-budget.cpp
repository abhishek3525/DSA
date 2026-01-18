class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n=costs.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({costs[i],capacity[i]});
        }
        sort(v.rbegin(),v.rend());
        vector<int>preMax(n);
        preMax[n-1]=v[n-1].second;
        for(int i=n-2;i>=0;i--){
            int temp=v[i].second;
            preMax[i]=max(preMax[i+1],temp);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int maxi=0;
            if(v[i].first>=budget) continue;
            maxi+=v[i].second;
            int bud=budget-v[i].first;
            int low=i+1;
            int high=n-1;
            int temp_cap=0;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(v[mid].first<bud){
                    temp_cap=max(temp_cap,preMax[mid]);
                    high=mid-1;
                }
                else low=mid+1;
            }
            ans=max(ans,maxi+temp_cap);
        }
        return ans;
    }
};