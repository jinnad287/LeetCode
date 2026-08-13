class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());

        double ans = accumulate(prices.begin(), prices.end(), 0.0);

        int i = prices.size() - 1;
        int j = discounts.size() - 1;

        while(i >= 0 && j >= 0){
            ans -= ((double)prices[i] * discounts[j]) / 100.0;
            i--;
            j--;
        }

        return ans;
    }
};