class Node:
    """定义节点
    """
    def __init__(self,data,next_node = None):
        self.__data = data
        self.__next = next_node
    @property
    def data(self):
        return self.__data
    @data.setter
    def data(self,data):
        self.__data = data
    @property
    def next_node(self):
        return self.__next
    @next_node.setter
    def next_node(self,next_node):
        self.__next = next_node
class SinglyLinkedList:
    """单向链表和操作
    """
    def __init__(self):
        self.__head = None
    def find_by_value(self,value):
        """按照数据值在单向列表中查找.
        参数:
            value:查找的数据
        返回:
            Node
        """
        node = self.__head
        while (node is not None) and (node.data != value):
            node = node.next_node
        return node
    def find_by_index(self,index):
        """按照索引值在列表中查找.
        参数:
            index:索引值
        返回:
            Node
        """
        node = self.__head
        pos = 0
        while(node is not None) and (pos!=index):
            node  = node.next_node
        return node
    def insert_value_to_head(self,value):
        """在链表的头部插入一个存储value数值的Node节点.
        参数:
            value:将要存储的数据
        """      
        node =Node(value)
        node.next_node = self.__head
        self.__head = node
    def insert_after(self,node,value):
        """在链表的某个指定Node节点之后插入一个存储value数据的Node节点.
        参数:
            node:指定的一个Node节点
            value:将要存储在新Node节点中的数据
        """
        if node is None:
            return
        new_node = Node(value)
        new_node.next_node = node.next
        node.next = new_node
    def insert_before(self,node,value):
        """在链表的某个指定Node节点之前插入一个存储value数据的Node节点.
        参数:
            node:指定的一个Node节点
            value:将要存储在新的Node节点中的数据
        """
        if (node is None) or (self.__head is None):
            return
        if node == self.__head:
            self.insert_to_head(value)
            return
        new_node = Node(value)
        pro = self.__head
        not_found = False
        while pro.next_node !=node:
            if pro.next_node is None:
                not_found = True
                break
            else:
                pro = pro.next_node
        if not not_found:
            pro.next_node = new_node
            new_node.next_node = node
    def delete_by_node(self,node):
        """在链表中删除指定Node的节点.
        参数:
            node:指定的Node节点
        """
        if self.__head is None:
            return
        if node ==self.__head:
            self.__head == node.next_node
            return
        pro = self.__head
        not_found = False
        while pro.next_node != node:
            if pro.next_node is None:
                not_found = True
                break
            else:
                pro = pro.next_node
            if not not_found:
                pro.next_node = node.next_node
    def delete_by_value(self,value):
        """在链表中删除指定存储数据的Node节点.
        参数:
            value:指定的存储数据
        """
        if self.__head is None:
            return
        if self.__head.data == value:
            self.__head =self.__head.next_node
        pro = self.__head
        node = self.__head.next_node
        not_found = False
        while node.data !=  value:
            if node.next_node is None:
                not_found = True
                break
            else:
                pro = node
                node = node.next_node
        if not_found is False:
            pro.next_node = node.next_node
    def delete_last_n_node(self,n):
        """删除链表中倒数第N个节点.
        主体思路：
            设置快、慢两个指针，快指针先行，慢指针不动；当快指针跨了N步以后，快、慢指针同时往链表尾部移动，
            当快指针到达链表尾部的时候，慢指针所指向的就是链表的倒数第N个节点
        参数:
            n:需要删除的倒数第N个序数
        """
        fast = self.__head
        slow = self.__head
        step = 0
        while step <=n:
            fast = fast.next_node
            step+=1
            while fast.next_node is not None:
                tmp =slow
                fast = fast.next_node
                slow = slow.next_node
            tmp.next_node = slow.next_node
    def find_mid_node(self):
        """查找链表中的中间节点.
        主体思想:
            设置快、慢两种指针，快指针每次跨两步，慢指针每次跨一步，则当快指针到达链表尾部的时候，慢指针指向链表的中间节点
        返回:
            node:链表的中间节点
        """
        fast = self.__head
        slow =self.__head
        while fast.next_node is not None:
            fast = fast.next_node.next_node
            slow = slow.next_node
        return slow
    def create_node(self,value):
        """创建一个存储value值的Node节点.
        参数:
            value:将要存储在Node节点中的数据
        返回:
            一个新的Node节点
        """
        return Node(value)
    def print_all(self):
        """打印当前链表所有节点数据."""
        pos = self.__head
        if pos is None:
            print("空")
            return
        while pos.next_node is not None:
            print(pos.data+"---->",end="")
            pos = pos.next_node
        print(pos.data)
    def __reversed_with_two_node(self,pre,node):
        """翻转相邻两个节点.
        参数:
            pre:前一个节点
            node:当前节点
        返回:
            (pre,node):下一个相邻节点的元组
        """
        tmp  = node.next_node
        node.next_node = pre
        pre = node
        node = tmp
        return pre,node
    def reversed_self(self):
        """翻转链表自身."""
        if self.__head is None or self.__head.next_node is None:
            return
        pre  = self.__head
        node = self.__head.next_node
        while node is not None:
            pre,node = self.__reversed_with_two_node(pre,node)
        self.__head.next = None 
        self.__head = pre
    def has_ring(self):
        """检查链表中是否有环.
        主体思想：
            设置快、慢两种指针，快指针每次跨两步，慢指针每次跨一步，如果快指针没有与慢指针相遇而是顺利到达链表尾部
            说明没有环；否则，存在环
        返回:
            True:有环
            False:没有环
        """
        fast = self.__head
        slow = self.__head
        while (fast.next_node is not None) and (fast is not None):
            fast = fast.next_node
            slow = slow.next_node
            if fast ==slow:
                return True
        return False
def reverse(head):
    reverse_head =None 
    while head:
        next = head.__next
        head.__next = reverse_head
        reverse_head = head
        head = next
    return reverse_head
def is_palindrome(l):
    l.print_all()
    slow = l.__head
    fast = l.__head
    position = 0
    while fast and fast._next:
        slow = slow._next
        fast = fast._next._next
        position += 1

    reverse_node = reverse(slow)
    head_node = l.__head
    is_palin = True
    while (head_node and reverse_node):
        if (head_node.data == reverse_node.data):
            head_node = head_node._next
            reverse_node = reverse_node._next
        else:
            is_palin = False
            break

    return is_palin

if __name__ == '__main__':
    # the result should be False, True, True, True, True
    test_str_arr = ['ab', 'aa', 'aba', 'abba', 'abcba']
    for str in test_str_arr:
        l = SinglyLinkedList()
        for i in str:
            l.insert_value_to_head(i)

        print(is_palindrome(l))