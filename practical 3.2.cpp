////#include <iostream>
////#include <vector>
////using namespace std;
////
////// Recursive function to calculate sum of array elements
////int recursiveSum(const vector<int>& arr, int n) {
////    if (n == 0)
////     {
////         return 0;
////     }
////    else
////    {
////        return arr[n - 1] + recursiveSum(arr, n - 1);
////    }
////}
////
////// Iterative function to calculate sum of array elements
////int iterativeSum(const vector<int>& arr) {
////    int sum = 0;
////    for (int num : arr) {
////        sum += num;
////    }
////    return sum;
////}
////
////int main() {
////    int size;
////
////    cout << "Enter the size of the array: ";
////    cin >> size;
////
////    vector<int> numbers(size);
////    cout << "Enter " << size << " elements:\n";
////    for (int i = 0; i < size; ++i) {
////        cout << "Element " << i + 1 << ": ";
////        cin >> numbers[i];
////    }
////
////    int sumRecursive = recursiveSum(numbers, size);
////    int sumIterative = iterativeSum(numbers);
////
////    cout << "\n======= Results =========\n";
////    cout << "Sum using recursion: " << sumRecursive << endl;
////    cout << "Sum using iteration: " << sumIterative << endl;
////
////    return 0;
////}
//#include <iostream>
//#include <vector>
//#include <chrono> // For timing
//using namespace std;
//using namespace chrono; // For convenience
//
//// Recursive function to calculate sum of array elements
//int recursiveSum(const vector<int>& arr, int n) {
//    if (n == 0) {
//        return 0;
//    } else {
//        return arr[n - 1] + recursiveSum(arr, n - 1);
//    }
//}
//
//// Iterative function to calculate sum of array elements
//int iterativeSum(const vector<int>& arr) {
//    int sum = 0;
//    for (int num : arr) {
//        sum += num;
//    }
//    return sum;
//}
//
//int main() {
//    int size;
//
//    cout << "Enter the size of the array: ";
//    cin >> size;
//
//    if (size <= 0) {
//        cout << "Invalid array size!" << endl;
//        return 1;
//    }
//
//    vector<int> numbers(size);
//    cout << "Enter " << size << " elements:\n";
//    for (int i = 0; i < size; ++i) {
//        cout << "Element " << i + 1 << ": ";
//        cin >> numbers[i];
//    }
//
//    // Timing recursive sum
//    auto startRecursive = high_resolution_clock::now();
//    int sumRecursive = recursiveSum(numbers, size);
//    auto endRecursive = high_resolution_clock::now();
//    auto durationRecursive = duration_cast<microseconds>(endRecursive - startRecursive);
//
//    // Timing iterative sum
//    auto startIterative = high_resolution_clock::now();
//    int sumIterative = iterativeSum(numbers);
//    auto endIterative = high_resolution_clock::now();
//    auto durationIterative = duration_cast<microseconds>(endIterative - startIterative);
//
//    // Display results
//    cout << "\n======= Results =========\n";
//    cout << "Sum using recursion: " << sumRecursive << endl;
//    cout << "Execution time (recursion): " << durationRecursive.count() << " microseconds\n";
//    cout << "Sum using iteration: " << sumIterative << endl;
//    cout << "Execution time (iteration): " << durationIterative.count() << " microseconds\n";
//
//    return 0;
//}
#include <iostream>
#include <vector>
#include <chrono> // Required for measuring execution time

using namespace std;
using namespace chrono;

// Recursive function to calculate sum of array elements
int recursiveSum(const vector<int>& arr, int n) {
    if (n == 0) {
        return 0;
    } else {
        return arr[n - 1] + recursiveSum(arr, n - 1);
    }
}

// Iterative function to calculate sum of array elements
int iterativeSum(const vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
}

int main() {
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid array size!" << endl;
        return 1;
    }

    vector<int> numbers(size);
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> numbers[i];
    }

    // Measure recursive sum time
    auto startRecursive = high_resolution_clock::now();
    int sumRecursive = recursiveSum(numbers, size);
    auto endRecursive = high_resolution_clock::now();
    auto durationRecursive = duration_cast<nanoseconds>(endRecursive - startRecursive);

    // Measure iterative sum time
    auto startIterative = high_resolution_clock::now();
    int sumIterative = iterativeSum(numbers);
    auto endIterative = high_resolution_clock::now();
    auto durationIterative = duration_cast<nanoseconds>(endIterative - startIterative);

    // Display results
    cout << "\n======= Results =========\n";
    cout << "Sum using recursion: " << sumRecursive << endl;
    cout << "Execution time (recursion): " << durationRecursive.count() << " nanoseconds\n";

    cout << "Sum using iteration: " << sumIterative << endl;
    cout << "Execution time (iteration): " << durationIterative.count() << " nanoseconds\n";

    return 0;
}
