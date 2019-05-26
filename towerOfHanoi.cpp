#include <iostream>
using namespace std;

void towerOfHanoi(int n, char start, char end, char mid) {
    if (n == 1) {
        cout << "Move Disk 1 from rod " << start << " to rod " << end << endl;
        return;
    }

    towerOfHanoi(n-1, start, mid, end);
    cout << "Move Disk " << n << " from rod " << start << " to rod " << end << endl;
    towerOfHanoi(n-1, mid, end, start);
}

int main() {
    towerOfHanoi(3, 'A', 'C', 'B');

    return 0;
}
