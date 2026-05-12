import random
import time

def brute_force(password):
    start_time = time.perf_counter()

    for i in range(10000):
        guess = str(i).zfill(4)
        if guess == password:
            attempts = i + 1
            break

    end_time = time.perf_counter()
    return end_time - start_time, attempts


# Example: 1000 runs
password = str(random.randint(0, 9999)).zfill(4)
print("Password used:", password)
print()

times = []

for run in range(1, 2001):
    t, attempts = brute_force(password)
    times.append(t)

    print(f"Run {run}: time = {t:.6f}s | attempts = {attempts}")

average_time = sum(times) / len(times)

print("\nAverage time:", average_time)