class Solution {
public:
    int uniquePaths(int m, int n) {
        int total_steps = m + n - 2;

        int k = min(m-1, n-1);
        // for unique paths, from m+n-2 totals steps choose m-1 or n-1 should be down or right
        // for optimization take k = min(m-1, n-1)
        // ans = (m+n-2)C(k)

        long long ans = 1;
        for(int i = 1; i <= k; i++){
            ans = ans * (total_steps - k + i) / i;
        }
        
        return (int)ans;
    }
};