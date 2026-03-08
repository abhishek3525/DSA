class Solution {
public:
    long long fn(int low,int high,int enc,int flat,vector<int>&pre){
        long long value;
        int one=pre[high]-(low ? pre[low-1]:0);
        long long val1=LLONG_MAX;
        long long val2=LLONG_MAX;
        if(one) val1=1LL*one*(high-low+1)*enc;
        else val2=1LL*flat;
        value=min(val1,val2);
        
        if((high-low+1)&1) 
        {
            return value;
        }
        int mid=(high+low)/2;
        long long left=fn(low,mid,enc,flat,pre);
        long long right=fn(mid+1,high,enc,flat,pre);
        return min(value,(left+right));
    }
    long long minCost(string s, int encCost, int flatCost) {
        int n=s.length();
        vector<int>pre(n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='1') pre[i]=1;
            if(i>0) pre[i]+=pre[i-1];
        }
        return fn(0,n-1,encCost,flatCost,pre);
    }
};