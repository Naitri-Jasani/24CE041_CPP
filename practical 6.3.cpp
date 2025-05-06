#include <iostream>
using namespace std;

void mergeSortedArrays(int* a, int n, int* b, int m, int*& result, int& size) {
    size = n + m;
    result = new int[size];

    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (a[i] < b[j])
            result[k++] = a[i++];
        else
            result[k++] = b[j++];
    }

    while (i < n)
        result[k++] = a[i++];

    while (j < m)
        result[k++] = b[j++];
}

int main() {
    int n, m;

    // Input for first array
    cout << "Enter number of elements in first sorted array: ";
    cin >> n;
    int* arr1 = new int[n];
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; ++i)
        cin >> arr1[i];

    // Input for second array
    cout << "Enter number of elements in second sorted array: ";
    cin >> m;
    int* arr2 = new int[m];
    cout << "Enter " << m << " sorted elements: ";
    for (int i = 0; i < m; ++i)
        cin >> arr2[i];

    int* merged = nullptr;
    int mergedSize = 0;

    // Merge arrays
    mergeSortedArrays(arr1, n, arr2, m, merged, mergedSize);

    // Output the merged array
    cout << "Merged sorted array: ";
    for (int i = 0; i < mergedSize; ++i)
        cout << merged[i] << " ";
    cout << endl;

    // Clean up
    delete[] arr1;
    delete[] arr2;
    delete[] merged;

    return 0;
}
