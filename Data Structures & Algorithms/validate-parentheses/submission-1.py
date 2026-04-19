class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        op = ['(', '{', '[']
        cl = [')', '}', ']']
        for ch in s:
            if ch in op:
                stack.append(ch)
            elif ch in cl:
                if len(stack) == 0:
                    return False
                opener = stack.pop()
                if ((opener == '(' and ch == ')') or
                   (opener == '{' and ch == '}') or
                   (opener == '[' and ch == ']')):
                    continue
                else:
                    return False
            else:
                return False
        if len(stack) != 0:
            return False
        return True

