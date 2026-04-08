class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_map = dict()
        for i,num in enumerate(nums):
            difference = target-num
            j = nums_map.get(difference)
            if j is not None:
                return [j, i]
            else:
                nums_map[num] = i
        return []