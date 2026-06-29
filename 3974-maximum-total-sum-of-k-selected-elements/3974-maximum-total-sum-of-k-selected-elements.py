class Solution:
    def maxSum(self, nums: list[int], k: int, mul: int) -> int:
        nums.sort(reverse=True)
        sum = 0
        for i in range(0,k,1):
            op1 = nums[i] * mul
            op2 = nums[i]
            sum += max(op1, op2)
            mul -= 1
        
        return sum

        