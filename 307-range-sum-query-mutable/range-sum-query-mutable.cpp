class NumArray {
    vector<int>bits;
    int n;
    void updateBits(int idx,int val){
        while(idx<=n){
            bits[idx]+=val;
            idx+=(idx & -idx);
        }
    }
    int sumRangeBits(int pos){
        int sum=0;
        while(pos){
            sum+=bits[pos];
            pos-=(pos & -pos);
        }
        return sum;
    }
public:

    NumArray(vector<int>& nums) {
        n=nums.size();
        bits.resize(n+1,0);
        for(int i=1;i<=n;i++){
            updateBits(i,nums[i-1]);
        }
    }
    
    void update(int index, int val) {
        int oldValue=sumRangeBits(index+1)-sumRangeBits(index);
        updateBits(index+1,-oldValue);
        updateBits(index+1,val);
    }
    
    int sumRange(int left, int right) {
        return sumRangeBits(right+1)-sumRangeBits(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */