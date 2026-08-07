class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i<n; ++i){
            int x = 0;
            int y = 0;
            for(int j = i; j<n; ++j){
                // even
                if(nums[j]%2 == 0){
                    x++;
                }
                else{ // odd
                    y++;
                }

                if(y > 0 && (x * b) <= (a * y)){
                    ans++;
                }
            }
        }

        return ans;
        
    }
};