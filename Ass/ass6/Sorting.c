#include <stdio.h>
#include <stdlib.h>
#define N 20
int exchanges;

void swap(int* a, int* b){
    int t= *a;
    *a=*b;
    *b=t;
    exchanges++;
}

void default_insertion(int a[], int n){
    exchanges=0;
    for(int i=1; i<n; i++){
        for(int j=i; j>=0 && a[j]<a[j-1]; j--){
            swap(&a[j], &a[j-1]);
        }
    }
}

void insertion(int a[], int n){
    exchanges =0;
    for(int i=0; i<n; i++){
        int k = a[i];
        int j=i-1;
        while(j>=0 && a[j]>k){
            a[j+1] = a[j];
            j--;
            exchanges++;
        }
        a[j+1] =k;
    }
}

void bubble_default(int a[], int n){
    exchanges =0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(a[j] >a[j+1]){
                swap(&a[j], &a[j+1]);
            }
        }
    }
}

void bubble_avoid_swap(int a[], int n) {
    exchanges = 0;
    for (int i=0;i<n;i++)
        for (int j=0;j<n-1;j++)
            if (a[j] > a[j+1]) {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                exchanges++;
            }
}

void bubble_flagged(int a[], int n){
    exchanges=0;
    int flag=1;
    for(int i=0; i<n-1 && flag; i++){
        flag=0;
        for(int j=0; j<n-i-1; j++){
            if(a[j]>a[j+1]){
                swap(&a[j], &a[j+1]);
                flag=1;
            }
        }
    }
}

void bubble_range_limit(int a[], int n){
    exchanges =0;
    int newn;
    while(n>1){
        newn=0;
        for(int i=1; i<n; i++){
            if(a[i-1]>a[i]){
                swap(&a[i-1], &a[i]);
                newn=i;
            }
        }n=newn;
    }
}

void bubble_alternating(int a[], int n){
    exchanges=0;
    int l=0;
    int r=n-1;
    int flag=1;
    while(flag){
        flag=0;
        for(int i=l; i<r; i++){
            if(a[i]>a[i+1]){
                swap(&a[i], &a[i+1]);
                flag=1;
            }
        }if(!flag){
            break;
        }
        flag=0;
        for(int i=r-1; i>l; i--){
            if(a[i-1]>a[i]){
                swap(&a[i-1], &a[i]);
                flag=1;
            }
        }r--;
    }
}

void merge(int a[], int l, int m, int r){
    int n1= m-l+1;
    int n2=r-m;
    
    int left[n1], right[n2];

    for(int i=0; i<n1; i++){
        left[i] =a[l+i];
    }
    for(int j=0; j<n2; j++){
        right[j]= a[m+1+j];
    }
    int i=0,j=0,k=l;

    while(i<n1 && j<n2){
        if(left[i]<= right[j]){
            a[k++] = left[i++];
        }else a[k++] =right[j++];
    }
    while(i<n1){
        a[k++] = left[i++];
    }
    while(j<n2){
        a[k++] =right[j++];
    }
}

void mergesort(int a[], int l, int r){
    if(l>=r) return;

    int m=(l+r)/2;
    mergesort(a,l,m);
    mergesort(a,m+1, r);
    merge(a,l,m,r);
}

int median(int a[], int l, int r){
    int m=(l+r)/2;
    if (a[l] > a[m]) swap(&a[l], &a[m]);
    if (a[m] > a[r]) swap(&a[m], &a[r]);
    if (a[l] > a[m]) swap(&a[l], &a[m]);
    return a[m];
}

int partition(int a[], int l, int r) {
    int pivot = median(a, l, r);
    int i = l, j = r;
    while (1) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i >= j) return j;
        swap(&a[i], &a[j]);
        i++; j--;
    }
}

void quick_sort(int a[], int l, int r) {
    if (l < r) {
        int p = partition(a, l, r);
        quick_sort(a, l, p);
        quick_sort(a, p+1, r);
    }
}

void print_array(int a[], int n){
    for (int i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
void copy(int a[], int arr[], int n){
    for(int i=0; i<n; i++){
        a[i] = arr[i];
    }
}

int main(){
    while(1){
        int choice, sort_choice, n;
        
        int L1[20] = {1,16,12,26,25,35,33,58,45,42,56,67,83,75,74,86,81,88,99,95};
        int L2[20] = {1,17,21,42,24,27,32,35,45,47,57,23,66,69,70,76,87,85,95,99};
        int L3[20] = {22,20,81,38,95,84,99,12,79,44,26,87,96,10,48,80,1,31,16,92};

        printf("Choose List Option:\n");
        printf("1. Use List 1\n");
        printf("2. Use List 2\n");
        printf("3. Use List 3\n");
        printf("4. Enter Custom List\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if(choice == 0){
                printf("Exiting...\n");
                return 0;
            }
        int a[20];
        if(choice==1){
            n=20;
            copy(a, L1, n);
        }else if(choice==2){
            n=20;
            copy(a, L2, n);
        }else if(choice ==3){
            n=20;
            copy(a,L3,n);
        }else if(choice == 4){
            printf("Enter size of list: ");
            scanf("%d", &n);
            printf("Enter %d elements: \n", n);
            for(int i=0; i<n; i++){
                scanf("%d", &a[i]);
            }
        }else{
            printf("INVALID CHOICE\n");
            return 0;
        }

        printf("\nChoose Sorting Technique:\n");
        printf("1. Insertion Sort (default)\n");
        printf("2. Insertion Sort (avoid swap)\n");
        printf("3. Bubble Sort (default)\n");
        printf("4. Bubble Sort (avoid swap)\n");
        printf("5. Flagged Bubble Sort\n");
        printf("6. Range-Limiting Bubble Sort\n");
        printf("7. Alternating Bubble Sort\n");
        printf("8. Merge Sort\n");
        printf("9. Quick Sort (median of three)\n");
        printf("Enter choice: ");
        scanf("%d", &sort_choice);
        
        switch(sort_choice) {
            case 1: default_insertion(a, n); break;
            case 2: insertion(a, n); break;
            case 3: bubble_default(a, n); break;
            case 4: bubble_avoid_swap(a, n); break;
            case 5: bubble_flagged(a, n); break;
            case 6: bubble_range_limit(a, n); break;
            case 7: bubble_alternating(a, n); break;
            case 8: exchanges = 0; mergesort(a, 0, n-1); break;
            case 9: exchanges = 0; quick_sort(a, 0, n-1); break;
            default: printf("Invalid choice\n"); return 0;
        }
        printf("\nSorted List:\n");
        print_array(a, n);

        printf("Exchanges: %d\n", exchanges);
    }


    return 0;
}