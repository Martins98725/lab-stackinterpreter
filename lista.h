struct Node {
    char key[15];
    int value;
    struct Node* next;
} ;

struct list {
    struct Node* first;
};
