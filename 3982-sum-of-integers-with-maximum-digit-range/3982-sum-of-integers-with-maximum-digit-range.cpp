class Solution {
public:
    int getRange(int x){
        if(x == 0) return 0;

        int mx = 0;
        int mn = 9;
        while(x > 0){
            int dig = x % 10;

            mx = max(mx, dig);
            mn = min(mn, dig);
            x /= 10;
        }

        return mx - mn;
    }

    int maxDigitRange(vector<int>& nums) {
        int maxRange = 0;
        for(int& num : nums){
            maxRange = max(maxRange, getRange(num));
        }

        int sum = 0;

        for(int& num : nums){
            if(getRange(num) == maxRange) sum += num;
        }

        return sum;
        
    }
};