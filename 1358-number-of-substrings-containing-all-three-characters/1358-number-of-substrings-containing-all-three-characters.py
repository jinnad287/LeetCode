class Solution:
    def numberOfSubstrings(self, s: str) -> int:

        last_seen = {'a': -1, 'b': -1, 'c': -1}
        ans = 0
        for i, char in enumerate(s):
            last_seen[char] = i

            if last_seen['a'] != -1 and last_seen['b'] != -1 and last_seen['c'] != -1:
                # min(last_seen.values()) --> starting index of current valid substr = m
                # max(last_seen.values()) --> ending index of current valid substr = n
                # so any index before 'm' might be a valid substr
                # +1 --> adding current valid substr
                ans += min(last_seen.values()) + 1
        
        return ans