class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        tmp = []
        tmp = nums[-(k % len(nums)):] + nums[:-(k % len(nums))]
        nums[:] = tmp
