class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        nums1.sort()
        # all even
        if all(num % 2 == 0 for num in nums1):
            return True
        
        # if the first element is odd then always True
        if nums1[0]% 2 == 1:
            return True

        # if the first element is even then not possible, return False
        return False

                
        
        


        