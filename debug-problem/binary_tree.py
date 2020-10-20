def bs(nums):
    low, high = 0, len(nums) - 1
    while low < high:
        mid = (low + high)//2
        if nums[mid] == 0:
            low = high = mid
            break
        elif nums[mid] > 0:
            high = mid
        else:
            low = mid + 1
    return nums[low], nums[high]

print(bs([-2, -1, 0, 1, 2]))
print(bs([-2, -1, 1, 2]))
print(bs([-3, -2, -1, 0, 1]))
print(bs([-3, -2, -1, 1]))
print(bs([-7,-3,2,3,11]))