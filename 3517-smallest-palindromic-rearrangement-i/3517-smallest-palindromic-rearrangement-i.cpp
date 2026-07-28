class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for(char& ch : s){
            freq[ch - 'a']++;
        }

        string str1 = "";
        string str2 = "";
        string middle = "";
        for(int i = 0; i<26; ++i){
            //even
            if(freq[i]%2 == 0){
                int x = freq[i] / 2;
                char ch = 'a' + i;
                string padding = "";
                for(int j = 1; j <= x; ++j){
                    padding += ch;
                }

                str1 = str1 + padding;
                str2 = padding + str2;
            }
            else{// odd
                int x = freq[i] / 2;
                char ch = 'a' + i;
                string padding = "";
                for(int j = 1; j <= x; ++j){
                    padding += ch;
                }

                str1 = str1 + padding;
                str2 = padding + str2;
                middle = ch;
            }
        }

        return str1 + middle + str2;
        
    }
};