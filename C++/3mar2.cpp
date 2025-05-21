#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr, int& comparisons, int& swaps) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; 
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j; 
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            swaps++; 
        }
    }
}

int main() {
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n;
        cout << "Enter the size of the array: ";
        cin >> n;

        vector<int> arr(n);
        cout << "Enter the array elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int comparisons = 0, swaps = 0;
        selectionSort(arr, comparisons, swaps);

        cout << "Sorted Array: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "Number of Comparisons: " << comparisons << endl;
        cout << "Number of Swaps: " << swaps << endl;
    }

    return 0;
}