class Solution {
public:

        //                  Current number
        //                    ↓
        //          ┌───────────────────┐
        //          │                   │
        //          ↓                   ↓
        //   Start new subarray   Extend old subarrays
        //          │                   │
        //          ↓                   ↓
        //       [num]            old subarrays + num
        //          │                   │
        //          └─────────┬─────────┘
        //                    ↓
        //                  ndp
        //                    ↓
        //           add ndp to answer
        //                    ↓
        //                dp = ndp


    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        //dp[r] = number of subarrays ending at the previous position whose product % k == r
        vector<long long> dp(k, 0);

        for(int& num : nums){
            vector<long long> ndp(k, 0);

            // start a new subarray with nums[i]
            ndp[num % k]++;

            //extend all previous subarrays
            for(int r = 0; r < k; r++){
                int newR = (r * (num % k)) % k;
                ndp[newR] += dp[r];
            }

            // all subarrays ending here contribute to answer
            for(int r = 0; r < k; r++){
                ans[r] += ndp[r];
            }

            dp = ndp;
        }

        return ans;

    }
};