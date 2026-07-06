class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count=0;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            int left=INT_MAX;
            int right=INT_MIN;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(intervals[j][0]<=left) {
                    left=min(left,intervals[j][0]);
                    right=max(right,intervals[j][1]);
                }
                else{
                    left=intervals[j][0];
                    right=intervals[j][1];
                }
                if(intervals[i][0]>=left and intervals[i][1]<=right){
                    count++;
                    break;
                }
            }
        }
        return (n-count);
    }
};