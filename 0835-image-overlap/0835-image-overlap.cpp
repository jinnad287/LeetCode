class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1;
        vector<pair<int, int>> ones2;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j] == 1) ones1.push_back({i, j});
                if(img2[i][j] == 1) ones2.push_back({i, j});
            }
        }
        
        
        vector<int> shiftCounts(6000, 0);
        int maxOverlap = 0;
        
        for(const auto& p1 : ones1){
            for(const auto& p2 : ones2){
                int dx = p2.first - p1.first + 30;
                int dy = p2.second - p1.second + 30;
                
                int hash = dx * 100 + dy;
                
                shiftCounts[hash]++;
                maxOverlap = max(maxOverlap, shiftCounts[hash]);
            }
        }
        
        return maxOverlap;
    }
};