class Solution {
public:
    double angleClock(int hour, int minutes) {
       hour*=60;
        minutes*=11;
        
            double temp=abs(hour-minutes)/2.0;
            return min(temp,360.00-temp);
       
    }
};