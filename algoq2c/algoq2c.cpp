#include "algoq2c.hpp"

int main() {
    // Generate vector of size 100
    std::vector<int> int_arr(100);

    // Random number generator (between 1 and 100)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

    // Fill the vector with random values
    std::generate(int_arr.begin(), int_arr.end(), [&]() { return dist(gen); });
    
    // Find the maximum element in the array
    // Output the maximum element (our algo)
    int maxElement{ findMaxInThreeParts(int_arr, 0, int_arr.size() - 1) };
    std::cout << "The maximum element using our function is: " << maxElement << std::endl;

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
    
    return 0;
}