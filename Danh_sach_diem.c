#include <stdio.h>
#include <stdlib.h>

typedef int slist_elem_t;
struct snode {
  slist_elem_t data;
  struct snode *next;
};

struct slist {
  struct snode *head, *tail;
  int len;
};

struct snode *snode(slist_elem_t elem) {
  struct snode *nn = malloc(sizeof(struct snode));
  nn->data = elem;
  nn->next = NULL;
  return nn;
}

#define SFOR(cur, list) \
  for (struct snode *cur = list->head; cur != NULL; cur = cur->next)

struct slist *slist() {
  struct slist *list = malloc(sizeof(struct slist));
  list->len = 0;
  list->head = list->tail = NULL;
  return list;
}

void sdel(struct slist *list) {
  struct snode *n = list->head;
  while (n) {
    struct snode *tmp = n->next;
    free(n);
    n = tmp;
  }
  free(list);
}

struct slist *sappend(struct slist *list, slist_elem_t elem) {
  struct snode *nn = snode(elem);
  if (list->tail == NULL) {
    list->head = list->tail = nn;
    list->len = 1;
    return list;
  }
  list->tail->next = nn;
  list->tail = nn;
  list->len += 1;
  return list;
}

struct slist *sprepend(struct slist *list, slist_elem_t elem) {
  struct snode *nn = snode(elem);
  if (list->head == NULL) {
    list->head = list->tail = nn;
    list->len = 1;
    return list;
  }
  nn->next = list->head;
  list->head = nn;
  list->len += 1;
  return list;
}

struct slist *sdelh(struct slist *list) {
  /* Người dùng phải kiểm tra điều kiện head != NULL */
  struct snode *tmp = list->head->next;
  free(list->head);
  list->head = tmp;
  list->len -= 1;
  if (list->len == 0) {
    list->tail = NULL;
  }
  return list;
}

struct slist *sparse_marked() {
  struct slist *list = slist();
  int elem;
  scanf("%d", &elem);
  while (elem != -1) {
    sappend(list, elem);
    scanf("%d", &elem);
  }
  return list;
}

int main() {
  struct slist *list = sparse_marked();
  SFOR(cur, list) {
    printf("%d ", cur->data);
  }
  printf("\n");
  sdel(list);
  return 0;
}