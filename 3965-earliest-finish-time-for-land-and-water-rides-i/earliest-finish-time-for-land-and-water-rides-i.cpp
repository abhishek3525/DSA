class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans=INT_MAX;
        int n=landStartTime.size();
        int m=waterStartTime.size();
        for(int i=0;i<n;i++){
            int startland=landStartTime[i];
                int endland=startland+landDuration[i];
            for(int j=0;j<m;j++){
                
                int startwater=waterStartTime[j];
                int endwater=startwater+waterDuration[j];
                ans=min(ans,endwater+landDuration[i]+((landStartTime[i]>endwater)?(landStartTime[i]-endwater):0));
                 ans=min(ans,endland+waterDuration[j]+((waterStartTime[j]>endland)?(waterStartTime[j]-endland):0));
            }
        }
        return ans;
    }
};