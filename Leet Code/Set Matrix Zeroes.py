class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        row = len(matrix)
        column = len(matrix[0])
        
        rows, cols = set(), set()
        
                  
        for i in range(row):
            for j in range(column):
                if matrix[i][j] == 0:
                    rows.add(i)
                    cols.add(j)
                
        for i in range(row):
            for j in range(column):
                  if i in rows or j in cols:
                    matrix[i][j] = 0