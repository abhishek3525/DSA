class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int even=INT_MAX;
        int odd=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]&1) odd=min(odd,nums1[i]);
            else even=min(even,nums1[i]);
        }
        if(even==INT_MAX or odd==INT_MAX) return true;
        return even>odd;
        
    }
};