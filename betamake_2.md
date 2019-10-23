## 一、python 链表操作
* 建立链表
```
#初始化链表结构
class Node:
   def __init__(self,dataVal = None):
       self.dataVal = dataVal
       self.nextVal = None
class TopListNode:
   def __init__(self):
       self.headVal = None
#先建立节点
li = TopListNode()
li.headVal = Node("1")
e2 = Node("2")
e3 = Node("3")
#连接节点
li.headVal.nextVal = e2
e2.nextVal = e3
```
* 链表遍历
```
    def showListNode(self):
        printVal = li.headVal
        while printVal:
            print(prinVal.dataVal)
            printVal = printVal.nextVal
```
* 链表表尾插入新的Node
```
    def appendEnd(self,newNode):
        newNode = Node(newNode)
        if li.headVal is None:
            self.headVal = newNode
            return
         latest = self.headVal
         while (latest.dataVal):
             latest = latest.nextVal
          latest.nextVal = newNode
```
* 链表开始插入Node
```
   def appendStart(self,newNode):
       newNode = Node(newNode)
       if li.headVal is Node :
           li.headVal = newNode
       newNode.nextVal = li.headVal.nextVal
       li.headVal.nextVal= newNode 
```
* 链表中间插入元素
```
   def appendMiddle(self,index,newdata):
       j =0
       newNode  =  Node(newNode)
       latest =  li.headVal
       present = li.headVal
       while latest.nextVal:
           present = latest
           latest = latest.nextVal
           j+=1
       if j = =index:
          newNode.nextVal= present.nextVal
          present.nextVal = newNode   
```
二、解法(按照逆序存储）
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def addTwoNumbers(self, l1, l2):
        target = ListNode(0)   
        p = target
        add = 0   
        while l1 and l2:
            p.next = ListNode((l1.val+l2.val+add)%10)
# //表示地板除法。即先做除法（/），然后向下取整（floor）。至少有一方是float型时，#结果为float型；两个数都是int型时，结果为int型。
            add = (l1.val+l2.val+add)//10
            p, l1, l2 = p.next, l1.next, l2.next
        l1 = l1 if l1 else l2
        while add:
            if l1:
                p.next = ListNode((l1.val+add)%10)
                add = (l1.val+add)//10
                p,l1 = p.next, l1.next
            else:
                p.next = ListNode(add)
                p = p.next
                break
        p.next = l1 
        
        return target.next
#时间复杂度：O(max(m,n))
#空间复杂度O(max(m,n))
```
三、按照正序存储
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def addTwoNumbers(self, l1, l2):
        # 链表中的数字按正序存储的
        m = l1
        n = l2
        len1 = self.getLenth(l1)
        len2 = self.getLenth(l2)
        #将 m 赋为长度短的链表， n 为长度较长的链表
        m = l1 if len1 <= len2 else l2
        n = l1 if len2 <= len1 else l2
        # 对长度短的链表m，前面进行 补0 操作
        for i in range(self.getLenth(m), self.getLenth(n)):
            cur = ListNode(0
            cur.next = m
            m = cur
        result = self.add(m, n)
        if result.val == 0:
            return result.next
        else:
            return result
        
    def getLenth(self,ln):
        count = 0            
        while(ln != None):
            count += 1
            ln = ln.next 
        return count
        
    def add(self, p1, p2):
        add_result = ListNode(0)
        if (p1.next == None):
            num = p1.val + p2.val
            sum = ListNode(num)
            if num > 9:
                add_result.val += 1
                sum.val -= 10
            add_result.next = sum
            return add_result
        else:
            a = self.add(p1.next, p2.next)
            num = p1.val + p2.val + a.val
            sum = ListNode(num)
            sum.next = a.next
            if num > 9:
                add_result.val += 1
                sum.val -= 10
            add_result.next = sum
            return add_result
```
