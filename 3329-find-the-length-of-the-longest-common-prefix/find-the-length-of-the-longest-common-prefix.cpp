class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        map<string,int>mp;
        int n1=arr1.size();
        int n2=arr2.size();
        for(int i=0;i<n1;i++){
            int no=arr1[i];
            string s=to_string(no);
            string temp="";
            for(int i=0;i<s.length();i++){
                temp.push_back(s[i]);
                mp[temp]++;
            }
        }
        int count=0;
        for(int i=0;i<n2;i++){
            int no=arr2[i];
            string s=to_string(no);
            string temp="";
            for(int i=0;i<s.length();i++){
                temp.push_back(s[i]);
                if(mp.find(temp)!=mp.end()){
                    count=max(count,i+1);
                }
                
            }
        }
        return count;
    }
    
};