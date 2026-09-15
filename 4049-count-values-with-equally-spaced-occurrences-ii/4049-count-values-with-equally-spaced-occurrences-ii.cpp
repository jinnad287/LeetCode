class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, pair<int, vector<int>>> mp; // < key, <frequency, vector of index>>
        for(int i = 0; i<n; ++i){
            mp[nums[i]].first++;
            mp[nums[i]].second.push_back(i);
        }

        int ans = 0;

        for(auto& it : mp){
            if(it.second.first < 3) continue;
            // determine the distance
            int d = it.second.second[1] - it.second.second[0];
            bool isSpecial = true;
            for(int i = 1; i<it.second.second.size(); ++i){
                if(it.second.second[i] - it.second.second[i-1] != d){
                    isSpecial = false;
                }
            }

            if(isSpecial) ans++;

        }

        return ans;
        
    }
};