#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define VFOR(cur, v) for (vec_elem_t* cur = \
     (v)->elems; cur < (v)->elems + (v)->sz; ++cur)
 
typedef int vec_elem_t;

struct vector{
    int sz;
    int cap;
    vec_elem_t *elems;
};

struct vector *vcreate(int n){
    struct vector *v = malloc(sizeof(struct vector));
    v->sz = n;
    v->cap = v->sz > 0 ? v->sz : 8;
    v-> elems= calloc(v->cap,sizeof(int));
    return v;
}

void vreserve(struct vector *v, int newcap){
    if(newcap <= v-> sz){
        return;
    }
    v->elems = realloc(v->elems,newcap*sizeof(vec_elem_t));
        v->elems = realloc(v->elems, newcap * sizeof(vec_elem_t));
    if (v->cap < newcap) {
        memset(v->elems + v-> cap,0, \
            sizeof(vec_elem_t)*(newcap - v->cap));
    }
    v->cap = newcap;
}

void vappend(struct vector *v, int value){
    if(v->cap == 0){
        vreserve(v,16);
    }else if (v->sz == v->cap){
        vreserve(v, 2*v-> cap);
    }
    v->elems[v->sz] = value;
    v->sz++;
}

void vresize(struct vector *v,int newsize){
    if(newsize > v->cap){
        vreserve(v,newsize);
    }
    v->sz= newsize;
}

void vfree(struct vector *v){
    if(!v){
        return;
    }
    free(v->elems);
    free(v);
}
int main(){

}