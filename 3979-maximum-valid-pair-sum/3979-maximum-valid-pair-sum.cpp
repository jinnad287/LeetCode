class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        int max_left = 0;
        int max_sum = 0;

        for(int j = k; j<n; ++j){
            max_left = max(max_left, nums[j-k]);

            max_sum = max(max_sum, max_left + nums[j]); 
        }

        return max_sum;
    }
};