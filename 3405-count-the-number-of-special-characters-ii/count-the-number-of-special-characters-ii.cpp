class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.length();
        vector<int>small(26,-1);
        vector<int>large(26,-1);
        for(int i=0;i<n;i++){
            if(word[i]>='A' and word[i]<='Z'){
               if(large[word[i]-'A']==-1) large[word[i]-'A']=i;
            }
            else{
               small[word[i]-'a']=i;
            }
        }
        int count=0;
        for(int i=0;i<26;i++){
            if(small[i]==-1 or large[i]==-1) continue;
            if(small[i] < large[i]) count++;
        }
        return count;
    }
};