class Solution(object):
    def maximumElementAfterDecrementingAndRearranging(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        n = len(arr)
        arr.sort()
        arr[0] = 1 ## forcing the first element to be 1
        ans = arr[0]
        for i in range(1,n,1):
            if abs(arr[i] - arr[i - 1]) <= 1:
                ans = arr[i]
            else:
                ans = arr[i-1] + 1
                arr[i] = ans
        
        return arr[n-1]
        