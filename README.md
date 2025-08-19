This project contains learning modern C++.
Useful for interviews for modern C++11 to C++17
The main.cpp file in this repository is a comprehensive demonstration of C++ Standard Template Library (STL) features and modern C++ concepts. Here’s a breakdown of what the code covers:

1. STL Containers
Vector: Creation, manipulation (push_back, pop_back, insert, erase, clear), iteration, capacity, 2D vectors (matrices), operations like sum, transpose, boundary extraction, etc.
Deque: Demonstrates push_front, push_back, pop_front, and iteration.
List and Forward List: Shows front/back operations, insert_after, remove, unique, merge, and iteration.
Array: Usage of std::array, fill, accumulate, and counting elements.
Set and Multiset: Insertion, find, lower_bound, and iteration. Shows uniqueness in set and how multiset would allow duplicates.
Map and Multimap: Key-value operations, insert, find, erase, iteration, and count. Uses structured bindings and demonstrates lower_bound, upper_bound, and equal_range.

2. Utilities and C++ Features
std::pair and std::tuple: Shows creation, comparison, automatic type deduction, tuple_cat, tie for unpacking, and element access.
std::optional: Safe return for functions when a value might not exist.
std::variant and std::any: For type-safe unions and storing any type.
Functors (function objects): Custom functor classes (Counter, square1) and use of std::for_each.
std::function and std::bind: Assigning and binding functions.

3. Algorithms
Sorting: Sort in ascending/descending order.
Accumulate, Count, Remove_if, Reverse: Demonstrates their use on containers.

4. Advanced Data Structures
3D Heterogeneous Data: Shows nested maps for district and school data, with file writing to demonstrate file I/O.
Custom Typedefs: For readability and complex structures.

5. File Handling
Writes school data to a file “details.txt”, checks for file errors.

6. Smart Pointers
unique_ptr, shared_ptr: Shows their creation, ownership semantics, and differences.

7. Multithreading & Concurrency
std::thread, std::async, std::future: Demonstrates launching tasks, waiting for results, detaching threads, using join to synchronize, and mutex for thread safety.
Mutex Usage: Guards shared resources in tasks and print functions.

8. Other Features
Namespace: Custom namespace zubair for demonstration.
Printing Functions: For vectors, deques, and safe printing with mutex.
Mathematical Operations: lcm, gcd, pow, bit manipulation.
Type Conversions: int to string, char operations.
Boundary Element Extraction: From matrices.

9. Example Output Demonstrations
Most operations print results to console for easy understanding.
In summary, this file is an extensive tutorial-style codebase that demonstrates nearly every major feature of C++ STL, plus modern C++ concepts (C++11 through C++17) like smart pointers, concurrency, and utilities. Each section is structured to show how to use C++ data structures and algorithms for practical scenarios, such as matrix manipulations, file operations, functors, and thread safety.