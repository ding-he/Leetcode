class Solution:
    def calPoints(self, ops: List[str]) -> int:
        score_stack = []
        score = 0
        def is_number(s):
            try:
                int(s)
                return True
            except ValueError:
                return False
        for option in ops:
            if is_number(option):
                score_stack.append(int(option))
                score += score_stack[-1]
            elif option == '+':
                score_stack.append(score_stack[-1] + score_stack[-2])
                score += score_stack[-1]
            elif option == 'D':
                score_stack.append(score_stack[-1] * 2)
                score += score_stack[-1]
            elif option == 'C':
                score -= score_stack[-1]
                score_stack.pop()
        
        return score