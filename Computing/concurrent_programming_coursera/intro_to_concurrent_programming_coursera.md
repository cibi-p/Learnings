# Intro to Concurrent programming from coursera
link: https://www.coursera.org/learn/introduction-to-concurrent-programming?specialization=gpu-programming

### Real World Concurrent Programming
#### Understanding Multi-Processing and Threads
Multi-processing and threading are essential for maximizing the use of modern computer processors.
Threads are independent sequences of executed programming steps, allowing for efficient data processing.

#### Role of the CPU Scheduler
The CPU scheduler manages the execution of threads across multiple cores, optimizing performance by minimizing idle time.
Memory caching is crucial for reducing delays in data retrieval, enhancing thread activity.

#### Memory Hierarchy and Caching
Memory caches are structured hierarchically, with closer memory being more efficient.
Caches facilitate data sharing between cores and limit the need for accessing slower memory sources.


### Concurrent Programming Pitfalls
#### Race Conditions
Occur when threads execute in an unintended sequence, leading to incorrect final values despite valid individual operations.
Minimizing shared variables or ensuring atomic access can help mitigate this issue.

#### Deadlock and Livelock
Deadlock happens when threads wait indefinitely for resources held by each other, preventing any progress.
Livelock is similar but involves threads actively changing states without making progress, often due to improper loop conditions.

#### Resource Contention and Utilization
Resource contention arises when multiple threads access shared resources, potentially leading to conflicts and inefficiencies.
Over or underutilization of threads can lead to performance issues, necessitating careful scaling based on workload and CPU usage.


### Concurrent Programming Problems and Algorithms

#### Dining Philosophers Problem
Illustrates resource contention and deadlock, where philosophers need two forks to eat but may end up in a situation where they all hold one fork and cannot eat.
Solutions may involve communication between philosophers or a central authority to manage fork access.

#### Producer-Consumer Problem
Describes a common pattern in message queues where producers add data and consumers retrieve it, with strategies for handling excess data.
Highlights potential race conditions if data structures allow overriding values or if producer and consumer indices are misaligned.

#### Sleeping Barber Problem
Explains the optimization of barber work with a finite waiting room, where issues like livelock or underutilization can occur.
Suggests solutions such as adjusting the number of barbers based on customer demand to improve efficiency.

### Concurrent Programming Patterns
#### Divide and Conquer
This pattern involves breaking down data into smaller parts to solve problems more efficiently, commonly used in searching and sorting algorithms.
While effective, it may not always be the best choice, especially in cases where recursion is inefficient or when managing complex states.

#### Map-Reduce
A subset of divide and conquer, this pattern processes individual data points through mapping and reducing operations, allowing for scalable solutions.
Each mapper processes data independently, and the reducer consolidates results, making it suitable for large datasets.

#### Repository Pattern
Maintains state across multiple threads or processes.
Allows independent processes to request and update data while ensuring data consistency and atomicity.

#### Pipelines and Workflows
Pipelines are linear sequences where each step takes input from the previous step and outputs to the next.
Workflows can be more complex, allowing for cycles and multiple paths for data flow, often employing fan-out and fan-in patterns.

#### Recursion
A method where a function calls itself to solve smaller instances of the same problem.
While powerful, it requires careful management of state and is not always efficient for large datasets or in parallel processing environments.

### Serial vs Parallel Programming
#### Serial vs. Parallel Code
Serial code involves a straightforward linear search algorithm that iterates through all values in a dataset to find a target value, returning the index or -1 if not found.
Parallel code divides the dataset into subsets for multiple threads to search simultaneously, improving efficiency but requiring careful thread management.

#### Search Algorithms
Linear search is simple but inefficient for large datasets, while more advanced algorithms like binary search offer logarithmic time complexity but require sorted data.
Parallel searches can be more efficient with many threads, but they can also introduce complexity and potential issues with thread management.

#### Flynn's Taxonomy
ref. Link: https://www.geeksforgeeks.org/computer-architecture-flynns-taxonomy/

Flynn's Taxonomy is a classification system that helps us understand different types of computer architectures based on how they handle instructions and data. It categorizes systems into four main types, which can be thought of as different approaches to processing information. The four categories are:

**Single Instruction Single Data (SISD):** This is the simplest form, where a single processor executes one instruction at a time on a single piece of data. Imagine a chef preparing a meal by following one recipe step at a time. This method is straightforward but can be slow if there are many tasks to complete.

**Single Instruction Multiple Data (SIMD):** In this category, a single instruction operates on multiple pieces of data simultaneously. Think of it like a chef who can chop several vegetables at once using a special tool. This approach is efficient for tasks that require the same operation on large datasets, such as image processing.

**Multiple Instruction Single Data (MISD):** Here, multiple instructions are executed on a single piece of data. This is less common but can be likened to a team of chefs each preparing a different aspect of the same dish, ensuring that every part is ready at the same time. This can be useful in specific applications, like fault tolerance in systems.

**Multiple Instruction Multiple Data (MIMD):** This is the most complex category, where multiple processors execute different instructions on different pieces of data. Imagine a bustling kitchen with several chefs, each working on their own unique dish. This allows for high flexibility and efficiency, especially in complex tasks like running simulations or processing large datasets.

## Parallel Programming Python
### Syntax and patterns
Note: commonly used 3 methods
Example: [code link](./code/m3_python_parallel_programming/)
#### Threading

Threading allows you to run multiple threads (smaller units of a process) at the same time. This is useful for tasks that are I/O-bound, like reading files or making network requests.

Syntax:
```py
import threading

def my_function():
    print("Hello from the thread!")
# Create a thread
my_thread = threading.Thread(target=my_function)

# Start the thread
my_thread.start()

# Wait for the thread to finish
my_thread.join()
```

Example:
In this example, we define a function my_function that simply prints a message. We create a thread that runs this function, start the thread, and then wait for it to finish using join().

2. Asyncio

Asyncio is used for writing asynchronous code, which allows you to handle tasks that may take time (like waiting for a response from a server) without blocking the entire program.

Syntax:

```py
import asyncio

async def my_async_function():
    print("Start async function")
    await asyncio.sleep(1)  # Simulates a delay
    print("End async function")

# Run the async function
asyncio.run(my_async_function())
```

Example:
Here, my_async_function is defined as an asynchronous function using the async keyword. Inside it, we use await to pause the function for 1 second without blocking other tasks. The asyncio.run() function is used to execute the async function.

3. Multiprocessing

Multiprocessing allows you to run multiple processes, which can be useful for CPU-bound tasks that require heavy computation. Each process runs in its own memory space.

Syntax:
```py
from multiprocessing import Process

def my_process_function():
    print("Hello from the process!")

# Create a process
my_process = Process(target=my_process_function)

# Start the process
my_process.start()

# Wait for the process to finish
my_process.join()
```
Example:
In this example, we define a function my_process_function that prints a message. We create a process that runs this function, start the process, and then wait for it to finish using join().

Summary

Threading is great for I/O-bound tasks and allows multiple threads to run concurrently.
Asyncio is perfect for handling asynchronous tasks without blocking the program.
Multiprocessing is ideal for CPU-bound tasks, allowing separate processes to run independently.
If you have any other concepts from the content that you would like me to explain, feel free to ask!


