#include <stdbool.h>

struct hash_node;
struct hash_map;

struct hash_map *create_hash_map(int *nums, int length);

bool in(struct hash_map *hashmap, int value);

int add(struct hash_map *hashmap, int value);

void print_hash_map(struct hash_map *hashmap);

void destory_hash_map(struct hash_map *hashmap);
