class Solution:
    def countValidPrefixes(self, s: str) -> int:
        zeros = 0
        ones = 0
        valid_count = 0
        
        for char in s:
            if char == '0':
                zeros += 1
            else:
                ones += 1
                
            if abs(zeros - ones) <= 1:
                valid_count += 1
                
        return valid_count