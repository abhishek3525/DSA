class Solution {
public:
    unordered_map<string,vector<int>>mp;
    unordered_map<string,bool>dp;
    bool solve(string curr,int idx,string above){
        if(curr.length()==1) return 1;
        string key=curr+"_"+to_string(idx)+"_"+above;
        if(dp.count(key)) return  dp[key];
        if(idx==curr.length()-1){
            return dp[key]= solve(above,0,"");
        }
       
        
        string pair=curr.substr(idx,2);
        if(mp.find(pair) == mp.end()) return dp[key]= 0;
        for(auto ele:mp[pair]){
            above.push_back(ele);
            if(solve(curr,idx+1,above)) return dp[key]= 1;
            above.pop_back();
            
        }
        return dp[key]= 0;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        
        for(auto ele:allowed){
            mp[ele.substr(0,2)].push_back(ele[2]);
        }
        return solve(bottom,0,"");
    }
};