typedef struct hashMap{
    int key;
    int value;
    struct hashMap* next;
} map;


#define tableSize 1000

int hash(int key){
     int prime = 31;
    long int hashValue = 0;

    while (key != 0) {
        int digit = key % 10;
        key /= 10;
        hashValue = (hashValue * prime) + digit;
    }

    return (hashValue % tableSize + tableSize) % tableSize;
}

void insert(map* Table, int key, int value){
    int index = hash(key);
    map* newVal = (map*)malloc(sizeof(map));
    newVal -> key = key;
    newVal -> value = value;
    newVal -> next = Table[index].next;
    Table[index].next = newVal;
}

int get(map* Table, int key){
    int index = hash(key);
    map* current = Table[index].next;
    while(current){
        if(current->key == key){
            return current -> value;
        }
        current = current -> next;
    }
    return (-1);
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    map* table;
    table = (map*)calloc(tableSize, sizeof(map));

     for(int i = 0; i < numsSize; i++){
        int ref = target - nums[i];
        int ret = get(table,ref);
        if(ret != -1){
            int * result = malloc(sizeof(int) * 2);
            result[0] = ret;
            result[1] = i;
            *returnSize = 2;
            return result;
        }
        insert(table, nums[i], i);
    }
free(table);
    return NULL;
}
