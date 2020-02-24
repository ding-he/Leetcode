class Solution:
    def isValid(self, s: str) -> bool:
        if s == '':
            return True
        else:
            stack = []
            match_left = {'(':0, '{':1, '[':2}
            match_right = {')':0, '}':1, ']':2}
            for ss in s:
                if ss in ('(', '{', '['):
                    stack.append(ss)
                elif ss in (')', '}', ']'):
                    if len(stack) == 0:
                        return False
                    else:
                        match_s = stack.pop()
                        if match_left[match_s] != match_right[ss]:
                            return False
            if len(stack) == 0:
                return True
            else:
                return False