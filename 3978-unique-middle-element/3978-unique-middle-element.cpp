class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {

        return count(nums.begin(), nums.end(),  nums[(nums.size() - 1) / 2]) == 1;        
    }
};