class KthLargest {
public:
int sz=0;
int total;
priority_queue<int,vector<int>,greater<int>>pq;

    KthLargest(int k, vector<int>& nums) {
        total=k;
        int l=min(k,(int)nums.size());
        for(int i=0;i<l;i++){
            pq.push(nums[i]);
            sz++;

        }
        for(int i=k;i<nums.size();i++){
            if(pq.size()<k){
                pq.push(nums[i]);
                sz++;
                continue;
            }
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(sz<total) {
            pq.push(val);
            sz++;
            
        }
        else if(val>pq.top()){
            pq.pop();
            pq.push(val);
        }
        
        return pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */