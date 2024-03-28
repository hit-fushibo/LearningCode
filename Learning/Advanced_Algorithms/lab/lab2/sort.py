def merge(l1: list, l2: list) -> list:
    l, r = 0, 0
    sorted_list = []
    while l < len(l1) and r < len(l2):
        if l1[l] <= l2[r]:
            sorted_list.append(l1[l])
            l += 1
        else:
            sorted_list.append(l2[r])
            r += 1

    sorted_list += l1[l:]
    sorted_list += l2[r:]
    return sorted_list


def merge_sort(l: list):
    if len(l) <= 1:
        return l

    mid = len(l)//2

    list_l = merge_sort(l[:mid])
    list_r = merge_sort(l[mid:])

    return merge(list_l, list_r)
