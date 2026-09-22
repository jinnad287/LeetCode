class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });

        int ans = 0;

        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){

                if(intervals[i][1] >= intervals[j][0]){
                    ans++;
                }
            }
        }

        return ans;

    }
};