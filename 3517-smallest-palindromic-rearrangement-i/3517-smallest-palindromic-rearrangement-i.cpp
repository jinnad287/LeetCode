class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for(char& ch : s){
            freq[ch - 'a']++;
        }

        string str1 = "";
        string middle = "";
        for(int i = 0; i < 26; ++i){
            if(freq[i] == 0) continue;
            
            char ch = 'a' + i;
            // odd --> must be in middle inorder to be a palindrome
            if(freq[i] % 2 != 0){
                middle = ch;
            }
            
            str1 += string(freq[i] / 2, ch);
        }

        string str2 = str1;
        reverse(str2.begin(), str2.end());

        return str1 + middle + str2;
        
    }
};