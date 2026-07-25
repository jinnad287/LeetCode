class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;

        while(n > 0){
            int dig = n % 10;
            digits.push_back(dig);
            n /= 10;
        }

        if(digits.size() == 1) return 0;

        sort(digits.begin(), digits.end());

        return digits[digits.size() - 1] * digits[digits.size() - 2];

    }
};