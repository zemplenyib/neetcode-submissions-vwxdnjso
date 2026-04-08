
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = defaultdict(int)
        for n in nums:
            count[n] = 1 + count[n]
        sorted_dict = dict(sorted(count.items(), key=lambda item: item[1], reverse=True))
        out = []
        for key,value in list(sorted_dict.items())[:k]:
            out.append(key)
        return out