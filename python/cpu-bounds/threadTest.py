import threading
import time


# elapsed time: 7.63382...
def fibonacci(n):
    if n <= 1:
        return n
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)


def thread_task(n):
    print(f"Thread starting for {n}")
    result = fibonacci(n)
    print(f"Fibonacci({n}) = {result}")


if __name__ == "__main__":
    n = 35  # A large number to make the task CPU-bound
    threads = []

    start_time = time.time()

    for i in range(4):
        # Python thread cannot execute bytecode in parallel
        thread = threading.Thread(target=thread_task, args=(n,))
        threads.append(thread)
        thread.start()

    for thread in threads:
        thread.join()

    end_time = time.time()
    print(f"Threading took {end_time - start_time} seconds")
