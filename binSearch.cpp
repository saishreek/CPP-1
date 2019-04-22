#include <iostream>
using namespace std;

int search(int arr[], int val, int low, int high) {
    int mid = low + (high - low) / 2;

    while (arr[mid] != val && high > low) {
        if (arr[mid] < val) {
            high = mid;
        } else {
            low = mid + 1;
        }

        mid = low + (high - low) / 2;
    }

    if (arr[mid] == val) {
        return mid;
    }
    return -1;

}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int key = search(arr, 5, 0, 9);
    cout << "Pos: " << key << endl;

}