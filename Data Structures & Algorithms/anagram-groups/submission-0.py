class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        out = []
        for i in range(len(strs)):
            found = False
            for k in range(len(out)):
                if strs[i] in out[k]:
                    found = True
                    break
            if found:
                continue
            sublist = [strs[i]]
            for j in range(i+1,len(strs)):
                if sorted(strs[i]) == sorted(strs[j]):
                    sublist.append(strs[j])
            out.append(sublist)
        return out