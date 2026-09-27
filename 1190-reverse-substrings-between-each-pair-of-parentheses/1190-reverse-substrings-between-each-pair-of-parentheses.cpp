class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";
        // stack
        vector<int> opened;

        for(char& ch : s){
            if(ch == '('){
                opened.push_back(ans.size());
            }
            else if(ch == ')'){
                int start = opened.back();
                opened.pop_back();

                reverse(ans.begin() + start, ans.end());
            }
            else{
                ans += ch;
            }
        }

        return ans;
        
    }
};