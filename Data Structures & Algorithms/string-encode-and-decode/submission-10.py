class Solution:

    def encode(self, strs: List[str]) -> str:
        
        code = "".join(f"{len(s)}#{s}" for s in strs)
        return code

    def decode(self, s: str) -> List[str]:
        strs = []
        i = 0
        while i < (len(s)):
            j = s.find("#", i)
            strs.append(s[j+1:j+1+int(s[i:j])])
            i = j+1+int(s[i:j])
        return strs
        
        
