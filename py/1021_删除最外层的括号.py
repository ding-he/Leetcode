class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        stack = []
        self_str = []
        last_index = 0
        for i, s in enumerate(S):
            if s == '(':
                stack.append(s)
            else:
                stack.pop()
            if not stack:
                # 分解
                self_str.append(S[last_index:i+1])
                last_index = i + 1
        
        res = ''
        for s in self_str:
            res += s[1:-1]
        return res