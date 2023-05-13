def compress(arr, x, y, size, result):
    if check_same(arr, x, y, size):
        result[arr[x][y]] += 1
    else:
        new_size = size // 2
        compress(arr, x, y, new_size, result)
        compress(arr, x, y + new_size, new_size, result)
        compress(arr, x + new_size, y, new_size, result)
        compress(arr, x + new_size, y + new_size, new_size, result)

def check_same(arr, x, y, size):
    target = arr[x][y]
    for i in range(x, x + size):
        for j in range(y, y + size):
            if arr[i][j] != target:
                return False
    return True

def solution(arr):
    n = len(arr)
    result = [0, 0] 
    
    compress(arr, 0, 0, n, result)
    
    return result
