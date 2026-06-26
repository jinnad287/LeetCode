class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;// cumSum | count
        mp[0] = 1;

        int cumSum = 0;
        long long count_subarray = 0;
        long long validLeftPoints = 0;

        for(int j = 0; j<n; ++j){
            if(nums[j] == target){
                validLeftPoints += mp[cumSum];
                cumSum++;
            }
            else{
                cumSum--;
                validLeftPoints -= mp[cumSum];
            }

            mp[cumSum]++;
            count_subarray += validLeftPoints;
        }

        
        return count_subarray;      
    }
};