class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int n=intervals.size();
        int n1=newInterval.size();
        sort(newInterval.begin(),newInterval.end());
        int i=0;
        int j=0;
        if(n==0) {
            ans.push_back({newInterval[0],newInterval[1]}); 
            j=2;
            }
        while(i<n){
            int low=intervals[i][0];
            int high=intervals[i][1];
            if(j<2 and newInterval[1]<low){
                ans.push_back({newInterval[0],newInterval[1]});
                j=2;
            }
            while(j<n1 and newInterval[j]<=high){
                low=min(low,newInterval[0]);
                high=max(high,newInterval[1]);
                j=2;
            }

            int k=i+1;
            
            while(k<n and intervals[k][0]<=high){
                high=max(high,intervals[k][1]);
                k++;
            }
            
            ans.push_back({low,high});
            i=k;
        }
        if (j==0) ans.push_back({newInterval[0],newInterval[1]});
        return ans;
    }
};