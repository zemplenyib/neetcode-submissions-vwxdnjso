class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        prefix, suffix, out = [0]*n, [0]*n, [0]*n
        prefix[0] = 1
        for i in range(1,n):
            prefix[i] = prefix[i-1] * nums[i-1]
        
        suffix[n-1] = 1
        for i in range(n-2,-1,-1):
            suffix[i] = suffix[i+1] * nums[i+1]

        for i in range(n):
            out[i] = prefix[i] * suffix[i]

        return out
        