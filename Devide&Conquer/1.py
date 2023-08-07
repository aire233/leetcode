class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        if n < 0:
            return 1 / self.myPow(x, -n)
        if n % 2:
            return x * self.myPow(x, n - 1)
        return self.myPow(x * x, n // 2)

class Solution:
    def myPow(self, x: float, n: int) -> float:
        def Mul(N):
            ans = 1.0
            _x = x
            while N:
                if N & 1:
                    ans *= _x
                _x *= _x
                N >>= 1
            return ans
        return Mul(n) if n >= 0 else 1 / Mul(-n)
