#include<stdio.h>
#include<limits.h>

#define TABLE_SIZE 11
#define EMPTY_SLOT INT_MIN
#define DELETED_SLOT (INT_MIN + 1)

int oa_table[TABLE_SIZE];

void init(){
    for(int i = 0; i < TABLE_SIZE; i++){
        oa_table[i] = EMPTY_SLOT;
    }
}

int hash_fn(int key){
    int h = key % TABLE_SIZE;
    if(h < 0) h += TABLE_SIZE;
    return h;
}

int linear_insert(int key){
    int index = hash_fn(key);

    for(int i = 0; i < TABLE_SIZE; i++){
        int pos = (index + i) % TABLE_SIZE;

        if(oa_table[pos] == EMPTY_SLOT || oa_table[pos] == DELETED_SLOT){
            oa_table[pos] = key;
            printf("Inserted %d at index %d (Linear)\n", key, pos);
            return 1;
        }
    }

    printf("Table Full (Linear)\n");
    return -1;
}

int linear_search(int key){
    int index = hash_fn(key);

    for(int i = 0; i < TABLE_SIZE; i++){
        int pos = (index + i) % TABLE_SIZE;

        if(oa_table[pos] == EMPTY_SLOT)
            return -1;

        if(oa_table[pos] == key)
            return pos;
    }

    return -1;
}

int linear_delete(int key){
    int pos = linear_search(key);

    if(pos == -1){
        printf("Not Found (Linear)\n");
        return -1;
    }

    oa_table[pos] = DELETED_SLOT;
    printf("Deleted %d from index %d (Linear)\n", key, pos);
    return 1;
}

int quadratic_insert(int key){
    int index = hash_fn(key);

    for(int i = 0; i < TABLE_SIZE; i++){
        int pos = (index + i*i) % TABLE_SIZE;

        if(oa_table[pos] == EMPTY_SLOT || oa_table[pos] == DELETED_SLOT){
            oa_table[pos] = key;
            printf("Inserted %d at index %d (Quadratic)\n", key, pos);
            return 1;
        }
    }

    printf("Table Full (Quadratic)\n");
    return -1;
}

int quadratic_search(int key){
    int index = hash_fn(key);

    for(int i = 0; i < TABLE_SIZE; i++){
        int pos = (index + i*i) % TABLE_SIZE;

        if(oa_table[pos] == EMPTY_SLOT)
            return -1;

        if(oa_table[pos] == key)
            return pos;
    }

    return -1;
}

int quadratic_delete(int key){
    int pos = quadratic_search(key);

    if(pos == -1){
        printf("Not Found (Quadratic)\n");
        return -1;
    }

    oa_table[pos] = DELETED_SLOT;
    printf("Deleted %d from index %d (Quadratic)\n", key, pos);
    return 1;
}

void display(){
    for(int i = 0; i < TABLE_SIZE; i++){
        if(oa_table[i] == EMPTY_SLOT)
            printf("[%d] : EMPTY\n", i);
        else if(oa_table[i] == DELETED_SLOT)
            printf("[%d] : DELETED\n", i);
        else
            printf("[%d] : %d\n", i, oa_table[i]);
    }
}

int main(){
    int choice, ch, key;

    while(1){
        printf("\n1.Linear 2.Quadratic 0.Exit\n");
        scanf("%d", &choice);

        if(choice == 0) break;

        init();

        while(1){
            printf("\n1.Insert 2.Search 3.Delete 4.Display 0.Back\n");
            scanf("%d", &ch);

            if(ch == 0) break;

            if(choice == 1){
                if(ch == 1){
                    scanf("%d", &key);
                    linear_insert(key);
                }
                else if(ch == 2){
                    scanf("%d", &key);
                    int pos = linear_search(key);
                    if(pos == -1) printf("Not Found\n");
                    else printf("Found at %d\n", pos);
                }
                else if(ch == 3){
                    scanf("%d", &key);
                    linear_delete(key);
                }
                else if(ch == 4){
                    display();
                }
            }

            else if(choice == 2){
                if(ch == 1){
                    scanf("%d", &key);
                    quadratic_insert(key);
                }
                else if(ch == 2){
                    scanf("%d", &key);
                    int pos = quadratic_search(key);
                    if(pos == -1) printf("Not Found\n");
                    else printf("Found at %d\n", pos);
                }
                else if(ch == 3){
                    scanf("%d", &key);
                    quadratic_delete(key);
                }
                else if(ch == 4){
                    display();
                }
            }
        }
    }

    return 0;
}
