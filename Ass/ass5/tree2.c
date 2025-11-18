#include<stdio.h>
#include<stdlib.h>

typedef struct node { 
    int data; 
    struct node *lchild; 
    struct node *rchild; 
    struct node *parent; 
    } treenode; 

 treenode* initializenode(int data){

   treenode* temp = NULL;

   temp = (treenode*)malloc(sizeof(treenode));

   if(NULL == temp)
      return NULL;

    // int data;
    // printf("Enter the data what you want to store in node ..\n");
    // scanf("%d",&data);
    
    temp->data = data;
    temp->lchild =NULL;
    temp->rchild =NULL;
    temp->parent =NULL;
     
    return temp;
 }


   int isEmpty(treenode *t) {

     if(NULL == t)
        return 1;

    else
        return 0;
    }
  

treenode* insertNode(treenode* t, int value){
    if( t == NULL ) {
        return initializenode(value);
    }
    treenode* temp;
    temp=initializenode(value);
    if( value < t->data ) {
        t->lchild = insertNode(t->lchild, value);
        t->lchild->parent = t;
    } else {
        t->rchild = insertNode(t->rchild, value);
        t->rchild->parent = t;
    }   

    return t;
}

int getCount(treenode* t) {
    if( t == NULL ) {
        return 0;
    }   
    return 1 + getCount(t->lchild) + getCount(t->rchild);
}


int  inorder(treenode* t) {
    if( t == NULL ){
        return 0;
    }   
    inorder(t->lchild);
    printf("%d ", t->data);
    inorder(t->rchild);
    return 1;
}


int preorder(treenode* t) {
    if( t == NULL ) {
        return 0;
    }   
    printf("%d ", t->data);
    preorder(t->lchild);
    preorder(t->rchild);
    return 1;
}


int postorder(treenode* t) {
    if( t == NULL ) {
        return 0;
    }   
    postorder(t->lchild);
    postorder(t->rchild);
    printf("%d ", t->data);
    return 1;
}



int main(){

     treenode* root = NULL;
    int choice, value;

    while (1) {
        printf("\n\nBinary Tree Menu:\n");
        printf("1. Insert Node\n");
        printf("2. Check if Tree is Empty\n");
        printf("3. Count Nodes\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case 2:
                if (isEmpty(root))
                    printf("Tree is empty.\n");
                else
                    printf("Tree is not empty.\n");
                break;
            case 3:
                printf("Total nodes: %d\n", getCount(root));
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}