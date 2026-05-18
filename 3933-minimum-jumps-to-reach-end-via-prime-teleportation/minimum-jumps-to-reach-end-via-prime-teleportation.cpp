class Solution {
public:
    

    bool isPrime(int x){
        if(x < 2) return false;
        for(int i=2;i*i<=x;i++){
            if(x%i==0) return false;
        }
        return true;
    }

    vector<int> getFactors(int x){
        vector<int> f;

        for(int p=2;p*p<=x;p++){
            if(x%p==0){
                f.push_back(p);

                while(x%p==0)
                    x/=p;
            }
        }

        if(x>1) f.push_back(x);

        return f;
    }

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        // build divisibility groups
        for(int i=0;i<n;i++){

            vector<int> factors = getFactors(nums[i]);

            for(int p : factors){
                mp[p].push_back(i);
            }
        }

        queue<pair<int,int>> q;
        vector<int> vis(n,0);

        q.push({0,0});
        vis[0]=1;

        while(!q.empty()){

            auto [i,d] = q.front();
            q.pop();

            if(i==n-1) return d;

            // adjacent
            if(i+1<n && !vis[i+1]){
                vis[i+1]=1;
                q.push({i+1,d+1});
            }

            if(i-1>=0 && !vis[i-1]){
                vis[i-1]=1;
                q.push({i-1,d+1});
            }

            // teleport
            if(isPrime(nums[i])){

                int p = nums[i];

                for(int nxt : mp[p]){

                    if(!vis[nxt]){
                        vis[nxt]=1;
                        q.push({nxt,d+1});
                    }
                }

                mp[p].clear();
            }
        }

        return -1;
    }
};
