#include <iostream>
#include <cmath>

using namespace std;

class Sort {
public:
    void displayArray(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void heapify(int arr[], int size, int i) {
        int largest = i; //inialize largest as root
        int left = 2 * i + 1;//left child index
        int right = 2 * i + 2;//right child index

        if (left < size && arr[left] > arr[largest])
            largest = left;

        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, size, largest);
        }
    }

    void heapSort(int arr[], int size) {
        cout << "Heap Sort Passes:" << endl;
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(arr, size, i);
            displayArray(arr, size);
        }

        for (int i = size - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
            displayArray(arr, size);
        }
    }

    void shellSort(int arr[], int size) {
        cout << "Shell Sort Passes:" << endl;
        for (int gap = size / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < size; i++) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
            displayArray(arr, size);
        }
    }
};

int main() {
    Sort sorter;
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Original Array: ";
    sorter.displayArray(arr, size);

    int choice;
    cout << "Enter sorting method (1 for Heap Sort, 2 for Shell Sort): ";
    cin >> choice;

    if (choice == 1) {
        sorter.heapSort(arr, size);
        cout << "Sorted Array using Heap Sort: ";
        sorter.displayArray(arr, size);
    }
    else if (choice == 2) {
        sorter.shellSort(arr, size);
        cout << "Sorted Array using Shell Sort: ";
        sorter.displayArray(arr, size);
    }
    else {
        cout << "Invalid choice! Exiting..." << endl;
    }

    return 0;
}
