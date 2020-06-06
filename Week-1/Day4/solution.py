class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        i = 0
        while i<n:
            if nums[i] == 0:
                flag = False
                for j in range(i, n):
                    if nums[j] != 0:
                        temp = nums[i]
                        nums[i] = nums[j]
                        nums[j] = temp
                        flag = True
                        break
                
                if flag == False:
                    break
            else:
                i += 1