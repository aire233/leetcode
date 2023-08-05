class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for i in range(0, len(s)):
            if s[i] == '(' or s[i] == '[' or s[i] == '{':
                stack.append(s[i])
            elif len(stack) == 0:
                return False
            elif s[i] == ')' and stack.pop() != '(':
                return False
            elif s[i] == ']' and stack.pop() != '[':
                return False
            elif s[i] == '}' and stack.pop() != '{':
                return False
        return len(stack) == 0