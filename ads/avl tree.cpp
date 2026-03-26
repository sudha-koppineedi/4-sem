#include<stdio.h>
#include<stdlib.h>

// Node structure using typedef
typedef struct Node {
    int key;
    struct Node *left, *right;
    int height;
} Node;

// Utility functions
int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node *n) {
    if(n == NULL) return 0;
    return n->height;
}

// Create new node
Node* newnode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

// Right Rotation
Node* rightRotate(Node *y){
    Node *x = y->left;
    Node *T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    
    return x;
}

// Left Rotation
Node* leftRotate(Node *x){
    Node *y = x->right;
    Node *T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;  
    
    return y;
}

// Get Balance Factor
int getBalance(Node* node){
    if(node == NULL)
        return 0;
    
    return height(node->left) - height(node->right);
}

// Insert
Node* insertNode(Node *node, int key){
    
    if(node == NULL){
        return newnode(key);
    }
    
    if(key < node->key){
        node->left = insertNode(node->left, key);
    }
    else if(key > node->key){
        node->right = insertNode(node->right, key);
    }
    else{
        return node;
    }
    
    // Update height
    node->height = 1 + max(height(node->left), height(node->right));
    
    int balance = getBalance(node);
    
    // LL Case
    if(balance > 1 && key < node->left->key){
        return rightRotate(node);
    }
    
    // RR Case
    if(balance < -1 && key > node->right->key){
        return leftRotate(node);
    }
    
    // LR Case
    if(balance > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    
    // RL Case
    if(balance < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    return node;
}

// Search
Node* search(Node *root, int key){
    if(root == NULL || root->key == key){
        return root;
    }
    
    if(key < root->key){
        return search(root->left, key);
    }
    
    return search(root->right, key);
}

// Traversals
void inorder(Node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void preorder(Node *root) {
    if(root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

// Main
int main() {
    Node *root = NULL;
    int choice, key;

    while(1) {
        printf("\n--- AVL TREE MENU ---");
        printf("\n1.Insert\n2.Search\n3.Inorder\n4.Preorder\n5.Postorder\n6.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                root = insertNode(root, key);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if(search(root, key))
                    printf("FOUND\n");
                else
                    printf("NOT FOUND\n");
                break;

            case 3:
                printf("Inorder: ");
                inorder(root);
                break;

            case 4:
                printf("Preorder: ");
                preorder(root);
                break;

            case 5:
                printf("Postorder: ");
                postorder(root);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
