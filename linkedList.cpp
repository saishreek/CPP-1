#include <iostream>
using namespace std;

class linkedList {
    struct node {
        int val;
        node * next;
    };

    public:
        struct node * root = (struct node * )malloc(sizeof(struct node));
        int n_nodes;
        struct node * tail = (struct node * )malloc(sizeof(struct node));

        linkedList(int val) {
            this->n_nodes = 0;
            this->root->val = val;
            this->root->next = NULL;

            this->tail = this->root;

            this->n_nodes++;
        }

        void addNode(int val) {
            struct node * n = (struct node * )malloc(sizeof(struct node));
            n->val = val;
            n->next = NULL;
            this->n_nodes++;

            this->tail->next = n;
            this->tail = n;        
        }

        void printList() {
            struct node * n = this->root;
            for (int i = 0; i < this->n_nodes; i++) {
                cout << n->val << endl;
                n = n->next;
            }
        }

        void addToTop(int val) {
            struct node * n = (struct node * )malloc(sizeof(struct node));
            n->val = val;
            n->next = this->root;
            this->n_nodes++;
        
            this->root = n;
        }
};


class DLinkedList {
    struct node {
        int val;
        node * next;
        node * prev;
    };

    public:
        struct node * root = (struct node * )malloc(sizeof(struct node));
        int n_nodes;
        struct node * tail = (struct node * )malloc(sizeof(struct node));

        DLinkedList(int val) {
            this->n_nodes = 0;
            this->root->val = val;
            this->root->next = NULL;
            this->root->next = NULL;

            this->tail = this->root;

            this->n_nodes++;
        }

        void addNode(int val) {
            struct node * n = (struct node * )malloc(sizeof(struct node));
            n->val = val;
            n->next = NULL;
            n->prev = this->tail;
            this->n_nodes++;

            this->tail->next = n;
            this->tail = n;        
        }

        void printList() {
            struct node * n = this->root;
            for (int i = 0; i < this->n_nodes; i++) {
                cout << n->val << endl;
                n = n->next;
            }
        }

        void addToTop(int val) {
            struct node * n = (struct node * )malloc(sizeof(struct node));
            n->val = val;
            this->root->prev = n;
            n->next = this->root;
            this->n_nodes++;
        
            this->root = n;
        }
};

class CLinkedList {
    struct node {
        int val;
        node * next;
    };

    public:
        struct node * root = (struct node * )malloc(sizeof(struct node));
        int n_nodes;
        struct node * tail = (struct node * )malloc(sizeof(struct node));

        CLinkedList(int val) {
            this->n_nodes = 0;
            this->root->val = val;
            this->root->next = this->root;

            this->tail = this->root;

            this->n_nodes++;
        }

        void addNode(int val) {
            struct node * n = (struct node * )malloc(sizeof(struct node));
            n->val = val;
            n->next = this->root;
            this->n_nodes++;

            this->tail->next = n;
            this->tail = n;        
        }

        void printList() {
            struct node * n = this->root;
            for (int i = 0; i < this->n_nodes; i++) {
                cout << n->val << endl;
                n = n->next;
            }
        }

        void addToTop(int val) {
            struct node * n = (struct node * )malloc(sizeof(struct node));
            n->val = val;
            n->next = this->root;
            this->n_nodes++;
        
            this->root = n;
        }
};


int main() {

    CLinkedList L = CLinkedList(10);
    L.addNode(20);
    L.addNode(30);
    L.printList();

    L.addToTop(5);

    L.printList();


    return 0;
}