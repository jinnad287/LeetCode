class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq_text(26, 0);
        for(char& ch : text){
            freq_text[ch - 'a']++;
        }

        int b = freq_text['b' - 'a']/1;
        int a = freq_text['a' - 'a']/1;
        int l = freq_text['l' - 'a']/2;
        int o = freq_text['o' - 'a']/2;
        int n = freq_text['n' - 'a']/1;

        return min({b, a, l, o, n});
        
    }
};