#include <iostream>
using namespace std;

class queue {
    struct node {
        int val;
        struct node * next;
    };

    public:
        struct node * front, * back;
        struct node * root;
        queue() {
            root = front = back = NULL;
        }

        void insert(int val) {
            struct node * N = new struct node;
            N->val = val;
            N->next = NULL;
            if (this->root == NULL) {
                root = front = back = N;
                return;
            }
            this->back->next = N;
            this->back = N;
        }

        int frontData() {
            return this->front->val;
        }

        int backData() {
            return this->back->val;
        }
};

int main() {
    queue Q;
    Q.insert(10);
    Q.insert(20);
    Q.insert(40);

    cout << Q.backData() << endl;

    return 0;
}
