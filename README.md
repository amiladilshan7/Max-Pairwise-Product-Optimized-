# Max-Pairwise-Product-Optimized-
Solution code for Programming Assignment 1: Maximum Pairwise Product in cpp, 

This repository contains a corrected and optimized implementation of the Max Pairwise Product algorithm. The code computes the maximum product of two distinct elements in an array, addressing inefficiencies and critical issues from the original version.

## Problem Statement
Given an array of integers, find the maximum product of two distinct elements.
The original implementation had issues with efficiency and overflow, which this optimized version resolves.

---

## ⚠ Errors in the Original Code

### 1. Integer Overflow
- **Problem**:  
  The product of two large numbers could exceed the maximum value of a 32-bit integer (\(2,147,483,647\)), causing incorrect results.  
  - **Example Input**: `2\n100000 90000`
  - **Original Output**: `410065408` (Incorrect due to overflow)
  - **Expected Output**: `9000000000`

### 2. Inefficiency
- **Problem**:  
  The original algorithm used nested loops, resulting in \(O(n^2)\) time complexity.  
  - **Impact**: Computation was slow for large arrays.

### 3. Lack of Error Handling
- **Problem**:  
  The code did not handle edge cases where the input array had fewer than two elements.  
  - **Impact**: This could lead to crashes or undefined behavior.

---

##  Fixes and Optimizations

### 1. Long Long for Overflow Prevention
- Updated variable types (`max1`, `max2`, and the return value) to `long long` to handle large products without overflow.

### 2. Optimized Algorithm
- Replaced the \(O(n^2)\) nested loop with an \(O(n)\) single-loop solution:
  - **Logic**:
    - Traverse the array to find the two largest numbers.
    - Compute their product directly.

### 3. Error Handling
- Added checks to ensure the input array contains at least two elements.
- Graceful error messages are displayed if the input is invalid.

---

##  Improved Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    int n = numbers.size();

    // Handle edge case
    if (n < 2) {
        std::cerr << "Error: At least two numbers are required.\n";
        return -1; // Error code
    }

    // Use long long to handle large products
    long long max1 = std::max(numbers[0], numbers[1]);
    long long max2 = std::min(numbers[0], numbers[1]);

    for (int i = 2; i < n; ++i) {
        if (numbers[i] > max1) {
            max2 = max1;
            max1 = numbers[i];
        } else if (numbers[i] > max2) {
            max2 = numbers[i];
        }
    }

    return max1 * max2;
}

int main() {
    int n;
    std::cin >> n;
    if (n < 2) {
        std::cerr << "Error: At least two numbers are required.\n";
        return 1; // Error code
    }

    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
```

---

## 🔄 Comparison: Original vs Fixed Code

| **Aspect**          | **Original Code**                  | **Fixed Code**                      |
|----------------------|-------------------------------------|--------------------------------------|
| **Time Complexity**  | \(O(n^2)\)                         | \(O(n)\)                            |
| **Integer Overflow** | Prone to overflow for large numbers| Avoided by using `long long`        |
| **Error Handling**   | None                               | Validates input size                |
| **Readability**      | Nested loops, harder to follow     | Single loop, clean logic            |

---

