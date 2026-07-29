class Solution {
public:
    bool possible(vector<int>& piles, int h, int k){
        long long H = 0;
        for(int& x : piles){
            H += (x + k - 1) / k; 
        }

        return H <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int lowerBound = 1;
        int upperBound = 0;
        
        for(int& x : piles){
            upperBound = max(upperBound, x);
        }

        int ans = upperBound; // maximum possible answer
        
        while(lowerBound <= upperBound){
            int mid = lowerBound + (upperBound - lowerBound) / 2;
            
            // if possible, save the result and search the left half
            if(possible(piles, h, mid)){
                ans = mid; 
                upperBound = mid - 1;
            }
            else{ 
                // if not possible, search the right half
                lowerBound = mid + 1;
            }
        }

        return ans;
    }
};