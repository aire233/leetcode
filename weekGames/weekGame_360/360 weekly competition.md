# 360 weekly competition

## [8015. 距离原点最远的点](https://leetcode.cn/problems/furthest-point-from-origin/)

先获取不考虑‘_’的最远距离，即`abs(cnt('R')-cnt('L'))`,之后延当前的最远距离继续移动`cnt('_')`个单位。

```c++
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cnt = 0, m = 0;
        for(auto &x: moves)
        {
            if(x == '_') cnt++;
            else if(x == 'R') m++;
            else m--;
        }
        return abs(m) + cnt;
    }
};
```

## [8022. 找出美丽数组的最小和](https://leetcode.cn/problems/find-the-minimum-possible-sum-of-a-beautiful-array/)

### $\mathrm O(n)$ 的做法：

```c++
class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        // if(n == 1) return target;
        long long sum = 0;
        int rec[200000] = {0};
        for(int l = 0, j = 1; l < n; j++)
        {
            if(rec[j] == 0)
            {
                if(target - j > 0) rec[target - j] = 1;
                sum += j;
                l++;
            }
        }
        return sum;
    }
};
```

### $\mathrm O(1)$ 的做法：

贪心：

let `x = target`
the number pairs from which we can only choose one are:

| number_1                  | number_2 |
| ------------------------- | -------- |
| 1                         | x - 1    |
| 2                         | x - 2    |
| ...                       | ...      |
| $\lfloor x \div 2\rfloor$ | -        |

so we choose the former in the list, the answer can be devided as two part:

+ the first part: 1 + ... + min(x//2, n)

+ the last part: x + ... + (x + n - min(x//2, n) - 1)

the answer is $$\frac{m(m+1)+(2k+n-m-1)(n-m)}{2}$$

```c++
class Solution {
public:
    long long minimumPossibleSum(int n, int k) {
        long long m = min(k / 2, n);
        return (m * (m + 1) + (k * 2 + n - m - 1) * (n - m)) / 2;
    }
};

```

## [2835. 使子序列的和等于目标的最少操作次数](https://leetcode.cn/problems/minimum-operations-to-form-subsequence-with-target-sum/)

由于可以把一个数一分为二，所以整个数组可以全部变成`1`。因此如果`nums`的元素和小于`target`，则无解，返回`−1`。否则一定有解。

然后从低位到高位贪心：

+ 如果`target`第`i`位是`0`: `pass`
+ 如果`target`第`i`位是`1`:
  + 记所有小于等于$2^i$的元素和为`s`，若`s`大于等于`target`的第前`i`位的值：`pass`
  + 否则：找到一个更大的数$2^j$不断操作，知道分解出$x^i$为止。==分解后跳到第`j`位开始判断==

```c++
class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        if(accumulate(nums.begin(), nums.end(), 0LL) < target) return -1;
        long long cnt[31] = {0}, s = 0;
        for(auto &x: nums) cnt[__builtin_ctz(x)]++;
        int i = 0, ans = 0;
        while(1LL << i <= target)
        {
            if((s += cnt[i] << i) >= (target & (1LL << ++i) - 1))continue;
            for(ans++;!cnt[i];i++)ans++;
        }
        return ans;
    }
};
```

btw，不开`long long`见祖宗。。。T_T

