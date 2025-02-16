# https://leetcode.com/problems/spiral-matrix-ii/description/
# 59. Spiral Matrix II
# Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
# Input: n = 3
# Output: [[1,2,3],[8,9,4],[7,6,5]]
# Input: n = 1
# Output: [[1]]

class Solution:
    def generateMatrix(self, n: int):
        result = [[0 for i in range(n)] for i in range(n)]
        i = 0
        j = 0
        count = 1
        while i<n and j < n and count <= n*n:
            while j < n-1:
                result[i][j] = count
                j += 1
                count +=1
            while i < n-1:
                result[i][j] = count
                i += 1
                count +=1
        return result

n = 3
sol = Solution()
print(sol.generateMatrix(n))