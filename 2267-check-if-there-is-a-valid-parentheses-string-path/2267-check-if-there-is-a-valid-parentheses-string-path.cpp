class Solution {
public:
    int m, n;

    int memo[101][101][200];

    bool solve(int i, int j, int opened, vector<vector<char>>& grid){
        // bounday ckeck
        if(i >= m || j >= n){
            return false;
        }

        // process this cell
        if(grid[i][j] == '('){
            opened++;
        }
        else{
            opened--;
        }

        if(opened < 0){
            return false;
        }

        // check the final condition
        if(i == m - 1 && j == n - 1){
            return opened == 0;
        }

        if(memo[i][j][opened] != -1){
            return memo[i][j][opened];
        }

        // visited right and down
        bool ans = solve(i, j+1, opened, grid) || solve(i+1, j, opened, grid);

        return memo[i][j][opened] = ans;

    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        // path length = m + n - 1
        // path length has to be even
        if((m + n - 1) % 2 != 0) {
            return false;
        }

        memset(memo, -1, sizeof(memo));

        return solve(0, 0, 0, grid);
        
    }
};