class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }
        for (auto it = count.begin(); it != count.end(); ++it) {
            int currentCard = it->first;
            int freq = it->second;
            if (freq > 0) {
                for (int j = 0; j < groupSize; j++) {
                    if (count[currentCard + j] < freq) {
                        return false;
                    }
                    count[currentCard + j] -= freq;
                }
            }
        }
        
        return true;
    }
};