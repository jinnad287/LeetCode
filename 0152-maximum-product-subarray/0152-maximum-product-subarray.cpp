class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxP = INT_MIN;
        
        int product = 1;
        
        // left to Right
        for(int i = 0; i < n; ++i){
            product *= nums[i];
            maxP = max(maxP, product);
            
            if(product == 0){
                product = 1;
            }
        }
        
        product = 1;
        
        // right to Left
        for(int i = n - 1; i >= 0; --i){
            product *= nums[i];
            maxP = max(maxP, product);
            
            if(product == 0){
                product = 1;
            }
        }

        return maxP;
    }
};