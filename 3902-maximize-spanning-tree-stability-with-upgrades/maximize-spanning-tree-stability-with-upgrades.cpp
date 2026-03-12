class Solution {
public:

    struct DSU {
        vector<int> p,r;
        DSU(int n){
            p.resize(n);
            r.resize(n,0);
            for(int i=0;i<n;i++) p[i]=i;
        }
        int find(int x){
            if(p[x]==x) return x;
            return p[x]=find(p[x]);
        }
        bool unite(int a,int b){
            a=find(a); b=find(b);
            if(a==b) return false;
            if(r[a]<r[b]) swap(a,b);
            p[b]=a;
            if(r[a]==r[b]) r[a]++;
            return true;
        }
    };

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        DSU dsu(n);

        vector<int> mustEdges;
        vector<int> optionalEdges;

        vector<vector<int>> optional;

        int edgeCount=0;

        for(auto &e:edges){
            if(e[3]==1){
                if(!dsu.unite(e[0],e[1])) return -1;
                mustEdges.push_back(e[2]);
                edgeCount++;
            }else{
                optional.push_back(e);
            }
        }

        sort(optional.begin(),optional.end(),
        [](auto &a,auto &b){
            return a[2]>b[2];
        });

        for(auto &e:optional){
            if(edgeCount==n-1) break;

            if(dsu.unite(e[0],e[1])){
                optionalEdges.push_back(e[2]);
                edgeCount++;
            }
        }

        if(edgeCount<n-1) return -1;

        sort(optionalEdges.begin(),optionalEdges.end());

        for(int i=0;i<optionalEdges.size() && k>0;i++,k--){
            optionalEdges[i]*=2;
        }

        int ans=INT_MAX;

        for(int x:mustEdges) ans=min(ans,x);
        for(int x:optionalEdges) ans=min(ans,x);

        return ans;
    }
};