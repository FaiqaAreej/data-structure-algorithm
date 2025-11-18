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

    temp->data = data;
    temp->lchild =NULL;
    temp->rchild =NULL;
    temp->parent =NULL;
     
    return temp;
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


int height (treenode* t){
    if(t==NULL){
        return -1;
    }
    int lheight=height(t->lchild);
    int rheight=height(t->rchild);
    if(lheight>rheight){
        return lheight+1;
    }
    else{
        return rheight+1;
    }   
    }

int max(treenode *t) {
    if (t->rchild == NULL)
        return t->data;
    else
        return max(t->rchild);
}

int min(treenode *t){
    if(t->lchild==NULL)
        return t->data;
    else
        return min(t->lchild);
}

int equal(treenode *t1, treenode *t2) {

if((t1 == NULL)&&(t2 == NULL))
  return 1;

if((t1 == NULL)||(t2 == NULL))
  return 0;

 return ((t1->data == t2->data) &&
           equal(t1->lchild, t2->lchild) &&
           equal(t1->rchild, t2->rchild));
  
}


treenode* findNode(treenode* t, int key) {

    if (t == NULL) 
    return NULL;

    if (key == t->data) 
    return t;

    if (key < t->data)
     return findNode(t->lchild, key);

    else 
    return findNode(t->rchild, key);
}

treenode* findMin(treenode* t) {

    while (t && t->lchild != NULL)
        t = t->lchild;

    return t;
}

treenode* insucc(treenode* t, int key) {
    treenode* target = findNode(t, key);
    if (target == NULL) return NULL;

    if (target->rchild != NULL)
        return findMin(target->rchild);

    treenode* succ = NULL;
    treenode* ancestor = target->parent;
    while (ancestor != NULL && target == ancestor->rchild) {
        target = ancestor;
        ancestor = ancestor->parent;
    }
    succ = ancestor;

    return succ;
}


int deleteNodeHelper(treenode **t, int val) {
    if (*t == NULL)
        return 0;

    if (val < (*t)->data)
        return deleteNodeHelper(&((*t)->lchild), val);

    else if (val > (*t)->data)
        return deleteNodeHelper(&((*t)->rchild), val);
    else {
        treenode *temp = *t;

        if (temp->lchild == NULL && temp->rchild == NULL) {
            *t = NULL;
            free(temp);  
        }
      
        else if (temp->lchild == NULL) {
            *t = temp->rchild;
            (*t)->parent = temp->parent;
            free(temp); 
        }
  
        else if (temp->rchild == NULL) {
            *t = temp->lchild;
            (*t)->parent = temp->parent;
            free(temp);  
        }
       
        else {
            treenode *succ = temp->rchild;
            while (succ->lchild != NULL)
                succ = succ->lchild;

            temp->data = succ->data;
            return deleteNodeHelper(&(temp->rchild), succ->data);
        }

        return 1;
    }
}




int main() {
    treenode *root = NULL;
    int choice, value, result;
    treenode *succ = NULL, *t2 = NULL ,*t1 = NULL; 

    while (1) {
        printf("\n====== Binary Search Tree Menu ======\n");
        printf("1. Insert Node\n");
        printf("2. Find Height of Tree\n");
        printf("3. Find Maximum Value\n");
        printf("4. Find Minimum Value\n");
        printf("5. Delete Node\n");
        printf("6. Find Inorder Successor\n");
        printf("7. Compare with Another Tree\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;

            case 2:
                printf("Height of tree: %d\n", height(root));
                break;

            case 3:
                if (root)
                    printf("Maximum value: %d\n", max(root));
                else
                    printf("Tree is empty.\n");
                break;

            case 4:
                if (root)
                    printf("Minimum value: %d\n", min(root));
                else
                    printf("Tree is empty.\n");
                break;

            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                result = deleteNodeHelper(&root, value);
                if (result)
                    printf("Node deleted successfully.\n");
                else
                    printf("Node not found.\n");
                break;

            case 6:
                printf("Enter key to find inorder successor: ");
                scanf("%d", &value);
                succ = insucc(root, value);
                if (succ)
                    printf("Inorder successor of %d is %d\n", value, succ->data);
                else
                    printf("Inorder successor not found or key doesn't exist.\n");
                break;

            case 7:
                printf("Creating two tree for comparison...\n");
                t1 = NULL;
                t2 = NULL;
                printf("Enter values for 1st tree (end with -1): ");
                while (1) {
                    scanf("%d", &value);
                    if (value == -1) break;
                    t1 = insertNode(t1, value);
                }
                printf("Enter values for 2nd tree (end with -1): ");
                while (1) {
                    scanf("%d", &value);
                    if (value == -1) break;
                    t2 = insertNode(t2, value);
                }
                if (equal(t1, t2))
                    printf("Trees are equal.\n");
                else
                    printf("Trees are not equal.\n");
                break;

            case 8:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}