class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.data_stack = []
        self.min_stack = []

    def push(self, x: int) -> None:
        self.data_stack.append(x)
        if len(self.min_stack) == 0:
            self.min_stack.append(x)
        else:
            if x < self.min_stack[-1]:
                min_data = x
            else:
                min_data = self.min_stack[-1]
            self.min_stack.append(min_data)

    def pop(self) -> None:
        _ = self.min_stack.pop()
        return self.data_stack.pop()

    def top(self) -> int:
        return self.data_stack[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()