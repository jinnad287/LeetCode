class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> count(26, 0);
        int l = 0;
        int maxFreq = 0;
        int maxLength = 0;

        for(int r = 0; r<n; ++r){
            count[s[r] - 'A']++;
            maxFreq = max(maxFreq, count[s[r] - 'A']);

            if((r - l + 1) - maxFreq > k){
                count[s[l] - 'A']--;
                l++; 
            }

            maxLength = max(maxLength, r - l + 1);
        }

        return maxLength;
    }
};