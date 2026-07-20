class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])
        total = m * n
        k = k % total
        
        ans = [[0] * n for _ in range(m)]
        
        for i in range(m):
            for j in range(n):
                # Calculate the new flattened index
                new_idx = (i * n + j + k) % total
                
                # Convert back to 2D coordinates
                new_r = new_idx // n
                new_c = new_idx % n
                
                ans[new_r][new_c] = grid[i][j]
                
        return ans
        