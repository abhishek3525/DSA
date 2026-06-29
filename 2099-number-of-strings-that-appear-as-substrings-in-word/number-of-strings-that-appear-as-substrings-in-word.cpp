class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count=0;
        int n=patterns.size();
        for(int i=0;i<n;i++){
            string s=patterns[i];
            if(word.contains(s)) count++;
        }
        return count;
    }
};