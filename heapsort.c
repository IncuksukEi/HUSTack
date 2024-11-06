#include<stdio.h>
#include<stdlib.h>
#define TOP(n)  ((n/2)-1)
#define LC(r) ((r) * 2 + 1)
#define RC(r) ((r) * 2 + 2)

typedef int vec_elem_t;

#define VSWAP(x,y) \
{\
    vec_elm_t ___tmp = x; \
    x = y ; \
    y = ___tmp; \
} 

struct vector {
  int sz;
  int cap;
  vec_elem_t *elems;
};

void shift_down(vec_elem_t *a,int n,int r, int (*order)(const void*,const  void*)){
    do {
        int lc = LC(r), rc = RC(r);
        int tmp = order(a + lc, a + rc)? lc:rc;
        if(lc < n){
            tmp = lc;
            if(rc < n && !order(a+lc, a+ rc)){
                tmp = rc;
        }
        }
        if(tmp < 0 || !order(a+r,a+tmp)){
            break;
        }
            VSWAP(a[r],a[tmp]);
            r=tmp;
            
    } while (r > 0) ;
}
void vsort(struct vector *v, int (*order)(const void *, const void *)) {
    for(int i = TOP(v->sz); i >= 0;i--){
        shift_down(v-elems,v->sz,i,order);
    }
}

void heaptify(vec_elem_t , int (*order)(const void *, const void *)) {
    for(int i = TOP(v->sz); i >= 0;i--){
        shift_down(v-elem,v->sz,i,order);
    }
}
int lesser(const void *p1, const void *p2) {
    const vec_elem_t *v1 = p1, *v2 = p2;
    if(*v1 <= *v2){
        return 1;
    }
    return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

}