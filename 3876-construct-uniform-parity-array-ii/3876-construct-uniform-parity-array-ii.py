class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        n = len(nums1)
        nums1.sort()
        
        smallest_odd_num = 1
        j = -1
        for i in range(0, n):
            if nums1[i] % 2 == 1:
                smallest_odd_num = nums1[i]
                j = i
                break
        # all elements are even
        if j == -1:
            return True
        
        # if the first element is odd then always True
        if nums1[0]% 2 == 1:
            return True

        # if the first element is even then not possible, return False
        return False

                
        
        


        