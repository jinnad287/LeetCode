class Solution {
public:
    int scoreOfParentheses(std::string s) {
        // idea: replace () --> A and (AAA.. N times) = AAAAAA... 2N times
        // then return the size of s

        while(s.find('(') != std::string::npos){
            
            // find the FIRST closing parenthesis
            int right = s.find(')');
            
            // find its matching opening parenthesis
            int left = right - 1;
            while(left >= 0 && s[left] != '('){
                left--;
            }
            
            //count how many 'A's are inside this pair
            int count_A = right - left - 1;
            
            // apply your replacement rules
            int new_A_count = (count_A == 0) ? 1 : count_A * 2;
            
            // build the new string of 'A's
            string replacement(new_A_count, 'A');
            
            // replace the original segment (including parentheses) with the new 'A's
            s.replace(left, right - left + 1, replacement);
        }

        return s.length();

    }
};