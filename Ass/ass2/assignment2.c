#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Stack {
    int StackSize;
    int StackCount;
    int *StackElement;
} Stack;

void initStack(Stack *s, int size) {
    s->StackSize = size;
    s->StackCount = 0;
    s->StackElement = (int *)calloc(size , sizeof(int));
}

int pushintstack(Stack *s, int value ) {
    if (s->StackCount >= s->StackSize) {
        printf("Stack overflow\n");
        return 0; 
    }
    s->StackElement[s->StackCount] = value;
    printf("Pushed %d onto stack at index %d\n", value, s->StackCount );
    s->StackCount++;
    return value;
}

int* popintstack(Stack *s ,int *value ) {
    if (s->StackCount <= 0) {
        printf("Stack underflow\n");
        return NULL; 
    }
*value = s->StackElement[s->StackCount-1];
    printf("Popped %d from stack at index %d\n", *value, s->StackCount-1 );
    s->StackCount--;
    return *value;
    
}

void printStack(Stack *s) {
    if (s->StackCount == 0) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: \n");
    printf("Stack size: %d, Stack count: %d\n", s->StackSize, s->StackCount);
    printf("---------------------------------------------------\n");
    for (int i = 0; i < s->StackCount; i++) {
        printf(" value %d at index %d ", s->StackElement[i] ,i);
        printf("\n");
    }
    printf("---------------------------------------------------\n");
    printf("\n");
}

int stackSize(Stack *s)
{
    return s->StackCount + 1;
}


int FreeStack(Stack *s) {
    if (s->StackElement != NULL) {
        free(s->StackElement);
        s->StackElement = NULL;
        s->StackSize = 0;
        s->StackCount = 0;
        return 1; 
    }
    return 0; 
}

int isStackEmpty(Stack *s) {
    if (s == NULL) {
        printf("Stack is not initialized\n");
        return 0; 
    }
    if (s->StackCount == 0) {
        printf("Stack is empty\n");
        return 1;
    } else {
        printf("Stack is not empty\n");
        return 0;
    }

}
int isStackFull(Stack *s) {
    if (s == NULL) {
        printf("Stack is not initialized\n");
        return 0; 
    }
    if (s->StackCount == s->StackSize) {
        printf("Stack is full\n");
        return 1;
    } else {
        printf("Stack is not full\n");
        return 0;
    }
}

void CheckStack(Stack *s)
{
    int ch, d;
    while (1)
    {
        printf("\n---Stack menu---\n");
        printf("1. Push element\n");
        printf("2. Pop element\n");
        printf("3. Display stack\n");
        printf("4. Check stack size\n");
        printf("5. Check if stack is full\n");
        printf("6. Check if stack is empty\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to be pushed into the stack: ");
            scanf("%d", &d);
            if (pushintstack(s, d))
                printf("Push successful\n");
            else
                printf("Push unsuccessful\n");
            break;
        case 2:
            if (popintstack(s, &d))
            {
                printf("Pop successful\n");
                printf("Element poped is: %d\n", d);
            }
            else
                printf("Pop unsuccessful\n");
            break;
        case 3:
            printStack(s);
            break;
        case 4:
            printf("No.of elements in the stack is: %d\n", stackSize(s));
            break;
        case 5:
            if (isStackFull(s))
                printf("Stack is full\n");
            else
                printf("Stack is not full\n");
            break;
        case 6:
            if (isStackEmpty(s))
                printf("Stack is empty\n");
            else
                printf("Stack is not empty\n");
            break;
        case 7:
            printf("Program ended successfully\n");
            FreeStack(s);
            return;
        default:
            printf("Invalid choice\n");
        }
    }
}

int mathExp()
{
    printf("\nEnter the mathematical expression:\n");
    char m[50];
    fgets(m, 50, stdin);
    Stack s;
    int maxSize = 0;
    for (int i = 0; i < strlen(m); i++)
        if (m[i] == '(' || m[i] == ')' || m[i] == '{' || m[i] == '}' || m[i] == '[' || m[i] == ']')
            maxSize++;
    initStack(&s, maxSize);
    for (int i = 0; i < strlen(m); i++)
        if (m[i] == '(' || m[i] == '{' || m[i] == '[')
            pushintstack(&s, (int)m[i]);
        else if (m[i] == ')' || m[i] == '}' || m[i] == ']')
            if (!isStackEmpty(&s) &&
                ((m[i] == ')' && s.StackElement[s.StackCount] == '(') ||
                 (m[i] == '}' && s.StackElement[s.StackCount] == '{') ||
                 (m[i] == ']' && s.StackElement[s.StackCount] == '[')))
                popintstack(&s, NULL);
            else
            {
                FreeStack(&s);
                return 0;
            }
    if (stackSize(&s) == 0)
    {
        FreeStack(&s);
        return 1;
    }
    else
    {
        FreeStack(&s);
        return 0;
    }
}

void Two_Stack()
{
        
    int *poppedValue = (int *)malloc(10*sizeof(int));
    Stack s2;
    Stack s1;
    int sizes1 ;
    int sizes2;
    printf("Enter the size of stack 1: ");
    scanf("%d", &sizes1);
    printf("Enter the size of stack 2: ");
    scanf("%d", &sizes2);
    initStack(&s1, sizes1);
    initStack(&s2, sizes2);
    for (int i = 0; i < sizes1; i++)
    {
        int value;
        printf("Enter value to push onto stack 1: at index %d: ", i);
        scanf("%d", &value);
        pushintstack(&s1, value);
    }
    for (int i = 0; i < sizes2; i++)
    {
        int value;
        printf("Enter value to push onto stack 1: at index %d: ", i);
        scanf("%d", &value);
        pushintstack(&s2, value);
    }
    for (int i = sizes2; i >0; i--)
    {
        int value;
        popintstack(&s2, &value);
    }
    for (int i = sizes1; i >0; i--)
    {
        int value;
        popintstack(&s1, &value);
    }
    free(s1.StackElement);
    
    free(s2.StackElement);
}

int main() {
    
     int x;
    printf("\n---Answer menu---\n");
    printf("1. Check Stack implementation\n");
    printf("2. Two stack problem\n");
    printf("3. Check mathematical expression\n");
    printf("Enter your choice: ");
    scanf("%d", &x);
    getchar();
    switch (x)
    {
    case 1:
        printf("Enter the maximum number of elements in the stack\n");
        Stack s;
        int maxSize;
        scanf("%d", &maxSize);
        initStack(&s, maxSize);
        CheckStack(&s);
        break;
    case 2:
        Two_Stack();
        break;
    case 3:
        if (mathExp())
            printf("Mathematical expression has correct sequence of parentheses\n");
        else
            printf("Mathematical expression does not have correct sequence of parentheses\n");
        break;
    default:
        printf("Invalid choice\n");
    }

    return 0;
}