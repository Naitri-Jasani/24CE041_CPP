#include <iostream>
using namespace std;

class DynamicArray {
    int* data;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for(int i = 0; i < size; ++i)
            newData[i] = data[i];
        delete[] data;
        data = newData;
    }

public:
    DynamicArray(int cap = 2) {
        capacity = cap;
        size = 0;
        data = new int[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void insert(int value) {
        if(size == capacity)
            resize();
        data[size++] = value;
    }

    void remove(int pos) {
        if(pos < 0 || pos >= size) {
            cout << "Invalid position. Please try again." << endl;
            return;
        }
        for(int i = pos; i < size - 1; ++i)
            data[i] = data[i + 1];
        size--;
    }

    void display() {
        if(size == 0) {
            cout << "Array is empty." << endl;
            return;
        }
        cout << "Array elements: ";
        for(int i = 0; i < size; ++i)
            cout << data[i] << " ";
        cout << endl;
    }

    int getSize() {
        return size;
    }
};

int main() {
    DynamicArray arr;
    int choice, value, position;

    while(true) {
        cout << "\nMenu:\n";
        cout << "1. Insert an element\n";
        cout << "2. Remove element at position\n";
        cout << "3. Display array\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                arr.insert(value);
                break;
            case 2:
                cout << "Enter position to remove (0-based index): ";
                cin >> position;
                arr.remove(position);
                break;
            case 3:
                arr.display();
                break;
            case 4:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

