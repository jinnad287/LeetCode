class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int depth = 0;

        for(char& ch : s){
            if(ch == '('){
                // not an outermost '('
                if(depth > 0){
                    ans += ch;
                }

                depth++;
            }
            else{
                depth--;

                // not an outermost ')'
                if(depth > 0){
                    ans += ch;
                }
            }
        }

        return ans;

    }
};