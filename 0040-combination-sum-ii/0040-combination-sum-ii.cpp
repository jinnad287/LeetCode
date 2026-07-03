class Solution {
public:
    void solve(int i, int target, vector<int>& candidates, vector<int>& currComb, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(currComb);
            return;
        }
        if(i >= candidates.size() || target < 0){
            return;
        }

        
        currComb.push_back(candidates[i]);
        solve(i+1, target - candidates[i], candidates, currComb, ans);
        
        //Backtrack
        currComb.pop_back(); 

        while(i+1 < candidates.size() && candidates[i] == candidates[i+1]){
            i++;
        }
        
        solve(i+1, target, candidates, currComb, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> currComb;
        
        solve(0, target, candidates, currComb, ans);

        return ans;
    }
};