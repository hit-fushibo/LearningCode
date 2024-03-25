def merge(list1,list2):
    l,r=0,0
    sorted_list=[]
    while l<len(list1) and r<len(list2):
        if list1[l]<=list2[r]:
            sorted_list.append(list1[l])
            l+=1
        else:
            sorted_list.append(list2[r])
            r+=1
            
    sorted_list+=list1[l:]
    sorted_list+=list2[r:]
    return sorted_list

def merge_sort(list):
    if len(list)<=1:
        return list
    
    mid=len(list)//2
    
    list_l=merge_sort(list[:mid])
    list_r=merge_sort(list[mid:])
    
    return merge(list_l,list_r)