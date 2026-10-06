class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_needed = 0;
        int close_needed = 0;
        
        for(char& ch : s){
            if(ch == '('){
                // we see an open bracket, so we will need a close bracket for that
                close_needed++;
            }
            else{
                // we see a close bracket
                if(close_needed > 0){
                    // it matches with a previous open bracket
                    close_needed--;
                }
                else{
                    // no previous open bracket available to match this, so we need to add an open bracket
                    open_needed++;
                }
            }
        }
        
        return open_needed + close_needed;

    }
};