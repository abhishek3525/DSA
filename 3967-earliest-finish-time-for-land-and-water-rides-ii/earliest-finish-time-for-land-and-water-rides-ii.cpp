class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int land=INT_MAX;
        int water=INT_MAX;
        for(int i=0;i<n;i++){
            land=min(land,landStartTime[i]+landDuration[i]);
        }
        for(int i=0;i<m;i++){
            water=min(water,waterStartTime[i]+waterDuration[i]);
        }
        int ans1=INT_MAX;
        int ans2=INT_MAX;
        for(int i=0;i<m;i++){
            if(waterStartTime[i]<=land) ans1=min(ans1,waterDuration[i]+land);
            else ans1=min(ans1,waterDuration[i]+waterStartTime[i]);
        }
        for(int i=0;i<n;i++){
            if(landStartTime[i]<=water) ans2=min(ans2,landDuration[i]+water);
            else ans2=min(ans2,landDuration[i]+landStartTime[i]);
        }
        return min(ans1,ans2);
    }
};