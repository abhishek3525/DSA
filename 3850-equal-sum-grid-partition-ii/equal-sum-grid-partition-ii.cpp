#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPosition(vector<pair<int,int>> &v,int r1,int c1,int r2,int c2,int rows,int cols){
        int l=0,r=v.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(v[mid].first<r1) l=mid+1;
            else r=mid-1;
        }
        while(l<v.size()&&v[l].first<=r2){
            int x=v[l].first,y=v[l].second;
            if(y>=c1&&y<=c2){
                if(rows>1&&cols>1) return true;
                if(rows==1){
                    if(y==c1||y==c2) return true;
                }
                if(cols==1){
                    if(x==r1||x==r2) return true;
                }
            }
            l++;
        }
        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid){
        int n=grid.size(),m=grid[0].size();
        unordered_map<long long, vector<pair<int,int>>> mp;
        long long total=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[grid[i][j]].push_back({i,j});
                total+=grid[i][j];
            }
        }
        for(auto &it:mp) sort(it.second.begin(),it.second.end());
        vector<long long> rowPrefix(n,0);
        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=0;j<m;j++) sum+=grid[i][j];
            rowPrefix[i]=sum+(i?rowPrefix[i-1]:0);
        }
        for(int i=0;i<n-1;i++){
            long long top=rowPrefix[i];
            long long bottom=total-top;
            if(top==bottom) return true;
            long long diff=abs(top-bottom);
            if(top>bottom){
                if(mp.count(diff)){
                    if(validPosition(mp[diff],0,0,i,m-1,i+1,m)) return true;
                }
            }else{
                if(mp.count(diff)){
                    if(validPosition(mp[diff],i+1,0,n-1,m-1,n-i-1,m)) return true;
                }
            }
        }
        vector<long long> colPrefix(m,0);
        for(int j=0;j<m;j++){
            long long sum=0;
            for(int i=0;i<n;i++) sum+=grid[i][j];
            colPrefix[j]=sum+(j?colPrefix[j-1]:0);
        }
        for(int j=0;j<m-1;j++){
            long long left=colPrefix[j];
            long long right=total-left;
            if(left==right) return true;
            long long diff=abs(left-right);
            if(left>right){
                if(mp.count(diff)){
                    if(validPosition(mp[diff],0,0,n-1,j,n,j+1)) return true;
                }
            }else{
                if(mp.count(diff)){
                    if(validPosition(mp[diff],0,j+1,n-1,m-1,n,m-j-1)) return true;
                }
            }
        }
        return false;
    }
};