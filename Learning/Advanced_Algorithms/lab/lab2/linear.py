def swap(a: list, i: int, j: int):
    if i == j:
        return
    t = a[i]
    a[i] = a[j]
    a[j] = t


def get_mid(a: list, l: int, r: int) -> int:
    if l == r:
        return l
    i = l
    n = 0
    for i in range(l, r-4, 5):
        a[i: i + 5] = sorted(a[i: i + 5])
        n = i - l
        swap(a, l + n // 5, i + 2)
    if r - 4 > l:
        i += 5
        n = i - l
    num = r - i
    if num > 0:
        a[i:i+num] = sorted(a[i:i+num])
        n = i - l
        swap(a, l + n // 5, i + num // 2)
    n //= 5
    if n == l:
        return l
    return get_mid(a, l, l + n)


def partition(a: list, l: int, r: int, p: int) -> int:
    swap(a, p, l)
    i = l
    j = r - 1
    pivot = a[l]
    while i < j:
        while a[j] >= pivot and i < j:
            j -= 1
        a[i] = a[j]
        while a[i] <= pivot and i < j:
            i += 1
        a[j] = a[i]
    a[i] = pivot
    return i


def select(a: list, l: int, r: int, k: int):
    p = get_mid(a, l, r)
    i = partition(a, l, r, p)
    m = i - l + 1
    if m == k:
        return a[i]
    elif m > k:
        return select(a, l, i, k)
    else:
        return select(a, i + 1, r, k - m)


def liner_select(datasets: dict, k: int) -> dict:
    result = {}
    for key in datasets.keys():
        data = datasets[key]
        result[key] = select(data, 0, len(data), k)
    return result
