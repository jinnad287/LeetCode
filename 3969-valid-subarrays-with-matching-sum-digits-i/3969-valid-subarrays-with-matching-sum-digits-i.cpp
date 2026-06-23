class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i<n; ++i){
            long long sum = 0;
            for(int j = i; j<n; ++j){
                sum += nums[j];
                long long temp = sum;
                long long div = 1;
                while(temp >0){
                    temp /= 10;
                    div *= 10;
                }
                div /= 10;

                if((sum/div == x) && (sum%10 == x)){
                    ans++;
                }

            }
        }

        return ans;
        
    }
};