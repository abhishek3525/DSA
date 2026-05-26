class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.length();
        vector<int>small(26,0);
        vector<int>large(26,0);
        for(int i=0;i<n;i++){
            if(word[i]>='A' and word[i]<='Z'){
                large[word[i]-'A']++;
            }
            else{
                small[word[i]-'a']++;
            }
        }
        int count=0;
        for(int i=0;i<26;i++){
            if(small[i] and large[i]) count++;
        }
        return count;
    }
};