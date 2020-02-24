class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []

        if not path:
            return ''

        # split path
        path_array = path.split('/')

        for p in path_array:
            if p == '.':
                pass
            elif p == '..':
                if len(stack) != 0:
                    stack.pop()
            elif p == '':
                pass
            else:
                stack.append(p)
        
        out_path = ''
        for s in stack:
            out_path += '/' + s
        
        if not out_path:
            out_path = '/'
        
        return out_path
