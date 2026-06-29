class Solution:
    def maxSum(self, nums: list[int], k: int, mul: int) -> int:
        nums.sort(reverse=True)
        sum = 0
        for i in range(0,k,1):
            if mul > 0:
                sum += (nums[i] * mul)
            else:
                sum += nums[i]
            mul -= 1
        
        return sum

        