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
