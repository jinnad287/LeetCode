class Solution {
public:
    bool check(string a, string b){
        if(a == "") return true; 
        
        if(a.size() > b.size()) return true;
        if(a.size() < b.size()) return false;

        return b < a; 
    }

    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int l = 0;
        int count = 0;
        string ans = "";
        
        for(int r = 0; r < n; ++r){
            if(s[r] == '1'){
                count++;
            }
            
            while(count > k){
                if(s[l] == '1'){
                    count--;
                }
                l++;
            }

            // remove the leading zero's
            while(l <= r && s[l] == '0'){
                l++;
            }

            if(count == k){
                string b = s.substr(l, r - l + 1);
                if(check(ans, b)){
                    ans = b;
                }
            }
        }

        return ans;
    }
};