#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SFOR(cur, list ) \
    for(struct snode *cur = list -> head; cur != NULL; cur =cur -> next)

typedef int slist_elem_t;

struct snode{
    slist_elem_t data;
    struct snode *next;
};

struct slist{
    struct snode *head, *tail;
    int len;
};

struct snode *snode (slist_elem_t elem){
    struct snode *nn=malloc(sizeof(struct snode));
    nn->data = elem;
    nn->next = NULL;
    return nn;
};

struct slist *screate(){
    struct slist *list= malloc (sizeof(struct slist));
    list->len=0;
    list->head = list -> tail = NULL;
    return list; 
}

struct slist *sappend(struct slist *list, slist_elem_t elem){
    struct snode *nn = snode(elem);
    if(list -> tail == NULL){
        list -> head = list -> tail = nn;
        list -> len = 1;
        return list;
    }
    list -> tail -> next = nn;
    list -> tail =nn;
    list -> len += 1;
    return list;
}

struct slist *sprepend(struct slist *list, slist_elem_t elem){
    struct snode *nn = snode(elem);
    if(list -> head == NULL){
        list -> head = list -> tail = nn;
        list -> len = 1;
    }
    nn -> next = list -> head;
    list -> head = nn ;
    list -> len +=1;
    return list;
}

struct slist *sdelh(struct slist *list){
    //if (list->head != NULL) { // Kiểm tra head != NULL
        struct snode *tmp = list->head->next;
        free(list->head);
        list->head = tmp;
        list->len -= 1;
        if (list->len == 0) {
            list->tail = NULL;
        }
    //}
    return list;
}

void sdel (struct slist *list){
    struct snode *n = list -> head;
    while (n){
        struct snode *tmp = n -> next;
        free(n);
        n = tmp;
    }
    free (list);
}

void slist_printf(struct slist *list){
    printf("len: %d\n",list -> len);
    SFOR(n,list){
        printf("%d ", n->data);
    }
    printf("\n");
}

int main(){
    struct slist *list = screate ();
    int tmp;
    while(scanf("%d", &tmp) == 1 && tmp > 0){
        if(tmp == 1){
            sdelh(list);
            slist_printf(list);
        }else if(tmp<10){
            sprepend(list,tmp);
            slist_printf(list);
            continue;
        }else {
            sappend(list,tmp);
            slist_printf(list);
        }
    }
    sdel(list);
}