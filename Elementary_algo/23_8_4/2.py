class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        ans = []
        for i in range(n):
            j = i + 1
            if j % 3 == 0 and j % 5 == 0 :
                ans.append("FizzBuzz")
            elif j % 3 == 0:
                ans.append("Fizz")
            elif j % 5 == 0:
                ans.append("Buzz")
            else:
                ans.append(str(j))

        return ans