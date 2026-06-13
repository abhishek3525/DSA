class TreeAncestor {
public:
    int rows;
    int cols;
    vector<vector<int>>ancestorTable;
    TreeAncestor(int n, vector<int>& parent) {
        rows=n;
        cols=log2(n)+1;
        ancestorTable.resize(rows,vector<int>(cols,-1));
        for(int i=0;i<n;i++){
            ancestorTable[i][0]=parent[i];
        }
        for(int j=1;j<cols;j++){
            for(int i=0;i<rows;i++){
                if(ancestorTable[i][j-1] != -1)
                    ancestorTable[i][j]=ancestorTable[ancestorTable[i][j-1]][j-1];
            }
        }

    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<cols;i++){
            if(k & (1<<i)){
                node=ancestorTable[node][i];
                if(node==-1) return -1;
            }
            
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */