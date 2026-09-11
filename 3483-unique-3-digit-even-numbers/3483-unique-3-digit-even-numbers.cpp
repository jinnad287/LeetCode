class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<int> st;

        for(int i = 0; i < n; ++i){
            // no leading zero
            if(digits[i] == 0) continue; 
            
            for(int j = 0; j < n; ++j){
                // don't reuse the same index
                if(i == j) continue; 
                
                for(int k = 0; k < n; ++k){
                    // don't reuse indices
                    if(i == k || j == k) continue; 
                    // last digit MUST be even in order to get even
                    if(digits[k] % 2 != 0) continue;
                    
                    int z = digits[i] * 100 + digits[j] * 10 + digits[k];
                    
                    st.insert(z);
                }
            }
        }

        return st.size();
    }
};