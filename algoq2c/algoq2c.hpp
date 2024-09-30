#pragma once
#include <iostream>
#include <vector>
#include <algorithm> 
#include <random>
#include <chrono>

int get_max_three_ints(int a, int b, int c) {
    if (a > b) {
        if (a > c) {
            return a;
        }
        else {
            return c;
        }
    }

    else if (b > c) {
        return b;
    }

    return c;
}

int findMaxInThreeParts(std::vector<int> const& arr, int start, int end) {
    // Base case
    if (start == end - 1) {
        return arr[start];
    }

    // Number of elements in the block
    int n{ end - start };
    
    // Divide the array into three parts
    int mid1{ start + n / 3 };
    int mid2{ start + 2 * (n / 3) };

    // Recursively call to find the max in each part
    int max1{ findMaxInThreeParts(arr, start, mid1) };
    int max2{ findMaxInThreeParts(arr, mid1, mid2) };
    int max3{ findMaxInThreeParts(arr, mid2, end) };

    // Get the max value of the three parts
    return get_max_three_ints(max1, max2, max3);
}

void printChrono(std::chrono::steady_clock::time_point start, std::chrono::steady_clock::time_point stop, std::string algoType) {
    // Calculate the duration (microseconds)
    auto duration{ std::chrono::duration_cast<std::chrono::microseconds>(stop - start) };

    // Display the runtime
    std::cout << "Execution time for " << algoType << ": " << duration.count() << " microseconds" << std::endl;
}

int findMaxQuadratic(const std::vector<int>& part1, const std::vector<int>& part2, const std::vector<int>& part3) {
    int maxElement = part1[0];
    
    // Compare every element of part1 with part2 and part3
    for (int i{}; i < static_cast<int>(part1.size()); ++i) {
        for (int j{}; j < static_cast<int>(part2.size()); ++j) {
            for (int k{}; k < static_cast<int>(part3.size()); ++k) {
                maxElement = std::max({maxElement, part1[i], part2[j], part3[k]});
            }
        }
    }
    
    return maxElement;
}