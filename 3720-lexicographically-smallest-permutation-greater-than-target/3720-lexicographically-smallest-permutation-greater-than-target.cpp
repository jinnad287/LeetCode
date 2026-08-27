class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
    
        for(char c : s){
            count[c - 'a']++;
        }

        int l = 0;
        while(l < n && count[target[l] - 'a'] > 0){
            count[target[l] - 'a']--;
            l++;
        }

        for(int i = min(l, n - 1); i >= 0; --i){
            if(i < l){
                count[target[i] - 'a']++;
            }
            
            for(int c = target[i] - 'a' + 1; c < 26; ++c){
                if(count[c] > 0){
                    string res = target.substr(0, i);
                    res += (char)(c + 'a');
                    count[c]--;

                    for(int j = 0; j < 26; ++j){
                        res.append(count[j], (char)(j + 'a'));
                    }
                    
                    return res;
                }
            }
        }

        return "";
    }
};