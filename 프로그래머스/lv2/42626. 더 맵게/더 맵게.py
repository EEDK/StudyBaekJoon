import heapq

def solution(scoville, K):
    heap = []
    for s in scoville:
        heapq.heappush(heap, s)

    mix_count = 0
    while len(heap) > 1:
        a = heapq.heappop(heap)
        if a >= K:
            break
        b = heapq.heappop(heap)
        heapq.heappush(heap, a + b * 2)
        mix_count += 1

    if heap[0] < K:
        return -1
    else:
        return mix_count
