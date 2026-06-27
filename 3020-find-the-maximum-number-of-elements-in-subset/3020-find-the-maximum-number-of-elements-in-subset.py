class Solution(object):
    def maximumLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ## Creating Hashmap
        count = Counter(nums)
        # for worst case senario the max_len = 1
        max_len = 1

        ## for 1's ,because 1 = 1**2 = 1**4 ....
        ## and max_length is always odd
        ## We can select an odd number of 1’s
        if 1 in count:
            ones = count[1]
            max_len = max(max_len, ones if ones%2 != 0 else ones-1)
        
        for x in count:
            # already calculated
            if x == 1:
                continue
            
            curr = x
            length = 1
            
            while count[curr]>=2 and (curr * curr) in count:
                length += 2
                curr = curr * curr
            
            max_len = max(max_len, length)
        

        return max_len
        
        
        