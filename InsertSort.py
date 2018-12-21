# author:betamake
# chapter:2-insert_sort
def Insert_sort(list): 
    n = len(list)
    for j in range(1,n):
        key = list[j]
        i=j-1
        while i>=0 and list[i]>key:
            list[i+1]=list[i]
            i=i-1
        list[i+1]=key
if __name__ == "__main__":
    list = [5,2,4,6,1,3]
    print("原列表为：%s" % list)
    Insert_sort(list)
    print("新列表为：%s" % list)