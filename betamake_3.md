### 3.无重复字符的最长子串

> 题目主要思路为滑动窗口

```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0
        #初始化参数，最左侧的字符。
        left = 0
        string_len = len(s)#长度 
        window_set = set() #开始滑动窗口的载体
        window_length = 0 
        max_length = 0
        for i in range(window):#一个循环 O(N)复杂度
            window_length +=1
            while s[i] in window_set:
                window_set.remove(s[left])
                left +=1
                window_length +=1
            if window_length>max_length:
                max_length = window_length
            window_set.add(s[i])
        return max_length               
```

