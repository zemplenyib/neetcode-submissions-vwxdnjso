class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        full_prod = 1
        numZero = 0
        out = [0] * len(nums)
        for n in nums:
            if n == 0:
                numZero += 1
            else:
                full_prod *= n
        if numZero > 1:
            return out

        if numZero == 1:
            for i in range(len(nums)):
                if nums[i] == 0:
                    out[i] = full_prod
            return out

        for i in range(len(nums)):
                out[i] = full_prod // nums[i]
        return out
        