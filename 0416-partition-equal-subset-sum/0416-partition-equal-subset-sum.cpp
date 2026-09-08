class Solution {
public:
    bool solve(int i, int current_sum, int target, vector<int>& nums, vector<vector<int>>& memo){
        if(current_sum == target) return true;
        if(i == nums.size() || current_sum > target) return false;

        if(memo[i][current_sum] != -1){
            return memo[i][current_sum];
        }

        bool include = solve(i+1, current_sum + nums[i], target, nums, memo);
        bool exclude = solve(i+1, current_sum, target, nums, memo);

        return memo[i][current_sum] = include || exclude;
    }

    bool canPartition(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        // if total_sum is odd, then partition is not possible
        if(total_sum % 2 != 0){
            return false;
        }

        int target = total_sum / 2;
        vector<vector<int>> memo(nums.size(), vector<int>(target + 1, -1));
        
        return solve(0, 0, target, nums, memo);
    }
};