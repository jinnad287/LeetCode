class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int countSubArray = 0;

        for(int i = 0; i<n; ++i){
            //reseting count for each new starting point
            int count_target = 0;
            for(int j = i; j<n; ++j){
                //increase count_target if we hit nums[j] == target
                if(nums[j] == target){
                    count_target++;
                }

                int subarray_length = j - i + 1;

                if(2 * count_target > subarray_length) countSubArray++;
            }
        }

        return countSubArray;      
    }
};