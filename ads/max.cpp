#include<stdio.h>
#define SIZE 100

int maxHeap[SIZE];
int maxSize = 0;

void insertMax(int value){
    int i = maxSize++;
    maxHeap[i] = value;

    while(i != 0 && maxHeap[(i-1)/2] < maxHeap[i]){
        int temp = maxHeap[i];
        maxHeap[i] = maxHeap[(i-1)/2];
        maxHeap[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

void deleteMax(){
    if(maxSize <= 0){
        printf("Max Heap is empty\n");
        return;
    }

    printf("Deleted element: %d\n", maxHeap[0]);

    maxHeap[0] = maxHeap[--maxSize];

    int i = 0;
    while(1){
        int left = 2*i+1, right = 2*i+2, largest = i;

        if(left < maxSize && maxHeap[left] > maxHeap[largest])
            largest = left;

        if(right < maxSize && maxHeap[right] > maxHeap[largest])
            largest = right;

        if(largest != i){
            int temp = maxHeap[i];
            maxHeap[i] = maxHeap[largest];
            maxHeap[largest] = temp;
            i = largest;
        }
        else break;
    }
}

void displayMax(){
    printf("Max Heap: ");
    for(int i = 0; i < maxSize; i++)
        printf("%d ", maxHeap[i]);
    printf("\n");
}

int main(){
    int choice, value;

    while(1){
        printf("\n--- MAX HEAP MENU ---\n");
        printf("1 Insert\n2 Delete\n3 Display\n4 Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                scanf("%d",&value);
                insertMax(value);
                break;

            case 2:
                deleteMax();
                break;

            case 3:
                displayMax();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
