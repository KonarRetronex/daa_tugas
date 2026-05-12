import random
import time
import threading

# Generate shuffled list
arr = list(range(1, 1001))
random.shuffle(arr)

# -----------------------------
# BRUTE FORCE (MULTITHREADED)
# -----------------------------
def brute_worker(sub_arr, result, index):
    local_min = sub_arr[0]
    local_max = sub_arr[0]

    for num in sub_arr:
        if num < local_min:
            local_min = num
        if num > local_max:
            local_max = num

    result[index] = (local_min, local_max)


def brute_force_mt(arr, num_threads=4):
    threads = []
    results = [None] * num_threads
    chunk_size = len(arr) // num_threads

    for i in range(num_threads):
        start = i * chunk_size
        end = len(arr) if i == num_threads - 1 else (i + 1) * chunk_size
        t = threading.Thread(target=brute_worker, args=(arr[start:end], results, i))
        threads.append(t)
        t.start()

    for t in threads:
        t.join()

    # Combine results
    final_min = min(r[0] for r in results)
    final_max = max(r[1] for r in results)

    return final_min, final_max


# -----------------------------
# DIVIDE & CONQUER (RECURSIVE)
# -----------------------------
def divide_conquer(arr):
    if len(arr) == 1:
        return arr[0], arr[0]
    elif len(arr) == 2:
        return (min(arr), max(arr))

    mid = len(arr) // 2
    left_min, left_max = divide_conquer(arr[:mid])
    right_min, right_max = divide_conquer(arr[mid:])

    return min(left_min, right_min), max(left_max, right_max)


def dc_worker(sub_arr, result, index):
    result[index] = divide_conquer(sub_arr)


def divide_conquer_mt(arr, num_threads=4):
    threads = []
    results = [None] * num_threads
    chunk_size = len(arr) // num_threads

    for i in range(num_threads):
        start = i * chunk_size
        end = len(arr) if i == num_threads - 1 else (i + 1) * chunk_size
        t = threading.Thread(target=dc_worker, args=(arr[start:end], results, i))
        threads.append(t)
        t.start()

    for t in threads:
        t.join()

    final_min = min(r[0] for r in results)
    final_max = max(r[1] for r in results)

    return final_min, final_max


# -----------------------------
# MEASURE TIME
# -----------------------------
start = time.time()
bf_min, bf_max = brute_force_mt(arr)
bf_time = time.time() - start

start = time.time()
dc_min, dc_max = divide_conquer_mt(arr)
dc_time = time.time() - start


# -----------------------------
# OUTPUT
# -----------------------------
print("Brute Force Result:", bf_min, bf_max)
print("Brute Force Time:", bf_time)

print("Divide & Conquer Result:", dc_min, dc_max)
print("Divide & Conquer Time:", dc_time)