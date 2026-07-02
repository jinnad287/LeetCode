class Solution {
public:
    int m, n;
    vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    void backtrack(int i, int j, int health, vector<vector<int>>& grid, bool& ans, vector<vector<int>>& memo){
        
        if(ans) return;
        
        if(i < 0 || j < 0 || i >= m || j >= n) return; 

        if(grid[i][j] == 1) health--;
        if(health < 1) return;
        
        // if we are here before with the same or more health, ignore the path
        if(health <= memo[i][j]) return;
        
        // Record the best 'health' we have achived so far at this cell
        memo[i][j] = health;

        if(i == m-1 && j == n-1){
            ans = true;
            return;
        }

        for(auto& dir: direction){
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            backtrack(new_i, new_j, health, grid, ans, memo);
        }

    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m = grid.size();
        n = grid[0].size();

        bool ans = false;
        
        // Initialize memo array with -1
        vector<vector<int>> memo(m, vector<int>(n, -1));

        backtrack(0, 0, health, grid, ans, memo);

        return ans;
    }
};