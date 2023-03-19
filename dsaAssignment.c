#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//creation of node
struct Node {
    char val[10];
    struct Node* left;
    struct Node* right;
};
typedef struct Node Node;
//function to create the node 
Node* createNode(char* val) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    strcpy(newnode->val, val);
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
//function to insert any chapter in the book
void insert(Node** root, char* val) {
    if (*root == NULL) {
        *root = createNode(val);
    } else if (strcmp(val, (*root)->val) < 0) {
        insert(&((*root)->left), val);
    } else {
        insert(&((*root)->right), val);
    }
}
//fuction to search any chapter in the book
Node* search(Node* root, char* val) {
    if (root == NULL || strcmp(root->val, val) == 0) {
        return root;
    } else if (strcmp(val, root->val) < 0) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}
//function to display in-order binary tree
void displayInOrder(Node* root) {
    if (root != NULL) {
        displayInOrder(root->left);
        printf("%s\n", root->val);
        displayInOrder(root->right);
    }
}
//main function
int main() {
    Node* root = NULL;
    // Node* root = NULL;
    // insert(&root, "1");
    // insert(&root, "1.1");      
    // insert(&root, "1.1.1");

    // printf("In-order traversal of the tree:\n");
    // displayInOrder(root);
    // Node* node = search(root, "1.1.2");
    // if (node == NULL) {
    //     printf("Chapter not found\n");
    // } else {
    //     printf("Chapter found: %s\n", node->value);
    // }
    int test;
    char ch[10];
    while(1){
        printf("\n1:Insert Chapter 2:Search 3:Display 4:Exit\n");
        scanf("%d",&test);
        switch(test)
        {
            case 1:
                printf("Enter the chapter/sub-chapter\n");
                // insert(&root, "1.1.2");
                scanf("%s",ch);
                insert(&root, ch);
                break;
            case 2:
                printf("Enter the chapter to search\n");
                scanf("%s",ch);
                Node* node = search(root, ch);
                // Node* node = search(root, "1.1.2");
                if (node == NULL) {
                    printf("Chapter not found\n");
                } 
                else {
                    printf("Chapter found: %s\n", node->val);
                }
                break;
            case 3:
                printf("In-order traversal of the tree:\n");
                displayInOrder(root);
                break;
            default:
                exit(0);
        }
    }
    
    return 0;
}
