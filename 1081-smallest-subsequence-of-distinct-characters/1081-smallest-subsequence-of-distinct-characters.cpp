class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last_idx(26, 0);

        for(int i = 0; i < s.size(); ++i){
            last_idx[s[i] - 'a'] = i;
        }

        vector<bool> seen(26, false);
        string ans = "";
        
        for(int i = 0; i < s.size(); ++i){
            int curr = s[i] - 'a';
            
            // If it's already seen then skip
            if(seen[curr]) continue;
            
            // while the top of the stack > current char && the top of the stack appears again later in the string:
            // so pop it out so we can put a smaller character first
            while(!ans.empty() && ans.back() > s[i] && last_idx[ans.back() - 'a'] > i){
                seen[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            
            ans.push_back(s[i]);
            seen[curr] = true;
        }
        
        return ans;
    }
};