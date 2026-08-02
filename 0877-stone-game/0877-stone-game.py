class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        n = len(piles)
        alice = 0 # even turns
        bob = 0 # odd turns
        l = 0
        r = n-1

        for i in range(n):
            # even
            if i % 2 == 0:
                if piles[l] > piles[r]:
                    alice += piles[l]
                    l += 1
                else:
                    alice += piles[r]
                    r -= 1
            # odd
            else:
                if piles[l] < piles[r]:
                    bob += piles[l]
                    l += 1
                else:
                    bob += piles[r]
                    r -= 1
        
        return alice > bob