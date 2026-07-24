class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // intution:
        // separate the unique elements in nums
        // we can't do it with 3 for loops (T.C. - O(N^3)) at once like nums[i] ^ nums[j] ^ nums[k] it will give TLE
        // so we can compute first pair wise like nums[i] ^ nums[j] --> O(N^2) and sepate the unique XORs
        // then later againn XOR with nums[k] at O(N)
        // T.C. --> O(N^2) + O(N) --> O(N^2)

        unordered_set<int> unique_nums(nums.begin(), nums.end());

        // nums[i] ^ nums[j] = px(pair_xor)
        unordered_set<int> pair_xors;
        for(auto it1 = unique_nums.begin(); it1 != unique_nums.end(); ++it1){
            for(auto it2 = it1; it2 != unique_nums.end(); ++it2){
                pair_xors.insert(*it1 ^ *it2);
            }
        }
        
        // px ^ nums[k]
        unordered_set<int> triplet_xors;
        for(int px : pair_xors){
            for(int num : unique_nums){
                triplet_xors.insert(px ^ num);
            }
        }
        
        return triplet_xors.size();
    }
};