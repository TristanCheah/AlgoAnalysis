#include "algoq2c.hpp"

int main() {
    // findMaxInThreeParts
    // Generate vector with 100 ints
    std::vector<int> int_arr {
        35, 69, 20, 83, 12, 72, 66, 53, 66, 42, 
        27, 97, 18, 91, 24, 42, 11, 66, 59, 79, 
        82, 54, 25, 21, 97, 93, 42, 53, 5, 52, 
        42, 19, 66, 25, 33, 57, 45, 22, 33, 82, 
        92, 68, 52, 73, 82, 53, 73, 7, 81, 63, 
        35, 64, 84, 18, 73, 20, 52, 19, 21, 87, 
        70, 93, 42, 17, 83, 35, 98, 85, 80, 83, 
        51, 41, 54, 47, 30, 1, 97, 86, 42, 3, 
        32, 48, 71, 50, 38, 10, 84, 51, 36, 9, 
        17, 49, 85, 27, 49, 85, 99, 77, 63, 86
    };
    
    // Find the maximum element in the array
    // Output the maximum element (our algo)
    std::chrono::steady_clock::time_point start{ std::chrono::steady_clock::now() };

    int maxElement{ findMaxInThreeParts(int_arr, 0, int_arr.size() - 1) };
    std::cout << "The maximum element using our function is: " << maxElement << std::endl;
    std::chrono::steady_clock::time_point stop{ std::chrono::steady_clock::now() };

    // Display runtime
    printChrono(start, stop, "findMaxInThreeParts");
    std::cout << std::endl;
    
    // Output the maximum element (std::max)
    int stdMaxElement{ *std::max_element(int_arr.begin(), int_arr.end()) };
    std::cout << "The maximum element using std::max is: " << stdMaxElement << std::endl;

    // Output equivalence
    if (maxElement == stdMaxElement) {
        std::cout << "The two maximum elements found are equivalent." << std::endl;
    }
    else {
        std::cout << "The two maximum elements found are not equivalent." << std::endl;
    }

    std::cout << std::endl;

    // findMaxQuadratic
    std::vector<int> part1 { 
        35, 69, 20, 83, 12, 72, 66, 53, 66, 42, 27, 
        97, 18, 91, 24, 42, 11, 66, 59, 79, 82, 54, 
        25, 21, 97, 93, 42, 53, 5, 52, 42, 19, 66 
    };
    std::vector<int> part2 { 
        25, 33, 57, 45, 22, 33, 82, 92, 68, 52, 73, 
        82, 53, 73, 7, 81, 63, 35, 64, 84, 18, 73, 
        20, 52, 19, 21, 87, 70, 93, 42, 17, 83, 35 
    };
    std::vector<int> part3 { 
        98, 85, 80, 83, 51, 41, 54, 47, 30, 1, 97, 
        86, 42, 3, 32, 48, 71, 50, 38, 10, 84, 51, 
        36, 9, 17, 49, 85, 27, 49, 85, 99, 77, 63 
    };

    start = std::chrono::steady_clock::now();

    // Find max value (quadratic)
    int maxValue{ findMaxQuadratic(part1, part2, part3) };
    std::cout << "Maximum value found (quadratic): " << maxValue << std::endl;

    stop = std::chrono::steady_clock::now();

    // Display runtime
    printChrono(start, stop, "findMaxQuadratic");
    std::cout << std::endl;

    return 0;
}