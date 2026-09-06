class Solution {
    int n, m;
    vector<vector<int>> memo;

    // 'i' iterates over 's', 'j' iterates over 't'
    int solve(int i, int j, const string& s, const string& t){
        // Base cases

        if(j == m){// success fully matches all chars
            return 1;
        }
        if(i == n){
            return 0;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int result = 0;

        if(s[i] == t[j]){
            // if match, the we have 2 option:
            // 1. take
            // 2. skip it
            result = solve(i + 1, j + 1, s, t) + solve(i + 1, j, s, t);
        }
        else {
            // don't match
            result = solve(i + 1, j, s, t);
        }

        return memo[i][j] = result;
    }

public:
    int numDistinct(string s, string t) {
        n = s.size();
        m = t.size();
        memo.assign(n, vector<int>(m, -1));

        return solve(0, 0, s, t);
        
    }
};