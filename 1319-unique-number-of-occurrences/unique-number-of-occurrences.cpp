class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int i=0;
        int ptr=0;
        while(i<n){
            int j=i+1;
            while(j<n and arr[j]==arr[i]) j++;
            arr[ptr]=(j-i);
            i=j;
            ptr++;
        }
        sort(arr.begin(),arr.begin()+ptr);
        for(int i=1;i<ptr;i++){
            if(arr[i]==arr[i-1]) return 0;
        }
        return 1;
    }
};