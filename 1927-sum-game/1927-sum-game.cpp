class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int sumL = 0;
        int sumR = 0;
        int cL = 0;
        int cR = 0;

        for(int i = 0; i < n; ++i){
            if(i < n/2){
                if(num[i] != '?') sumL += (num[i] - '0');
                else cL++;
            }
            else{
                if(num[i] != '?') sumR += (num[i] - '0');
                else cR++;
            }
        }

        // if total '?' is odd, Alice gets the last move and always wins
        if ((cL + cR) % 2 != 0) {
            return true;
        }

        // Bob's winning condition: 
        // diff == C/2 * 9
        if (sumL - sumR == (cR - cL) / 2 * 9) {
            return false; // Bob wins
        }
        
        // otherwise, Alice wins
        return true;
         
    }
};