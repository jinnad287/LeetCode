class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long power = 1000;
        
        while(n >= power){
            ans += (n - power + 1);
            power *= 1000;
        }

        return ans;



        /*
        if(n < 1e3) return 0;
        long long ans = 0;
        if(n >= 1e3){
            long long end = min(n, 999999LL);
            long long numbers_in_range = end - 1000 + 1;
            ans += (1 * numbers_in_range);
        }
        if(n >= 1e6){
            long long end = min(n, 999999999LL);
            long long numbers_in_range = end - 1e6 + 1;
            ans += (2 * numbers_in_range);
        }
        if(n >= 1e9){
            long long end = min(n, 999999999999LL);
            long long numbers_in_range = end - 1e9 + 1;
            ans += (3 * numbers_in_range);
        }
        if(n >= 1e12){
            long long end = min(n, 999999999999999LL);
            long long numbers_in_range = end - 1e12 + 1;
            ans += (4 * numbers_in_range);
        }
        if(n == 1e15){
            ans += 5;
        }

        return ans;
        */
        
    }
};