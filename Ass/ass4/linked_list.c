#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct listNode
{
    int data;
    struct listNode * next;
} node ;

node *  createnewNode(int val){
    node * newnode = NULL;
    newnode  = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("creation failed \n memory is full ....\n");
        return NULL;
    }

    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

node * AddNodeshort(node * start , int val){
    node* R = NULL;
    R = start;

    node* Addednode = NULL;
    Addednode = (node*)malloc(sizeof(node));

    if(Addednode == NULL){
        printf("memory is full .... \n we can't add new node.. \n ");
        return start;
    } 
    Addednode->data = val;
    Addednode->next = NULL;

    if(val >= R->data){
        Addednode->next = start;
        return Addednode;
    }

    node* prev = NULL;

    while(R){
        if(val >= R->data ){
            Addednode->next = R;
            prev->next  = Addednode;
            return start;
        }
        prev = R;
        R = R->next;
    }

    prev->next = Addednode;

    return start;
}

int IsListnodesorted(node* start ){
    node * p  = NULL;
    node * prev  = NULL;
    p = start;
    prev = p;
    p = p->next;
    while(p){
        if (p->data > prev->data ) {
            printf(" this linked list is not sorted in descending manner .. \n");
            return 0;
        }
        prev = p;
        p = p->next;
    }
    return 1;
}

int IselePresentinList( node* start , int ele ){
    int index = 0;
    node* p = NULL;
    p = start;
    while(p){
        if(ele == p->data){
            index++;
            return index;
        }
        index++;
        p = p->next;
    }
    return 0;
}

node * deletedListNodesorted( node * start , int ele ){
    node * p = NULL;
    p  = start;
    if( ele == p->data){
        start = start->next;
        free(p);
        return start;
    }

    node* prev = NULL;
    prev = p;
    p = p->next;

    while(p){
        if(ele == p->data){
            prev->next = p->next;
            free(p);
            return start;
        }
        prev = p;
        p = p->next;
    }
    printf(" Supplied node does not exist ..\n");
    return start ;
}

void printsortedlist( node* start){
    node* P = NULL;
    P= start ;
    printf( " Start -> ");
    int count = 0;
    while (P && count < 50)
    {
        printf( " %d-> ",P->data);
        P =P->next;
        count++;
    }
  
    printf( "NULL \n");
}
node * freeListNodesorted(node* start){
    node* p = NULL;
    node* prev = NULL;
    p = start;
    while(p){
        prev = p;
        p = p->next;
        free(prev);
    }
    start = NULL;
    if(p == NULL){
        printf(" memory obtained by all nodes free \n ");
        return start;
        }
    return NULL;
}


node* reverseListNodeSorted(node* start ){
    node* p = start ;
    node* before = NULL;
    node* prev = NULL;

   while ( p != NULL){
      
      before = p->next;
      p->next = prev;
      prev = p;
      p = before;

   }

    return prev;
}

void updateListNode(struct listNode *start){
 
    node* p = NULL;
    p = start;
    while (p)
    {
        p->data = p->data + rand()%10 ;
        p = p->next;
    }
}
node* sortListNode_2(node* start) {
    if (!start || !start->next) 
    return start;

    node *sorted = NULL;

    while (start) {
        
        node *maxNode = start;
        node *maxPrev = NULL;
        node *prev = NULL;
        node *curr = start;

        while (curr) {
            if (curr->data < maxNode->data) {
                maxNode = curr;
                maxPrev = prev;
            }
            prev = curr;
            curr = curr->next;
        }

       
        if (maxPrev) {
            maxPrev->next = maxNode->next;
        } else {
            start = maxNode->next;
        }

      
        maxNode->next = sorted;
        sorted = maxNode;
    }

    return sorted;
}

 node* sortListNode_1(node *start){
    node* P = NULL;
    node* P_prev = NULL; 
    node* P_bef = NULL; 
    node*Q = NULL;
    node*Q_prev = NULL;
    node*Q_bef = NULL;
    node*R = NULL;
    P = start;
    int max;
    max = P->data;
     R = P;
   while(R){
        if(R->data >= max){
            max = R->data;
        }
        R = R->next;
    }
    Q =P;
    while(Q){
       Q_bef = Q->next;
       
       if(Q->data == max)
       break;

       Q_prev = Q;
        Q =Q->next;
   }

   P_bef = P->next;

   Q->next = P_bef;
   Q_prev->next = P;
   P->next = Q_bef;
   start = Q;
   P = Q;

    while(P){

    P_bef = P->next;
    max = P->data;
    R = P;
    while(R){
        if(R->data >= max){
            max = R->data;
        }
        R = R->next;
    }
    Q =P;
    while(Q){
       Q_bef = Q->next;
       
       if(Q->data == max)
       break;
       
       Q_prev = Q;
        Q =Q->next;
    }
     P_prev->next = Q;
     Q->next = P_bef;
     Q_prev->next = P;
     P->next = Q_bef;
  
     P = Q;

     P_prev = P;
     P = P->next;
    }
    return  start;
 }



node* mergeListNodeSorted(node*start1, node*start2 ){
    node* list;
    node* R;
  if((start1 == NULL)&&(start2 == NULL)){
    R = start1;
    start1 = NULL;
    return R;
}

if((start1 != NULL)&&(start2 == NULL)){
    R = start1;
    start1 = NULL;
    return R;
}

if((start1 == NULL)&&(start2 != NULL)){
    R = start2;
    start2 = NULL;
    return R;
}
if(start1->data < start2->data){
    list = start2;
    start2 = start2->next;
}
else{
    list = start1;
    start1 = start1->next;
}
R = list;

while((start1 != NULL)&&(start2 != NULL)){
   if(start1->data < start2->data){
    R->next = start2;
    start2 = start2->next;
    R = R->next;
}
else{
    R->next = start1;
    start1 = start1->next;
    R = R->next;
}
}

if((start1 != NULL)&&(start2 == NULL)){
    R->next = start1;
    start1 = NULL;
    start2 = NULL;
    return list;
}

if((start1 == NULL)&&(start2 != NULL)){
    R->next = start2;
    start1 = NULL;
    start2 = NULL;
    return list;
}
return NULL;  
}


void problem1( node * start )
{   
    printf(" 1. create new list  2. add new element in list 3. delete element in list \n");
    printf("  4. for searching element in list 5. for checking if list is sorted 6. for printing list\n ");

    int choice ;
    choice = 0;
    int n = 0;

    while(choice != -1){
        printf(" Enter your choice and if you want to exit enter -1\n ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                printf(" Enter your Data of first node \n ");
                scanf("%d",&n);
                start = createnewNode(n);
                break;

            case 2:
                printf(" Enter your Data of new node \n ");
                scanf("%d",&n);
                start = AddNodeshort(start ,n);
                break;

            case 3:
                printf(" Enter your Data to delete a node \n ");
                scanf("%d",&n);
                start = deletedListNodesorted( start ,n );
                break;

            case 4:
                printf(" Enter your element for searching in linked list  \n ");
                scanf("%d",&n);
                if( IselePresentinList( start , n )){
                    printf("element present in node number %d\n",IselePresentinList( start , n ));
                }
                else{
                    printf("element not found \n");
                }
                break;

            case 5:
                if(IsListnodesorted(start )){
                    printf(" linked list is sorted\n");
                }
                else{
                    printf(" linked list is not sorted\n");
                }
                break;

            case 6:
                printsortedlist( start);
                break;

            default:
                printf("Enter a valid choice \n");
                break;
        }
    }
}
void problem_2( node* start1, node* start2, node* start ){

    printf(" 1. for free link list  2. for revers linklist 3. to update link list  \n");
    printf("  4. to sort the link list  5. to merge the link list 6. to enter in problem 1 \n ");
    int choice ;
    
    while(choice != -1){
        
        printf("Enter your choic and enter -1 to exit \n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            start = freeListNodesorted(start);
            printsortedlist(start);
            break;
        case 2:
            start = reverseListNodeSorted(start);
            printsortedlist(start);
            break;
        case 3:
             updateListNode(start);
            printsortedlist(start);
            break;
        case 4:
           start =  sortListNode_2(start);
            printsortedlist(start);
            break;
        case 5:
          printsortedlist(start1);
          printsortedlist(start2);
          node* start3 =  mergeListNodeSorted(start1,start2);
          printsortedlist(start3);
            break;
        case 6:
         if(start == NULL)
           start = createnewNode(23);

           problem1(start);
            break;
        
        default:
            break;
        }
    }

}
int main(){
    node* start = NULL;
    start = createnewNode(7);
    AddNodeshort(start ,5);
    AddNodeshort(start ,3);
    AddNodeshort(start ,1);
    AddNodeshort(start ,6);
    AddNodeshort(start ,4);
    AddNodeshort(start ,2);
    // problem1(start);

    node* start1 = createnewNode(7);
    node* start2 = createnewNode(7);
    AddNodeshort(start1 ,5);
    AddNodeshort(start1 ,3);
    AddNodeshort(start1 ,1);
    AddNodeshort(start2 ,6);
    AddNodeshort(start2 ,4);
    AddNodeshort(start2 ,2);
    printsortedlist(start1);
//   start1 = reverseListNodeSorted(start1);
//     printsortedlist(start1);

    problem_2(start1,start2,start);

    return 0;
}