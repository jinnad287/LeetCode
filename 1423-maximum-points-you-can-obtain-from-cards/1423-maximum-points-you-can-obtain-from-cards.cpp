class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> arr;

        // add last k element in original order
        for(int i = n - k; i < n; ++i){
            arr.push_back(cardPoints[i]);
        }
        // add first k elements
        for(int i = 0; i<k; ++i){
            arr.push_back(cardPoints[i]);
        }

        // first window sum
        int sum = 0;
        for(int i = 0; i<k; ++i){
            sum += arr[i];
        }

        int ans = sum;
        for(int i = k; i<arr.size(); ++i){
            sum -= arr[i-k];
            sum += arr[i];
            ans = max(ans, sum);
        }

        return ans;
        
    }
};