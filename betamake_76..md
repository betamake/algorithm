#### 76. 最小覆盖子串

>和第三题（无重复最长字串）一样使用滑动窗口解答
>
>需要用到的collections这个包，defaultdict可以在未初始化key的时候使用。

```python
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        from collections import defaultdict
        lookup = defaultdict(int)
        for c in t:
            lookup[c] += 1 #如果使用普通的字典，会报错 keyerror
        start = 0
        end = 0
        min_len = float("inf") #正无穷：float("inf"); 负无穷：float("-inf")
        counter = len(t) #计数
        res = ""
        while end < len(s):
            if lookup[s[end]] > 0:
                counter -= 1
            lookup[s[end]] -= 1
            end += 1
            while counter == 0:
                if min_len > end - start:
                    min_len = end - start
                    res = s[start:end]
                if lookup[s[start]] == 0:
                    counter += 1
                lookup[s[start]] += 1
                start += 1
        return res
```

