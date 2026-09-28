class Solution {
public:
    int maxDepth(string s) {
        //stack
        vector<char> st;
        int ans = 0;

        for(char& ch : s){
            if(ch == '('){
                st.push_back(ch);
                ans = max(ans, (int)st.size());
            }
            else if(ch == ')'){
                st.pop_back();
            }
        }

        return ans;
        
    }
};