class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& v, int freeStart, int freeEnd) {
        sort(v.begin(),v.end());
        int st=v[0][0];
        int end=v[0][1];
        int n=v.size();
        vector<vector<int>>temp;
        for(int i=1;i<n;i++){
            if(end+1 >= v[i][0]) end=max(end,v[i][1]);
            else{
                temp.push_back({st,end});
                st=v[i][0];
                end=v[i][1];
            }
        }
        temp.push_back({st,end});
       
        vector<vector<int>>ans;
        for(int i=0;i<temp.size();i++){
           if(freeEnd>=temp[i][1]){
            if(freeStart<=temp[i][0]) continue;
            if(freeStart<=temp[i][1]) ans.push_back({temp[i][0],freeStart-1});
            else ans.push_back({temp[i][0],temp[i][1]});
           } 
           else if (freeEnd<temp[i][0]) ans.push_back({temp[i][0],temp[i][1]});
           else
           {
            if(freeStart>temp[i][0]){
                ans.push_back({temp[i][0],freeStart-1});
            } 
            ans.push_back({freeEnd+1,temp[i][1]});
            
           }
        }
        return ans;
    }
};