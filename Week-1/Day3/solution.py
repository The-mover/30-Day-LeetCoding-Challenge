class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxAns, curMax = nums[0], 0
        for num in nums:
            curMax = max(curMax + num, num)
            maxAns = max(maxAns, curMax)
        
        return maxAns
            