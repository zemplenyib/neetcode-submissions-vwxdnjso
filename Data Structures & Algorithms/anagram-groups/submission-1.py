class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        out = []
        dicts = []
        for i,word in enumerate(strs):
            myDict = dict()
            for letter in word:
                myDict[letter] = myDict.get(letter,0) + 1
            idx = -1
            for i,currDict in enumerate(dicts):
                if currDict == myDict:
                    idx = i
                    break
            if idx != -1:
                if idx == len(out):
                    out.append([word])
                else:
                    out[idx].append(word)
            else:
                dicts.append(myDict)
                out.append([word])
        return out
            

                

        