class Solution {
public:
    bool can(long long t, vector<int>& workerTimes, long long h){
        long long reduced = 0;

        for(long long w : workerTimes){
            long long q = t / w;

            long long x = (sqrt(1 + 8.0*q) - 1) / 2;

            reduced += x;

            if(reduced >= h) return true;
        }

        return reduced >= h;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        long long l = 0, r = 1e18;
        long long ans = r;

        while(l <= r){
            long long mid = l + (r-l)/2;

            if(can(mid, workerTimes, mountainHeight)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }
};