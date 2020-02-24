class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = len(nums) - 2
        while i >= 0:
            if nums[i] < nums[i + 1]:
                break
            else:
                i = i - 1

        if i < 0:
            for k in range(len(nums) - 1):
                for l in range(0, len(nums) - 1 - k):
                    if nums[l] > nums[l + 1]:
                        nums[l], nums[l + 1] = nums[l + 1], nums[l]
        else:
            min_num = max(nums[i+1:]) + 1
            for j in range(len(nums[i+1:])):
                if nums[i] < nums[i + 1 + j] and min_num > nums[i + 1 + j]:
                    min_num = nums[i + 1 + j]
                    min_index = i + 1 + j

            nums[i], nums[min_index] = nums[min_index], nums[i]

            for k in range(len(nums[i+1:]) - 1):
                for l in range(0, len(nums[i+1:]) - 1 - k):
                    if nums[i + 1 + l] > nums[i + 1 + l + 1]:
                        nums[i + 1 + l], nums[i + 1 + l + 1] = nums[i + 1 + l + 1], nums[i + 1 + l]