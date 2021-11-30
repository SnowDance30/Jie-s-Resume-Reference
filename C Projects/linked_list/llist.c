// This module shows the implementation of linked list.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

/*
 * node_create(value) returns a new node with value set to [value].
 * effects: allocates heap memory (caller must free by calling node_destroy)
 * time:    O(1)
 */
struct node *node_create(int value) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

/*
 * node_destroy(node) frees the memory allocated by [node].
 * effects: deallocates [node]
 * time:    O(1)
 */
void node_destory(struct node* node) {
  assert(node);
  free(node);
}

// see "list.h" file for documentation
struct llist *list_create(void) {
  struct llist *list = malloc(sizeof(struct llist));
  list->first = NULL;
  return list;
}

// see "list.h" file for documentation
void list_destroy(struct llist *list) {
  assert(list);
  struct node *current = list->first;
  while (current != NULL) { // travers nodes
    struct node *to_free = current;
    current = current->next;
    node_destory(to_free);
  }
  free(list);
}

// see "list.h" file for documentation
void list_append(struct llist *list, const int value) {
  assert(list);
  struct node *new_node = node_create(value);
  if (list->first == NULL) { // list is empty
    list->first = new_node;
  } else {
    struct node *current = list->first;
    while (current->next != NULL) { // find last node
      current = current->next;
    }
    current->next = new_node;
  }
}

// see "list.h" file for documentation
void list_print(const struct llist *list) {
  assert(list);
  struct node *current = list->first;
  if (current == NULL) { // list is empty
    printf("List empty\n");
  } else {
    int i = 0;
    while(current != NULL) { // travers nodes
      printf("Node #%d: %d\n", i++, current->value);
      current = current->next;
    }
  }
}

// see "list.h" file for documentation
void reverse_iter(struct llist *list) {
  assert(list);
  struct node *node_pre = NULL;
  struct node *node_cur = NULL;
  struct node *node_nex = NULL;

  if (list->first) {
    node_pre = list->first;
    if (node_pre->next) {
      node_nex = node_pre->next;
      node_pre->next = NULL;
      while (node_nex->next) {
        node_cur = node_nex->next;
        node_nex->next = node_pre;
        node_pre = node_nex;
        node_nex = node_cur;
      }
      node_nex->next = node_pre;
      list->first = node_nex;
    }
  }
}

// rev_rec_node(node, list) reverses the nodes in list and return node
// requires: list is not NULL pointer
// time: O(n) where n is the number of nodes in list
struct node *rev_rec_node(struct node *node, struct llist *list) {
  assert(list);
  if (node->next == NULL) {
    list->first = node;
    return node;
  } else {
    rev_rec_node(node->next, list)->next = node;
    return node;
  }
}



// see "list.h" file for documentation
void reverse_rec(struct llist *list) {
  assert(list);
  if (list->first != NULL) {
    rev_rec_node(list->first, list)->next = NULL;
  }
}