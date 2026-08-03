class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for(int& astr : asteroids){
            bool destroyed = false;

            while(!st.empty() && st.back() > 0 && astr < 0){
                if(st.back() < -astr){
                    st.pop_back();
                    continue;
                }
                else if(st.back() == -astr){
                    st.pop_back();
                }

                destroyed = true;
                break;
            }

            if(!destroyed){
                st.push_back(astr);
            }
        }

        return st;
        
    }
};