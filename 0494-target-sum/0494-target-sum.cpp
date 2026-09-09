class Solution {
public:
    int n;

    void solve(int i, int sum, int& ans, int& target, vector<int>& nums){
        if(i == n){
            if(sum == target){
                ans++;
            }
            return;
        }

        // do as it is
        solve(i+1, sum + nums[i], ans, target, nums);
        // do -1 with nums[i] to filp the sign
        solve(i+1, sum + (-nums[i]), ans, target, nums);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        int ans = 0;

        solve(0, 0, ans, target, nums);

        return ans;
        
    }
};