#include<stdio.h>
#include<stdlib.h>

#define TABLE_SIZE 11

typedef struct Node{
    int key;
    struct Node* next;
} Node;

Node* chaining_table[TABLE_SIZE];

void init_chaining(){
    for(int i = 0; i < TABLE_SIZE; i++){
        chaining_table[i] = NULL;
    }
}

int hash_fn(int key){
    int h = key % TABLE_SIZE;
    if(h < 0) h += TABLE_SIZE;
    return h;
}

void chaining_insert(int key){
    int index = hash_fn(key);

    Node* newnode = (Node*)malloc(sizeof(Node));
    if(!newnode){
        printf("Memory allocation failed\n");
        return;
    }

    newnode->key = key;
    newnode->next = chaining_table[index];
    chaining_table[index] = newnode;

    printf("Inserted %d at index %d\n", key, index);
}

int chaining_search(int key){
    int index = hash_fn(key);
    Node* curr = chaining_table[index];

    while(curr){
        if(curr->key == key)
            return 1;
        curr = curr->next;
    }
    return 0;
}

void chaining_delete(int key){
    int index = hash_fn(key);

    Node* curr = chaining_table[index];
    Node* prev = NULL;

    while(curr){
        if(curr->key == key){
            if(prev == NULL)
                chaining_table[index] = curr->next;
            else
                prev->next = curr->next;

            free(curr);
            printf("Deleted %d at index %d\n", key, index);
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    printf("Element not found\n");
}

void chaining_display(){
    for(int i = 0; i < TABLE_SIZE; i++){
        printf("[%d]", i);
        Node* curr = chaining_table[i];

        while(curr){
            printf(" -> %d", curr->key);
            curr = curr->next;
        }
        printf(" -> NULL\n");
    }
}

int main(){
    int ch, key;

    init_chaining();

    while(1){
        printf("\n1.Insert 2.Search 3.Delete 4.Display 0.Exit\n");
        scanf("%d", &ch);

        if(ch == 0) break;

        if(ch == 1){
            scanf("%d", &key);
            chaining_insert(key);
        }
        else if(ch == 2){
            scanf("%d", &key);
            if(chaining_search(key))
                printf("Found\n");
            else
                printf("Not Found\n");
        }
        else if(ch == 3){
            scanf("%d", &key);
            chaining_delete(key);
        }
        else if(ch == 4){
            chaining_display();
        }
    }

    return 0;
}
