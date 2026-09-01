class Solution {
public:

    long long powerMod(long long base, long long exp, long long mod){
        long long result = 1;
        base %= mod;
        while(exp > 0){
            if(exp % 2 == 1){
                result = (result * base) % mod;
            }

            base = (base * base) % mod;
            exp /= 2;
        }

        return result;
    }

    int sumDecoded(vector<long long>& nums) {
        long long MOD = 1e9 + 7;
        long long totalSum = 0;

        for(long long num : nums){
            int width = num % 10;
            long long d = num / 10;

            string s = to_string(d);
            long long x = stoll(s.substr(0, width));
            long long y = stoll(s.substr(width));

            long long decodedValue = powerMod(x, y, MOD);

            totalSum = (totalSum + decodedValue) % MOD;
        }

        return totalSum;
        
    }
};