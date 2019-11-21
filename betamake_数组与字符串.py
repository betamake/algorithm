"""
判断字符串是否重复，使用基本的数据结构
"""
def is_repeat(string):
    """
    funtion:比较简单，时间复杂度为O（n),从第一个元素开始，与后面的元素对比。有相等的，返回False 没有返回True
    biref:判断是否重复
    参数：string，字符串
    """
    lengh = len(string)
    cur = 0 
    while cur != lengh
    if string[cur] in string[cur+1]:
        return False
    i+=1
    return True    
"""
判断是否互为字符重排
解析：1，这个问题假设字符串a与b,也就是说。a中的字符全排列后，是否存在b的可能。
      2，另外一种想法是a与b的字符是否全部相等
      注意点：首先问清楚是否区分大小写
"""
def is_equal(string_a,string_b):
    a_length = len(string_a)
    b_length = len(string_b)
    if a_length!=b_length:
        return False
    step = 1
    for i in range(a_length):
        if string_a[i] in string_b:
            step +=1
    if step == a_length:
        return True
    return False