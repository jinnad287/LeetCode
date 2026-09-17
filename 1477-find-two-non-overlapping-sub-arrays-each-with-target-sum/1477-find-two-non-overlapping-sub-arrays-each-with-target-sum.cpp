class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        // state define:
        // best[i] = minimum length of a valid sub-array ending at or before index i
        vector<int> best(n, INT_MAX); 
        
        int min_len_so_far = INT_MAX; 
        int ans = INT_MAX;
        
        int l = 0;
        int sum = 0;
        
        for(int r = 0; r < n; ++r){
            sum += arr[r];
            
            // if sum exceeds target, shrink the window from the left
            while(sum > target && l <= r){
                sum -= arr[l];
                l++;
            }
            
            if(sum == target){
                int current_len = r - l + 1;
                
                // if there is a valid sub-array strictly before our current one,
                // we calculate the combined length
                if(l > 0 && best[l - 1] != INT_MAX){
                    ans = min(ans, current_len + best[l - 1]);
                }
                
                // update the minimum length found so far
                min_len_so_far = min(min_len_so_far, current_len);
            }
            
            // store the best length found up to the current index r
            best[r] = min_len_so_far;
        }
        
        return ans == INT_MAX ? -1 : ans;

    }
};