class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result = []

        ## to solve this think simple first add ((((....
        ## then close these ))))....
        ## by using backtracking

        def backtrack(curr_str, open_count, close_count):
            if len(curr_str) == 2 * n:
                result.append(curr_str)
                return
            
            # add Open Parentheses untill reached n
            if open_count < n:
                backtrack(curr_str + "(", open_count + 1, close_count)
            
            # add Close Parentheses
            if close_count < open_count:
                backtrack(curr_str + ")", open_count, close_count + 1)


        backtrack("", 0, 0)
        return result
        