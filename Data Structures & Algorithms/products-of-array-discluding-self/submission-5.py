class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        out = [1] * n
        for i in range(1,n):
            out[i] = out[i-1] * nums[i-1]

        running_suffix = 1
        for j in range(n-1,-1,-1):
            out[j] *= running_suffix
            running_suffix *= nums[j]
        
        return out