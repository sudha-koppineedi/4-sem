#include<stdio.h>
#define SIZE 100

void merge(int arr[], int start, int mid, int end){
    int i, j, k;

    int n1 = mid - start + 1;
    int n2 = end - mid;

    int l[SIZE], r[SIZE];

    // copy left
    for(i = 0; i < n1; i++){
        l[i] = arr[start + i];
    }

    // copy right
    for(j = 0; j < n2; j++){
        r[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = start;

    // merge
    while(i < n1 && j < n2){
        if(l[i] <= r[j]){
            arr[k] = l[i];
            i++;
        }
        else{
            arr[k] = r[j];
            j++;
        }
        k++;
    }

    // remaining left
    while(i < n1){
        arr[k] = l[i];
        i++;
        k++;
    }

    // remaining right
    while(j < n2){
        arr[k] = r[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int start, int end){
    if(start < end){
        int mid = (start + end) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }
}

int main(){
    int arr[SIZE], n;

    printf("Enter no.of elements: ");
    scanf("%d", &n);

    printf("Elements of array:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
