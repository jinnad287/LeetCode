class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    bool BFS(vector<vector<int>>& grid, queue<pair<int,int>>& q, int& fresh){
        int size = q.size();

        bool rotted = false;

        for(int i = 0; i < size; ++i){

            pair<int,int> f = q.front();
            q.pop();

            int x = f.first;
            int y = f.second;

            // check 4 neighbours
            for(auto& dir : directions){

                int nx = x + dir[0];
                int ny = y + dir[1];

                // boundary check
                if(nx < 0 || ny < 0 || nx >= m || ny >= n){
                    continue;
                }

                // fresh orange
                if(grid[nx][ny] == 1){

                    grid[nx][ny] = 2;
                    fresh--; // reduce the no. of fresh orange

                    q.push({nx, ny}); // push the rotten orange into queue

                    rotted = true;
                }
            }
        }

        return rotted;
    }


    int orangesRotting(vector<vector<int>>& grid){

        m = grid.size();
        n = grid[0].size();

        queue<pair<int,int>> q;

        int fresh = 0;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){

                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int ans = 0;

        while(!q.empty()){

            // one BFS level = one minute
            bool rotted = BFS(grid, q, fresh);

            if(rotted){
                ans++;
            }
        }

        // some fresh oranges could not be reached
        if(fresh > 0){
            return -1;
        }

        return ans;
    }
};