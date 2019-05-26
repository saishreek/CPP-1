#include <iostream>
using namespace std;

class BinTree {
    struct node {
        int val;
        struct node * left;
        struct node * right;
    };

    public:
        struct node * root = new struct node;
        
        BinTree(int val) {
            this->root->val = val;
            this->root->left = this->root->right = NULL;
        }

        void insert(int val) {
            struct node * tmp = root;
            while (1) {
                if (tmp->val > val && tmp->left != NULL) {
                    tmp = tmp->left;
                } else if (tmp->val < val && tmp->right != NULL){
                    tmp = tmp->right;
                } else {
                    break;
                }
            }

            struct node * N = new struct node;
            N->val = val;
            N->left = N->right = NULL;

            if (val < tmp->val) {
                tmp->left = N;
            } else if (val > tmp->val) {
                tmp->right = N;
            }
        }

};


int main() {
    BinTree b(10);
    b.insert(5);
    b.insert(20);

    cout << b.root->right->val << endl;
}
