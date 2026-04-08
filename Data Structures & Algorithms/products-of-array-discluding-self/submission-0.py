class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        full_prod = 1
        numZero = 0
        out = []
        for n in nums:
            if n == 0:
                numZero += 1
            else:
                full_prod *= n
        if numZero > 1:
            out = [0]*len(nums)
        elif numZero == 1:
            for n in nums:
                if n == 0:
                    out.append(full_prod)
                else:
                    out.append(0)
        else:
            for n in nums:
                    out.append(int(full_prod / n))
        return out
        