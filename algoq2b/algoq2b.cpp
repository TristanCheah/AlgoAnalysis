#include <iostream>
#include <vector>

void constant_function() {
    std::vector<int> int_arr{25, 5, 2, 132, 56, 238, 22, 51567, 23, 98, 2};
    std::cout << "Accessing fourth element: " << int_arr[3] << std::endl << std::endl;
}

void logarithmic_function() {

}

void linear_function() {

}

void linearithmic_function() {

}

void quadratic_function() {

}

void exponential_function() {

}

void factorial_function() {

}

int main() {
    std::cout << "Running constant function...\n";
    constant_function();

    std::cout << "Running logarithmic function...\n";
    logarithmic_function();

    std::cout << "Running linear function...\n";
    linear_function();

    std::cout << "Running linearithmic function...\n";
    linearithmic_function();

    std::cout << "Running quadratic function...\n";
    quadratic_function();

    std::cout << "Running exponential function...\n";
    exponential_function();

    std::cout << "Running factorial function...\n";
    factorial_function();
    
    return 0;
}