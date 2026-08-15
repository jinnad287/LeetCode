class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int ans = 0;
        int prev = 0;
        for(int &x : requests){
            ans += abs(prev - x);
            prev = x;
        }

        return ans;
        
    }
};