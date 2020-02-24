# class Solution:
#     def evalRPN(self, tokens: List[str]) -> int:
#         stack = []

#         for token in tokens:
#             if token == '+':
#                 num1 = stack.pop()
#                 num2 = stack.pop()
#                 stack.append(num2 + num1)
#             elif token == '-':
#                 num1 = stack.pop()
#                 num2 = stack.pop()
#                 stack.append(num2 - num1)
#             elif token == '*':
#                 num1 = stack.pop()
#                 num2 = stack.pop()
#                 stack.append(num2 * num1)
#             elif token == '/':
#                 num1 = stack.pop()
#                 num2 = stack.pop()
#                 stack.append(int(num2 / num1))
#             else:
#                 stack.append(int(token))
        
#         return stack[0]

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        add = lambda a, b: a + b
        sub = lambda a, b: a - b
        mul = lambda a, b: a * b
        div = lambda a, b: int(a / b)

        ops = {'+': add, '-': sub, '*': mul, '/': div}

        for token in tokens:
            if token not in ops:
                stack.append(int(token))
            else:
                num1 = stack.pop()
                num2 = stack.pop()
                stack.append(ops[token](num2, num1))
        
        return stack[0]