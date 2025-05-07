#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> sequence;
    int n, input;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> input;
        sequence.push_back(input);
    }

    reverse(sequence.begin(), sequence.end());

    cout << "Reversed sequence:\n";
    for (const int& num : sequence) {
        cout << num << " ";
    }

    auto front = sequence.begin();
    auto back = sequence.end() - 1;

    while (front < back) {
        iter_swap(front, back);
        ++front;
        --back;
    }

    cout << "\n\nReversed sequence:\n";
    for (const int& num : sequence) {
        cout << num << " ";
    }

        return 0;
}


