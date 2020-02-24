class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        s_stack = []
        t_stack = []

        for s in S:
            if s == '#' and len(s_stack) != 0:
                s_stack.pop()
            elif s != '#':
                s_stack.append(s)
        for t in T:
            if t == '#' and len(t_stack) != 0:
                t_stack.pop()
            elif t != '#':
                t_stack.append(t)
        
        return s_stack == t_stack