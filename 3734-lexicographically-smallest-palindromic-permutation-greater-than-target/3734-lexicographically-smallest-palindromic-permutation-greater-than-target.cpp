class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
    
        for(char c : s){
            count[c - 'a']++;
        }
        // 1. Check if palindrome is possible and find the middle character
        int count_odd = 0;
        char mid_char = 0;
        for(int i = 0; i < 26; ++i){
            if(count[i] % 2 != 0){
                count_odd++;
                mid_char = (char)(i + 'a');
            }
        }
        if(count_odd > 1) return "";

        // 2. Create the pool for only the left half of the palindrome
        int half_n = n / 2;
        vector<int> left_pool(26, 0);
        for(int i = 0; i < 26; ++i){
            left_pool[i] = count[i] / 2;
        }

        // 3. Check if the exact left half of target can form a valid palindrome > target
        vector<int> temp_pool = left_pool;
        bool can_match = true;
        for(int i = 0; i < half_n; ++i){
            if(temp_pool[target[i] - 'a'] > 0){
                temp_pool[target[i] - 'a']--;
            } else {
                can_match = false;
                break;
            }
        }
        if(can_match){
            string left = target.substr(0, half_n);
            string res = left;
            if(n % 2 != 0) res += mid_char;
            string right = left;
            reverse(right.begin(), right.end());
            res += right;
            if(res > target) return res;
        }

        // 4. Greedily match the prefix of the left half
        int l = 0;
        while(l < half_n && left_pool[target[l] - 'a'] > 0){
            left_pool[target[l] - 'a']--;
            l++;
        }

        // 5. Backtrack on the left half to find the smallest valid substitution
        for(int i = min(l, half_n - 1); i >= 0; --i){
            if(i < l){
                left_pool[target[i] - 'a']++;
            }
            
            for(int c = target[i] - 'a' + 1; c < 26; ++c){
                if(left_pool[c] > 0){
                    string left = target.substr(0, i);
                    left += (char)(c + 'a');
                    left_pool[c]--;
                    for(int j = 0; j < 26; ++j){
                        left.append(left_pool[j], (char)(j + 'a'));
                    }
                    // 6. Mirror the completed left half to form the final palindrome
                    string res = left;
                    if(n % 2 != 0) res += mid_char;
                    string right = left;
                    reverse(right.begin(), right.end());
                    res += right;
                    
                    return res;
                }
            }
        }

        return "";
    }
};