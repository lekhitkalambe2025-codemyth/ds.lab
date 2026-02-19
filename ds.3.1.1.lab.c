#include <stdio.h>

void mergeArray(int a[], int start, int mid, int end) {
    int i, j, k;
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int leftArr[n1], rightArr[n2];

    for(i = 0; i < n1; i++)
        leftArr[i] = a[start + i];

    for(j = 0; j < n2; j++)
        rightArr[j] = a[mid + 1 + j];

    i = 0;
    j = 0;
    k = start;

    while(i < n1 && j < n2) {
        if(leftArr[i] <= rightArr[j]) {
            a[k] = leftArr[i];
            i++;
        } else {
            a[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        a[k] = leftArr[i];
        i++;
        k++;
    }

    while(j < n2) {
        a[k] = rightArr[j];
        j++;
        k++;
    }
}

void sortMerge(int a[], int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;

        sortMerge(a, start, mid);
        sortMerge(a, mid + 1, end);
        mergeArray(a, start, mid, end);
    }
}

void display(int a[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    display(a, n);         
    sortMerge(a, 0, n - 1); 
    display(a, n);  

    return 0;
}
