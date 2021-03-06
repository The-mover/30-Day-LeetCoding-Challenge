class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        sum = 0
        for num in nums:
            sum ^= num
        
        return sum
        