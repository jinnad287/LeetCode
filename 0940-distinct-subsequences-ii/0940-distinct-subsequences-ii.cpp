class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        int MOD = 1e9 + 7;
        // dp[char] = number of distinct subsequences ending with that character
        vector<int> dp(26, 0);

        int total = 0;
        for(char ch : s){
            int char_idx = ch - 'a';
            
            int new_ending_with_char = (total + 1) % MOD;
            int old_ending_with_char = dp[char_idx];

            dp[char_idx] = new_ending_with_char;

            long long updated_total = (long long)total + new_ending_with_char - old_ending_with_char;

            total = (updated_total % MOD + MOD) % MOD;
        }

        return total;

    }
};