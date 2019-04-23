#include <iostream>
using namespace std;

class binTree {
    struct node {
        int val;
        node * left;
        node * right;
    };


    public:
        struct node * root = new node;
        binTree(int val) {
            this->root->val = val;
            this->root->left = this->root->right = NULL;
        }

        void insert(int val) {
            struct node * n = this->root;
            while(n != NULL) {
                if (val < n->left->val) {
                    n = n->left;
                } else if (val > n->right->val) {
                    n = n->right;
                }
            }

            // struct node * N = new node;
            // N->val = val;
            // N->left = N->right = NULL;
            // n = N;
        }    

};

int main() {
    binTree b = binTree(10);
    b.insert(20);
    // b.insert(5);

    // cout << b.root->left->val << endl;
}