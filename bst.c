#include <stdio.h>
#include <stdlib.h>

typedef struct nodeStructure{
   int num;
   struct nodeStructure *left;
   struct nodeStructure *right;
}myS;

//FUNCTION DECLARATION
myS* createNode(int);
myS* insertNode(myS*, int);
void preorder(myS*);
void inorder(myS*);
void postorder(myS*);
void menu(myS*);

int main()
{
    myS* root = NULL;

    int size;
   
   printf("Enter the length of numbers : ");
   scanf("%d", &size);
   
    int nums[size];
   
   printf("Enter numbers (first number should be root): ");
   for(int i=0;i < size;i++){
      scanf("%d", &nums[i]);
   }
   
    for(int i = 0;i < size;i++){
        root = insertNode(root, nums[i]);
    }
    
    printf("Binary Search Tree created!\n");

    menu(root);









    printf("-----------------------PROGRAM TERMINATED-----------------------");
}//MAIN


myS* createNode(int num){
    myS* newNode = (myS*)malloc(sizeof(myS));
    
    newNode->num = num;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

myS* insertNode(myS* node, int num){
    if(node == NULL){
        node = createNode(num);
    }else if(node->num >= num){
        node->left = insertNode(node->left, num);
    }else{
        node->right = insertNode(node->right, num);
    }
    
    return node;
}

void preorder(myS* node){
    if(node!=NULL){
        printf("%d  ", node->num);
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(myS* node){
    if(node!=NULL){
        inorder(node->left);
        printf("%d  ", node->num);
        inorder(node->right);
    }
}

void postorder(myS* node){
    if(node!=NULL){
        postorder(node->left);
        postorder(node->right);
        printf("%d  ", node->num);
    }
}

void menu(myS* rootNode){
    int opt;
    

    do{
        restart:

        printf("Select a traversal method : \n");
        printf("1. Preorder\n");
        printf("2. Inorder\n");
        printf("3. Postorder\n");

        scanf("%d", &opt);

        switch (opt){
        case 1:
            printf("BST : ");
            preorder(rootNode);
            break;
        case 2:
            printf("BST : ");
            inorder(rootNode);
            break;
        case 3:
            printf("BST : ");
            postorder(rootNode);
            break;
        
        default:
            printf("Enter the correct option\n");
            goto restart;
            break;
        }

        printf("\n1. Return to menu\n");
        printf("0. Exit\n");
        scanf("%d", &opt);
    }while(opt != 0);
}






















