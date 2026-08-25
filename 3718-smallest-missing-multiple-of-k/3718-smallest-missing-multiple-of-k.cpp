class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int max = nums[nums.size()-1];
        
        unordered_set<int> st(nums.begin(),nums.end());

        int i = k;

        while(k<=max){
            if(st.count(k) == 0){
                return k;
            }

            k += i;
        }

        return k;  
    }
};