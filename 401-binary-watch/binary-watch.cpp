class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
        for(int i=0;i<12;i++){
            for(int j=0;j<60;j++){
                int hrs=i;
                int minu=j;
                string s1="";
                int count=0;
                while(hrs){
                    if(hrs&1){
                        count++;
                    }
                    hrs=hrs>>1;
                }
                while(minu){
                    if(minu&1){
                        count++;
                    }
                    minu=minu>>1;
                }
                if(count==turnedOn){
                    s1+=to_string(i);
                    s1+=':';
                    if(j<10){
                        s1.push_back('0');
                        s1.push_back(j+'0');
                    }
                    else{
                        s1+=to_string(j);
                    }
                    ans.push_back(s1);
                }

            }
        }
        return ans;
    }
};