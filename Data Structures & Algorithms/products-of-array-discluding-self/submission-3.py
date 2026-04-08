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

        out[0] = suffix[0]
        out[n-1] = prefix[n-1]
        for i in range(1, n-1):
            out[i] = prefix[i] * suffix[i]

        return out
        