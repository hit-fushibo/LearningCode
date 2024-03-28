from sort import merge_sort


def sort_select(data: dict, k: int) -> dict:
    result = {}
    for key in data.keys():
        result[key] = merge_sort(data[key])[k-1]

    return result
