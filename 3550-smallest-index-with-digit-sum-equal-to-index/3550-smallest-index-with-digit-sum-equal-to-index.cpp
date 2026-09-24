class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i<n; ++i){
            int num = nums[i];
            int digit_sum = 0;

            while(num){
                int dig = num % 10;
                digit_sum += dig;

                num /= 10;
            }

            if(i == digit_sum) return i;
        }

        return -1;
        
    }
};