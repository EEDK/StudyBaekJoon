import sys


def merge_sort(arr):
    if len(arr) <= 1:
        return arr, 0

    mid = len(arr) // 2
    left, lcnt = merge_sort(arr[:mid])
    right, rcnt = merge_sort(arr[mid:])
    merged, mcnt = merge(left, right)

    return merged, lcnt + rcnt + mcnt


def merge(left, right):
    merged = []
    lidx, ridx = 0, 0
    cnt = 0

    while lidx < len(left) and ridx < len(right):
        if left[lidx] <= right[ridx]:
            merged.append(left[lidx])
            lidx += 1
        else:
            merged.append(right[ridx])
            ridx += 1
            cnt += len(left) - lidx

    merged += left[lidx:]
    merged += right[ridx:]

    return merged, cnt


n = int(input())
arr = list(map(int, input().split()))
_, answer = merge_sort(arr)
print(answer)
