class Solution {
public:
    int uParentFindfn(int u,vector<int>&uPar){
        if(u==uPar[u]) return u;
        return uPar[u]=uParentFindfn(uPar[u],uPar);
    }
    void rankfn(int uU,int uV,int u,int v,vector<int>&rank,vector<int>&uPar){
        if(rank[uU]>rank[uV]){
            uPar[uV]=uU;
        }
        else if(rank[uU]<rank[uV]) uPar[uU]=uV;
        else {
            uPar[uV]=uU;
            rank[uU]++;
        }

    }
    int makeConnected(int n, vector<vector<int>>& connections) {
     vector<int>uPar(n);
     for(int i=0;i<n;i++){
        uPar[i]=i;
     }
     vector<int>rank(n,0);
     int count1=0;
        for(int i=0;i<connections.size();i++){
            int ultiParU=uParentFindfn(connections[i][0],uPar);
            int ultiParV=uParentFindfn(connections[i][1],uPar);
            if(ultiParU==ultiParV) count1++;
            else{
                rankfn(ultiParU,ultiParV,connections[i][0],connections[i][1],rank,uPar);
            }
        }
        int count2=0;
        for(int i=0;i<n;i++){
            if(uPar[i]==i) count2++;
        }
        return (count1>=(count2-1))?count2-1:-1;
    }
};