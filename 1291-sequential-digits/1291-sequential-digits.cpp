class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        int n = s.size();

        int nd_low= 0; // number_of_digits_in_low 
        int temp = low;
        while(temp > 0){
            int d = temp % 10;
            nd_low++;
            temp /= 10;
        }

        int nd_high = 0; //number_of_digits_in_high
        temp = high;
        while(temp > 0){
            int d = temp % 10;
            nd_high++;
            temp /= 10;
        }

        vector<int> ans;

        for(int len = nd_low; len <= nd_high; ++len){
            for(int fd = 0; fd <= n-len; ++fd){
                int num = stoi(s.substr(fd, len));

                if(num >= low && num <= high){
                    ans.push_back(num);
                }
            } 
        }

        return ans;
  
    }
};