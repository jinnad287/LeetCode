class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int mx = nums[0];
        for(int i = 0; i<n; ++i){
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(nums[i], mx);
        }
        
        sort(prefixGcd.begin(), prefixGcd.end());

        int i = 0;
        int j = n-1;
        long long gcdSum = 0;
        while(i < j){
            gcdSum += gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }

        return gcdSum;
    }
};