class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int min = nums[0];
        int max = nums[n-1];
        unordered_set<int> st(nums.begin(),nums.end());
        vector<int> ans;
        for(int i = min ; i<=max ; i++){
            if(!st.count(i)){
                ans.push_back(i);  
            }
        }

        return ans;
        
        
    }
};