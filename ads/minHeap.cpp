#include<stdio.h>

#define SIZE 100

int minHeap[SIZE];
int minSize = 0;

void insertMin(int value){
    int i = minSize++;
    minHeap[i] = value;

    while(i != 0 && minHeap[(i-1)/2] > minHeap[i]){
        int temp = minHeap[i];
        minHeap[i] = minHeap[(i-1)/2];
        minHeap[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

void deleteMin(){
    if(minSize <= 0){
        printf("Min Heap is empty\n");
        return;
    }

    printf("Deleted element: %d\n", minHeap[0]);

    minHeap[0] = minHeap[--minSize];

    int i = 0;
    while(1){
        int left = 2*i+1, right = 2*i+2, smallest = i;

        if(left < minSize && minHeap[left] < minHeap[smallest])
            smallest = left;

        if(right < minSize && minHeap[right] < minHeap[smallest])
            smallest = right;

        if(smallest != i){
            int temp = minHeap[i];
            minHeap[i] = minHeap[smallest];
            minHeap[smallest] = temp;
            i = smallest;
        }
        else break;
    }
}

void displayMin(){
    printf("Min Heap: ");
    for(int i = 0; i < minSize; i++)
        printf("%d ", minHeap[i]);
    printf("\n");
}

int main(){
    int choice, value;

    while(1){
        printf("\n--- MIN HEAP MENU ---\n");
        printf("1 Insert\n2 Delete\n3 Display\n4 Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                scanf("%d",&value);
                insertMin(value);
                break;

            case 2:
                deleteMin();
                break;

            case 3:
                displayMin();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
