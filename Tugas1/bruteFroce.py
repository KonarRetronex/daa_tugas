import random
import time

def brute_force(password):
    start_time = time.perf_counter()

    for i in range(10000):
        guess = str(i).zfill(4)
        if guess == password:
            break

    end_time = time.perf_counter()
    return end_time - start_time


# =========================
# EXPERIMENT 1 (1000 times)
# =========================
password1 = str(random.randint(0, 9999)).zfill(4)
print("Experiment 1 Password:", password1)

times1 = []

for _ in range(1000):
    times1.append(brute_force(password1))

avg1 = sum(times1) / len(times1)
print("Experiment 1 Average:", avg1)
print()


# =========================
# EXPERIMENT 2 (2000 times)
# =========================
password2 = str(random.randint(0, 9999)).zfill(4)
print("Experiment 2 Password:", password2)

times2 = []

for _ in range(2000):
    times2.append(brute_force(password2))

avg2 = sum(times2) / len(times2)
print("Experiment 2 Average:", avg2)
print()


# =========================
# EXPERIMENT 3 (3000 times)
# =========================
password3 = str(random.randint(0, 9999)).zfill(4)
print("Experiment 3 Password:", password3)

times3 = []

for _ in range(3000):
    times3.append(brute_force(password3))

avg3 = sum(times3) / len(times3)
print("Experiment 3 Average:", avg3)