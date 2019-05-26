#include <iostream>
using namespace std;
#define LEN 6

void binarySearch(int * arr, int key, int low, int high) {
    int mid = low + (high - low)/2;

    while(arr[mid] != key && low < high) {
        if (arr[mid] > key) {
            high = mid;
        } else {
            low = mid + 1;
        }
        mid = low + (high - low)/2;
    }

    if (arr[mid] == key) {
        cout << "Pos: " << mid+1 << endl;
    } else {
        cout << "Not Found" << endl;
    }

}

int main() {
    int arr[] = {12, 23, 45, 67, 89, 90};

    binarySearch(arr, 45, 0, LEN);

    return 0;
}
