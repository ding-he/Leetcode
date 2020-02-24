class Solution:
    # 
    
    def kthSmallest(self, matrix: [[int]], k: int) -> int:
        left=matrix[0][0]
        right=matrix[-1][-1]
        while left<right:
            mid=(left+right)>>1
            count=self.countsum(matrix,mid)
            if count<k:
                left=mid+1
            else:
                right=mid
        return left

    def countsum(self,matrix,target):
        i=0
        j=len(matrix)-1
        count=0
        while i<len(matrix) and j>=0:
            if matrix[i][j]<=target:
                count+=j+1
                i+=1
            else:
                j-=1
        return count