class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int total = 0;
        for(int i = 0; i < n; i++){
            total += nums[i];
        }

        // the elements you remove will always be from the two ends
        //therefore, the elements you keep will always be a continuous middle part

        // x will be removed from total
        // now total = rest array after removing elements
        // which is equal to the longest continuous subarray with sum == target
        int target = total - x;

        if(target < 0){
            return -1;
        }

        if(target == 0){
            return n;
        }

        // now we have to find the longest continuous subarray with sum == target
        int i = 0;
        int sum = 0;
        int maxLen = -1;

        for(int j = 0; j < n; j++){
            sum += nums[j];

            while(sum > target && i <= j){
                sum -= nums[i];
                i++;
            }

            if(sum == target){
                maxLen = max(maxLen, j - i + 1);
            }
        }

        if(maxLen == -1){
            return -1;
        }

        return n - maxLen;

    }
};