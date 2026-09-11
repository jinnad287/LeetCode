class Solution {
public:
    vector<vector<int>> memo;

    int solve(int i, int amount, vector<int>& coins){
        if(amount == 0) return 1;
        if(i == coins.size() || amount < 0) return 0;

        if(memo[i][amount] != -1){
            return memo[i][amount];
        }

        // take the coin (stay at index i)
        int take = solve(i, amount - coins[i], coins);
        
        // skip the coin (move to index i + 1)
        int skip = solve(i + 1, amount, coins);

        return memo[i][amount] = take + skip;
    }

    int change(int amount, vector<int>& coins) {
        memo.assign(coins.size(), vector<int>(amount+1, -1));

        return solve(0, amount, coins);
    }
};