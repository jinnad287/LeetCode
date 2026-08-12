class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int l = 0;
        int maxLen = 1;
        for(int r = 0; r<n; ++r){
            // add element to the window
            mp[nums[r]]++;
            while(mp[nums[r]] > k){
                mp[nums[l]]--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
        
    }
};