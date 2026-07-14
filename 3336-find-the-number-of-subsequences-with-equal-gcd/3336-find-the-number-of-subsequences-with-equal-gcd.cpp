class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int MOD = 1e9 + 7;

        int maxValue = 0;
        for(int& x: nums){
            maxValue = max(maxValue, x);
        }

        vector<vector<int>> dp(maxValue+1, vector<int>(maxValue+1, 0));
        // state define: dp[g1][g2] == number of ways to make two subsequences and there GCD is g1 and g2 respectvily
        dp[0][0] = 1;

        // In every x in nums we have 3 choises
        // (i) skip --> Both g1 and g2 remain unchanged
        // (ii) add to sq1 --> g1 = gcd(g1, x) and g2 remain unchanged
        // (iii) add to sq2 --> g2 = gcd(g2, x) and g1 remain unchanged

        for(int& x: nums){
            // (i) skip (initialize next_dp with current dp)
            vector<vector<int>> next_dp = dp;

            for(int g1 = 0; g1 <= maxValue; ++g1){
                for(int g2 = 0; g2 <= maxValue; ++g2){
                    if(dp[g1][g2] == 0) continue;

                    int ways = dp[g1][g2];

                    // (ii) add to sq1
                    int new_g1 = gcd(g1, x);
                    next_dp[new_g1][g2] = (next_dp[new_g1][g2] + ways) % MOD;

                    // (iii) add to sq2
                    int new_g2 = gcd(g2, x);
                    next_dp[g1][new_g2] = (next_dp[g1][new_g2] + ways) % MOD;

                }
            }

            // Move next_dp to current dp for the next iteration
            dp = move(next_dp);
        }

        int ans = 0;
        for(int g = 1; g <= maxValue; ++g){
            ans = (ans + dp[g][g]) % MOD;
        }

        return ans;
        
    }
};