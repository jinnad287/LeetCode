class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int ans = 0;
        int curr_zeros = 0; // in window
        int curr_ones = 0; // in window

        for(int r =0; r<n; ++r){
            if(nums[r] == 1){
                curr_ones++;
            }
            else{
                curr_zeros++;
            }

            while(curr_zeros > k){
                if(nums[l] == 1){
                    curr_ones--;
                }
                else{
                    curr_zeros--;
                }

                l++;
            }

            ans = max(ans, curr_ones + curr_zeros);

        }

        return ans;
    }
};