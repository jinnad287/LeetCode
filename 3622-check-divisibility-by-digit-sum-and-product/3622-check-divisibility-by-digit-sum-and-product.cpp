class Solution {
public:
    bool checkDivisibility(int n) {
        int x = n;
        int dig_mul = 1;
        int dig_sum = 0;
        while(x > 0){
            int dig = x % 10;
            dig_mul *= dig;
            dig_sum += dig;

            x /= 10;
        }

        int sum = dig_sum + dig_mul;

        return (n % sum) == 0;
    }
};