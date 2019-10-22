一、暴力求解

```
class Solution:
    def twoSum(self, nums, target):
        for i in range(len(nums)):
            j = i+1
            for j in range(len(nums)):
                if (nums[i] == target-nums[j]):
                    return [i,j]
                else:
                    return None
时间复杂度：O（n*n)
空间复杂度：O（1）
```
二、通过字典模拟Hash
```
class Solution:
   def twoSum(self,nums,target):
        dict = {}
        for index,num in enumerate(nums):
            dict[num] = index
        for index,num in enumerate(nums):
            j = dict.get(target-num)
            if j is not None and index !=j:
                return [index,j]
时间复杂度：O(N)
空间复杂度O(N)
```
三、通过一遍字典模拟Hash
```
class Solution:
   def twoSum(self,nums,target):
        dict = {}
        for index, num in enumerate(nums):
            if dict.get(target-num) is not None:
                return [index,dict.get(target-num)]
            dict[num] = index 
时间复杂度：O(N)
空间复杂度：O(N)
```
              
     

