class Solution:
    def countCommas(self, n: int) -> int:
        if n < 1000:
            return 0

        ans = 0
        if n >= 1000:
            ans = n - 1000 + 1
        
        return ans

        