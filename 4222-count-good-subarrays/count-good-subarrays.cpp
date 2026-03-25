class Solution {
public:

    bool isPart(string s1,string s2){
        for(int i=0;i<31;i++){
            if(s2[i]=='1' and s1[i]=='0')return false;
        }
        return true;
    }
    string convertToBinaryStringFn(int no){
        string res="";
        for(int i=0;i<31;i++){
            if(no&(1<<i))res.push_back('1');
            else res.push_back('0');
        }
        return res;
    }
    long long countGoodSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n,0);
        vector<int>post(n,n-1);
        vector<string>arr;
        for(int i=0;i<n;i++){
            string s1=convertToBinaryStringFn(nums[i]);
            arr.push_back(s1);
        }
        for(int i=1;i<n;i++){
            string s1=arr[i];
            int j=i-1;
            while(j>=0 and nums[j]!=nums[i] and isPart(s1,arr[j])){
                j=pre[j]-1;
            }
            pre[i]=j+1;
        }
        for(int i=n-2;i>=0;i--){
            string s1=arr[i];
            int j=i+1;
            while(j<n and isPart(s1,arr[j])){
                j=post[j]+1;
            }
            post[i]=j-1;
        }
        long long res=0;
        for(int i=0;i<n;i++){
            int no1=(i-pre[i]+1);
            int no2=(post[i]-i+1);
            res+=(1LL*no1*no2);
        }
        return res;

    }
};