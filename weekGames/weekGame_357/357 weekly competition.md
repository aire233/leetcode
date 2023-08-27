# 357 weekly competition
## [6925. 故障键盘](https://leetcode.cn/problems/faulty-keyboard/)

模拟即可，在出现 'i' 时翻转即可。也可以只使用队列，选择从前面或者后面进行加入新字符，最后确定是从前往后输出还是从后往前。

时间复杂度为 $\mathcal O(n^2)$ 或 $\mathcal O(n)$

### $\mathcal O(n^2)$ 具体代码如下——

```python
class Solution:
    def finalString(self, s: str) -> str:
        ans = []
        for c in s:
            if c == 'i': ans.reverse()
            else: ans.append(c)
        return ''.join(ans)
```

### $\mathcal O(n)$ 具体代码如下——

```python
class Solution:
    def finalString(self, s: str) -> str:
        dq = deque()
        flag = True
        for c in s:
            if c == 'i': flag = not flag
            else:
                if flag: dq.append(c)
                else: dq.appendleft(c)
        return ''.join(dq) if flag else ''.join(list(dq)[::-1])
```

## [6953. 判断是否能拆分数组](https://leetcode.cn/problems/check-if-it-is-possible-to-split-array/)

考虑删除过程中的最短数组，长度为 2，因此，只要有一组相邻和超过了 `m`，那么就可以将数组进行最终的拆分。
除此之外，数组长度小于3的时候也显然可以满足要求。

时间复杂度为 $\mathcal O(n)$。

### 具体代码如下——

```python
class Solution:
    def canSplitArray(self, nums: List[int], m: int) -> bool:
        n = len(nums)
        return n <= 2 or any(nums[i] + nums[i+1] >= m for i in range(n-1))
```


## [6951. 找出最安全路径](https://leetcode.cn/problems/find-the-safest-path-in-a-grid/)


## [6932. 子序列最大优雅度](https://leetcode.cn/problems/maximum-elegance-of-a-k-length-subsequence/)



