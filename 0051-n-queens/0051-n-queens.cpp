class Solution {
public:

    bool isSafe(vector<string>& board, int row, int col, int n){
        // check column
        for(int i = 0; i < row; i++){
            if(board[i][col] == 'Q')
                return false;
        }

        // check upper-left diagonal
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        // check upper-right diagonal
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        return true;
    }


    void solve(int row, int n, vector<string>& board, vector<vector<string>>& ans){

        // all queens are placed
        if(row == n){
            ans.push_back(board);
            return;
        }

        // for each row try every column --> it is safe or not
        for(int col = 0; col < n; ++col){

            if(isSafe(board, row, col, n)){
                board[row][col] = 'Q'; // if the column is safe then place the queen

                solve(row + 1, n, board, ans); // solve the next row

                board[row][col] = '.'; // backtrack to get all possible combinations
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        solve(0, n, board, ans);

        return ans;
    }
};