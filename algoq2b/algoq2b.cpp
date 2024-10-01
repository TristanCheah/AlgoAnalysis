#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>

//-------------------------Constant-------------------------
void getSpecifiedElement(std::vector<int> const& arr, int const& index) {
    if (static_cast<int>(arr.size()) > index) {
        std::cout << "Accessing element at index " << index << ": " << arr[index] << std::endl;
    }
}

//-------------------------Logarithmic-------------------------
int binarySearch(std::vector<int>& arr, int target) {
    int low{}, high{ static_cast<int>(arr.size()) - 1 };

    while (low <= high) {
        int mid{ (low + high) / 2 };

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

//-------------------------Linear-------------------------
int linearTimeSum(std::vector<int> const& arr) {
    int sum{};

    for (int i{}; i < static_cast<int>(arr.size()); ++i)
    {
        sum += arr[i];
    }

    return sum;
}

//-------------------------Linearithmic-------------------------
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1{ mid - left + 1 };
    int n2{ right - mid };
    std::vector<int> L(n1), R(n2);

    for (int i{}; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i{}; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i{}, j{}, k{ left };

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) 
        arr[k] = L[i++];
            else arr[k] = R[j++];
        k++;
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) { 
        arr[k++] = R[j++];
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

//-------------------------Quadratic-------------------------
void bubbleSort(std::vector<int>& arr, int n) {
    for (int i{}; i < n - 1; ++i) {
        for (int j{}; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

//-------------------------Exponential-------------------------
int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

//-------------------------Factorial-------------------------
void printPermutations(std::vector<int> arr) {
    int count{};
    std::sort(arr.begin(), arr.end());
    do {
        ++count;
    }
    while (std::next_permutation(arr.begin(), arr.end()));

    std::cout << "Number of permutations: " << count << std::endl;
}

void printChrono(std::chrono::steady_clock::time_point start, std::chrono::steady_clock::time_point stop, std::string algoType) {
    // Calculate the duration (microseconds)
    auto duration{ std::chrono::duration_cast<std::chrono::microseconds>(stop - start) };

    // Display the runtime
    std::cout << "Execution time for " << algoType << ": " << duration.count() << " microseconds" << std::endl;
}

int main() {
    // Initialize vector of ints
    std::vector<int> int_arr{25, 5, 2, 132, 56, 238, 22, 51567, 23, 98, 2};

    // Large vector of ints
    std::vector<int> large_int_arr {
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

    // Fix chrono
    std::chrono::steady_clock::time_point start{ std::chrono::steady_clock::now() };
    std::cout << "Initializing (to fix <chrono>)..." << std::endl;
    std::chrono::steady_clock::time_point stop{ std::chrono::steady_clock::now() };
    printChrono(start, stop, "Printing");
    std::cout << std::endl;

    //-------------------------Constant (large vector)-------------------------
    // Record start time
    start = std::chrono::steady_clock::now();

    // Get fourth element of int_arr
    getSpecifiedElement(large_int_arr, 79);

    // Record end time
    stop = std::chrono::steady_clock::now();

    // Display runtime
    printChrono(start, stop, "Constant (size = 100)");
    std::cout << std::endl;

    //-------------------------Constant (small vector)-------------------------
    // Record start time
    start = std::chrono::steady_clock::now();

    // Get fourth element of int_arr
    getSpecifiedElement(int_arr, 4);

    // Record end time
    stop = std::chrono::steady_clock::now();

    // Display runtime
    printChrono(start, stop, "Constant (size = 11)");
    std::cout << std::endl;    

    //-------------------------Logarithmic-------------------------
    std::vector<int> int_arr_binary = int_arr;
    std::sort(int_arr_binary.begin(), int_arr_binary.end());
    for (int i{}; i < static_cast<int>(int_arr_binary.size()); ++i) {
        std::cout << int_arr_binary[i] << " ";
    }
    std::cout << std::endl;

    // Record start time
    start = std::chrono::steady_clock::now();

    int index{ binarySearch(int_arr_binary, 22) };
    std::cout << "Element 22 found at index: " << index << std::endl;

    // Record end time
    stop = std::chrono::steady_clock::now();

    // Display runtime
    printChrono(start, stop, "Logarithmic");
    std::cout << std::endl;

    //-------------------------Linear-------------------------
    // Record start time
    start = std::chrono::steady_clock::now();

    std::cout << "Sum is: " << linearTimeSum(int_arr) << std::endl;
    
    // Record end time
    stop = std::chrono::steady_clock::now();

    // Display runtime
    printChrono(start, stop, "Linear");
    std::cout << std::endl;

    //-------------------------Linearithmic-------------------------
    std::vector<int> int_arr_mergesort = int_arr;

    // Record start time
    start = std::chrono::steady_clock::now();
    
    mergeSort(int_arr_mergesort, 0, int_arr_mergesort.size() - 1);
    std::cout << "Sorted array: ";
    for (int i{}; i < static_cast<int>(int_arr_mergesort.size()); i++) {
        std::cout << int_arr_mergesort[i] << " ";
    }
    std::cout << std::endl;

    // Record end time
    stop = std::chrono::steady_clock::now();

    // Display runtime
    printChrono(start, stop, "Linearithmic");
    std::cout << std::endl;

    //-------------------------Quadratic-------------------------
    std::vector<int> int_arr_bubblesort = int_arr;

    // Record start time
    start = std::chrono::steady_clock::now();

    bubbleSort(int_arr_bubblesort, int_arr_bubblesort.size());

    std::cout << "Sorted array: ";
    for (int i{}; i < static_cast<int>(int_arr_bubblesort.size()); i++) {
        std::cout << int_arr_bubblesort[i] << " ";
    }
    std::cout << std::endl;

    // Record end time
    stop = std::chrono::steady_clock::now();

    // Display runtime
    printChrono(start, stop, "Quadratic");
    std::cout << std::endl;

    //-------------------------Exponential-------------------------
    // Record start time
    start = std::chrono::steady_clock::now();

    int n{ 10 };
    std::cout << "Fibonacci of " << n << " is: " << fib(n) << std::endl;

    // Record end time
    stop = std::chrono::steady_clock::now();

    // Display runtime
    printChrono(start, stop, "Exponential");
    std::cout << std::endl;

    //-------------------------Factorial-------------------------
    // Record start time
    start = std::chrono::steady_clock::now();

    printPermutations(int_arr);

    // Record end time
    stop = std::chrono::steady_clock::now();

    // Display runtime
    printChrono(start, stop, "Factorial");
    std::cout << std::endl;

    return 0;
}