#ifndef __LLIST_H
#define __LLIST_H

/*
 * node is a node in a linked list
 */
struct node {
  int value;
  struct node *next;
};

/*
 * llist is a linked list
 */
struct llist {
  struct node *first;
};

/*
 * list_create() returns a new (empty) linked list
 * effects: allocates heap memory (caller must free by calling list_destroy)
 * time:    O(1)
 */
struct llist *list_create(void);

/*
 * list_destroy(list) frees the memory allocated by [list].
 * effects: deallocates [list]
 * time:    O(n), where n is the length of [list]
 */
void list_destroy(struct llist *list);

/* 
 * list_append(list, value) appends [value] to the end of [list].
 * effects: mutates [list]
 * time:    O(n), where n is the length of [list]
 */
void list_append(struct llist *list, const int value);

/*
 * list_print(list) writes out the content of [list] to standard output.
 * effects: modifies standard output
 * time:    O(n), where n is the length of [list]
 */
void list_print(const struct llist *list);

#endif // __LLIST_H

/*
 * reverse_iter(list) reverses the order of [list]. The algorithm is iterative.
 * effects: mutates [list]
 * time:    O(n), where n is the length of [list]
 */
void reverse_iter(struct llist *list);


/*
 * reverse_rec(list) reverses the order of [list]. The algorithm is recursive.
 * effects: mutates [list]
 * time:    O(n), where n is the length of [list]
 */
void reverse_rec(struct llist *list);