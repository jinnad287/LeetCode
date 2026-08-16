class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int ans = INT_MAX;
        
        for(int k = 0; k< n; ++k){
            int cost = k;
            
            for(int i = 0; i < n/2; ++i){
                char c1 = s[(k + i) % n];
                char c2 = s[(k + n - 1 - i) % n];
                
                // shortest circular distance
                int diff = abs(c1 - c2);
                cost += min(diff, 26 - diff);
            }
            
            ans = min(ans, cost);
        }
        
        return ans;
        
    }
};