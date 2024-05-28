import multiprocessing
import time


# elapsed time: 2.15598...
def fibonacci(n):
    if n <= 1:
        return n
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)


def process_task(n):
    print(f"Process starting for {n}")
    result = fibonacci(n)
    print(f"Fibonacci({n}) = {result}")


if __name__ == "__main__":
    n = 35  # A large number to make the task CPU-bound
    processes = []

    start_time = time.time()

    for i in range(4):
        process = multiprocessing.Process(target=process_task, args=(n,))
        processes.append(process)
        process.start()

    for process in processes:
        process.join()

    end_time = time.time()
    print(f"Multiprocessing took {end_time - start_time} seconds")
