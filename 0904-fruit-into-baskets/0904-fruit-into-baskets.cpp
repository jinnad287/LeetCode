class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // length of longest possible subarray of exactly two different elements
        int l = 0;
        int r = 0;
        int ans = 0;

        unordered_map<int, int> mp;

        for(int r = 0; r<fruits.size(); ++r){
            // add element to sliding window
            mp[fruits[r]]++;

            // loop to shrink the window while condition is invalid
            while(mp.size() > 2){
                mp[fruits[l]]--;

                if(mp[fruits[l]] == 0){
                    mp.erase(fruits[l]);
                }
                
                l++;
            }

            ans = max(ans, r - l + 1);
        }
        
        return ans;
    }
};