class Solution {
public:
    int dir[5] = {1, 0, -1, 0, 1};
    bool isInRange(int i, int j, int row, int col){
        return (i >= 0 && i < row && j >= 0 && j < col);        
    }
    int getIslandSize(int i, int j, vector<vector<int>>& grid){
        grid[i][j] = 0;
        int result = 0;
        int row=grid.size(), col=grid[0].size(); 
        for(int d = 0; d < 4; d++){
            int next_i = i + dir[d];
            int next_j = j + dir[d + 1];
            if(isInRange(next_i, next_j, row, col) && grid[next_i][next_j]){
                result += 1 + getIslandSize(next_i, next_j, grid);
            }
        }
        return result;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int maxarea = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j]){
                    maxarea = max(maxarea, 1 + getIslandSize(i, j, grid));
                }
            }
        }
        return maxarea;
    }
};