class Solution:
    def multiply(self, A: int, B: int) -> int:
        def Mul(N):
            ans = 0
            _A = A
            while N:
                if N & 1:
                    ans += _A
                _A += _A
                N >>= 1
            return ans
        return Mul(B) if B >= 0 else -Mul(-B)