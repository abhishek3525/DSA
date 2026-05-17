class Solution {
public:
    bool fn(vector<int>&arr,int pos,int n,vector<bool>&visited){
        if(pos<0 or pos >=n) return 0;
        if(arr[pos]==0) return 1;
        if(visited[pos]) return false;
        visited[pos]=1;
        
        bool left=fn(arr,pos-arr[pos],n,visited);
        bool right=fn(arr,pos+arr[pos],n,visited);
        visited[pos]=0;
        return left or right;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool>visited(arr.size(),0);
        return fn(arr,start,arr.size(),visited);
    }
};