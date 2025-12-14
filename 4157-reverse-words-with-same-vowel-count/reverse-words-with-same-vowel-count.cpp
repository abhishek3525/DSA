class Solution {
public:

    int cntvwl(string s){
        int cnt=0;
        for(auto c:s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') cnt++;
        }
        return cnt;
    }

    string reverseWords(string s) {
        stringstream ss(s);
        string token;
        vector<string>words;
        int cnt=0;
        int i=0;
        while(i<s.size() && s[i]!=' '){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')cnt++;
            i++;
        }
        string firstword="";
        while(getline(ss, token,' ')){
            if(token.empty()) continue;
            if(firstword.size()==0) firstword=token;
            int vowels=cntvwl(token);
            if(vowels==cnt) reverse(token.begin(),token.end());
            words.push_back(token);
        }
        string ans=firstword;
        int n=words.size();
        for(int i=1;i<n;i++){
            ans+=" "+words[i];
        }
        return ans;
    }
};