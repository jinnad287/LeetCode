class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()==0) return 0;

        stack<int> st;
        st.push(-1);
        int count = 0;
        

        for(int i=0 ; s[i]!='\0' ;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();

                if(st.empty()){

                    st.push(i);
                }
                else{
                    count = max(count,i-st.top());
                }
                

            }
        }
        
        return count;
        
    }
};