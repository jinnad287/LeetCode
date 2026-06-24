class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> track(n, 0);

        for(int i = 0; i<n; ++i){
            if(lights[i] != 0){
                int v = lights[i];
                int L = max(0, i-v);
                int R = min(n-1, i+v);

                //update in track array using Difference Array Technique
                track[L] += 1;
                if(R+1 < n){
                    track[R+1] -= 1;
                }
            }
        }

        // cummulative sum of track
        for(int i = 1; i<n; ++i){
            track[i] = track[i-1] + track[i];
        }

        // minimum number of additional bulbs required
        int extraBulb = 0;

        for(int i = 0; i< n; ++i){
            if(track[i] == 0){
                extraBulb++;

                track[i] = 1;
                if(i+1 < n){
                    track[i+1] = 1;
                }
                if(i+2 < n){
                    track[i+2] = 1;
                }
            }
        }

        return extraBulb;

    }
};