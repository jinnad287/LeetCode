class Solution {
public:
    int minRotations(string s) {
        int curr = 0;   // pointer initially at 0
        int ans = 0;

        for(char& ch : s){
            int next = ch - '0';

            int diff = abs(curr - next);

            // since the dial is circular
            int rotations = min(diff, 10 - diff);

            ans += rotations;

            // move pointer to the new digit
            curr = next;
        }

        return ans;

    }
};