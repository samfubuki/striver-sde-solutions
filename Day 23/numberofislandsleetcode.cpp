class Solution {
    void dfs(vector<vector<char>> &matrix, int x, int y, int r, int c)
    {
        if(x<0 || x>=r || y<0 || y>=c || matrix[x][y]!='1')
        {
            return;
        }
        matrix[x][y]='2';
        dfs(matrix,x+1,y,r,c);
        dfs(matrix,x,y+1,r,c);
        dfs(matrix,x-1,y,r,c);
        dfs(matrix,x,y-1,r,c);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
       int rows = grid.size();
       if(rows==0)
       {
           return 0;
       }
       int cols = grid[0].size();
       int cnt=0;
       for(int i=0;i<rows;i++)
       {
           for(int j=0;j<cols;j++)
           {
               if(grid[i][j]=='1')
               {
                   dfs(grid,i,j,rows,cols);
                   cnt=cnt+1;
               }
           }
       }
      return cnt;
    }
