class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        
        int bit_length = log2(n) + 1;

        return 1 << bit_length;
    }
};