class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        n = len(nums)

        if k == n:
            return max(nums)
        
        counts = Counter(nums)

        if k == 1:
            res = -1
            for num, freq in counts.items():
                if freq == 1:
                    res = max(res, num)
                
            return res
        
        ans = -1
        
        if counts[nums[0]] == 1:
            ans = max(ans, nums[0])

        if counts[nums[-1]] == 1:
            ans = max(ans, nums[-1])
        
        return ans