class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        for idxa, numa in enumerate(nums):
            for idxb in range(idxa+1, len(nums)):
                if numa == nums[idxb]:
                    return True
        return False
         