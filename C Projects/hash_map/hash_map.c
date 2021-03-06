// This file implements a hashmap structure.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// All pointers should not be NULL.

struct hash_node {
    int val;
    struct hash_node *next; 
};


struct hash_map {
    int size;
    struct hash_node *table;
};


// hash_func(hashmap, value) calculates and returns
//   a hash number
// time; O(1)
static int hash_func(struct hash_map *hashmap, int value) {
    assert(hashmap);
    return abs(value) % hashmap->size;
}


// create_hash_map(nums) creates and returns a new hash map
// time: O(n) where n is the length of nums
struct hash_map *create_hash_map(int *nums, int length) {
    assert(nums);
    struct hash_map *hashmap = malloc(sizeof(struct hash_map));
    hashmap->size = 7;
    hashmap->table = malloc(sizeof(struct hash_node) * hashmap->size);

    for(int i = 0; i < hashmap->size; i++) {
        hashmap->table[i].val= INT_MIN;
        hashmap->table[i].next = NULL;
    }

    for (int i = 0; i < length; i++) {
        int pos = hash_func(hashmap, nums[i]);
        if (hashmap->table[pos].val == INT_MIN){
            hashmap->table[pos].val = nums[i];
        } else {
            // collision occurs 
            struct hash_node *lnode = malloc(sizeof(struct hash_node));
            lnode->val = nums[i];
            lnode->next = NULL;
            struct hash_node *hashnode = &(hashmap->table[pos]);
            while(hashnode->next != NULL){
                hashnode = hashnode->next;
            }
            hashnode->next = lnode;
        }
    }
    return hashmap;
}


// in(hash_map, value) determines whether value is in hashmap
// time: O(n) 
bool in(struct hash_map *hashmap, int value){
    assert(hashmap);
    int pos = hash_func(hashmap, value);
    struct hash_node *pointer = &(hashmap->table[pos]);
    while(pointer != NULL){
        if(pointer->val == value)
            return true;
        else
            pointer=pointer->next;
    }
    return false;
}


// insert(hashmap, value) add a new value n hashmap
// time: O(1) 
int add(struct hash_map *hashmap, int value) {
    assert(hashmap);
    int pos = hash_func(hashmap, value);
    struct hash_node *pointer = &(hashmap->table[pos]);
    if (pointer->val == INT_MIN) {
        pointer->val = value;
    }	 else {
        while(pointer->next != NULL)
            pointer = pointer->next;
        struct hash_node *hnode = malloc(sizeof(struct hash_node));
        hnode->val = value;
        hnode->next = NULL;
        pointer->next = hnode;
    } 
    return 1;
}


// print_hash_map(hashmap) prints all the values
//    stored in hashmap
// time: O(n)
void print_hash_map(struct hash_map *hashmap){
    assert(hashmap);
    printf("===========PrintHashMap==========\n");
    int i = 0;
    struct hash_node *pointer;
    while (i < hashmap->size) {
        pointer = &(hashmap->table[i]);
        while (pointer != NULL){
            if (pointer->val != INT_MIN)
                printf("%d--->", pointer->val);
            else 
                printf("[ ]");
            pointer = pointer->next;
        }
        printf("\n---------------------------------\n");
        i++;
    }
    printf("===============End===============\n");
}


// destroy_hash_map(hashmap) destroys the hashmap
// effect: free the resources that hashmap used
// time: O(n) where n is the elements in hashmap
void destory_hash_map(struct hash_map *hashmap){
    assert(hashmap);
    struct hash_node *hpointer;
    for (int i = 0; i < hashmap->size; i++){
        hpointer = hashmap->table[i].next;
        while (hpointer != NULL){

            hashmap->table[i].next = hpointer->next;
            free(hpointer);
            hpointer = hashmap->table[i].next;
        }
    }
    free(hashmap->table);
    free(hashmap);
    printf("Destory hashmap Success!\n");
}


int main(void)
{
    int nums[] = {34,54,32,31,56,78};
    struct hash_map *hashmap = create_hash_map(nums, 6);
    add(hashmap, 123);
    print_hash_map(hashmap);
    printf("%d\n", in(hashmap, 123));

    destory_hash_map(hashmap);
    return 0;
}
