#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &grid,bool visited[][500],int row,int column,int n,int m){
        if(visited[row][column] || grid[row][column]=='0'){return;}
        visited[row][column] = true;
        
        int r,c;
        int i1 = row-1;
        for(int k=0;k<3;k++,i1++){
            int j1 = column-1;
            for(int l=0;l<3;l++,j1++){
                if((0<=i1 && i1<n) && (0<=j1 && j1<m) && !(i1==row && j1==column)){
                    dfs(grid,visited,i1,j1,n,m);
                }
            }
        }
        return;
        
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int count = 0;
        int n=grid.size();
        int m=grid[0].size();
        bool visited[n][500]={0};  
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    dfs(grid,visited,i,j,n,m);
                }
            }
        }
        return count;
    }