class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n=asteroids.size();
        sort(asteroids.begin(),asteroids.end());
        int i=0;
        long long sum=mass;
        while(i<n){
            if(asteroids[i]>sum) return 0;;
            sum+=asteroids[i];
            i++;
        }
        return 1;
    }
};