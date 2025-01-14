class Solution {
public:
    void dfs(int i ,int j,vector<vector<int>>&grid){
        if(i>=grid.size()  || j>=grid[0].size() || i<0 || j<0 || grid[i][j]!=1) return;

        grid[i][j]=-1;
        dfs(i-1,j,grid);
         dfs(i+1,j,grid);
          dfs(i,j-1,grid);
           dfs(i,j+1,grid);

    }
    int numberIsland(vector<vector<int>>grid){
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
    int minDays(vector<vector<int>>& grid) {

        int island =numberIsland(grid);
        if(island>1 || island==0)return 0;
        int countones=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    countones++;
                    grid[i][j]=0;
                    island=numberIsland(grid);
                    if(island>1) return 1;
                    grid[i][j]=1;
                }
            }
        }
        if(countones==1) return 1;
        return 2;
    }
};
