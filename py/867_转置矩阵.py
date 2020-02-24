class Solution:
    def transpose(self, A: List[List[int]]) -> List[List[int]]:
        rows = len(A)
        cols = len(A[0])

        AT = [[0 for i in range(rows)] for j in range(cols)]

        for j in range(cols):
            for i in range(rows):
                AT[j][i] = A[i][j]
        
        return AT