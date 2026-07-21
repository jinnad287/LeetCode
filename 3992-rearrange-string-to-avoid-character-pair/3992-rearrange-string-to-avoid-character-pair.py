class Solution:
    def rearrangeString(self, s: str, x: str, y: str) -> str:
        t = list(s)
        i = 0
        
        for j, ch in enumerate(t):
            if ch == y:
                t[i], t[j] = t[j], t[i]
                i += 1
            
        return ''.join(t)
            
        