class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long ans = -1;
        
        for(int i = 0; i < n - 1; ++i){
            for (int j = i + 1; j < n; ++j){
                long long g = gcd(nums[i], nums[j]);
                long long curr_ans = (nums[i] / g) * (long long)(nums[j] / g);
                ans = max(ans, curr_ans);
            }
        }

        return ans;
    }
};