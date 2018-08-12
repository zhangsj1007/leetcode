class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = [0, 0, 0] + nums
        for i,n in enumerate(nums[3:], start=3): nums[i] = max(nums[i-3]+n, nums[i-2] + n, nums[i-1])
        return nums[-1] if nums else 0
