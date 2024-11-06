#include <stdio.h>

//node thu i co chi so trai la 2i + 1, not ben phai co chi so la 2i + 2;
//not goc la (i-1)/2
// maxheap la gia tri cua not lon hon gia tri cua con, minheap ngc lai
typedef int arr_elem_t;

void swap(arr_elem_t *a, arr_elem_t *b) {
  arr_elem_t temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(arr_elem_t *a, int n, int i){
    int l=i*2+1;
    int r=i*2+2;
    int Max = i;

    if(l < n && a[l] > a[Max]){
        Max = l;
    }

    if(r < n && a[r] > a[Max]){
        Max = r;
    }
    
    if (Max != i){
        swap(a+i,a+Max);
        heapify(a,n,Max);
    }
}

void hsort(arr_elem_t *a, int n){
    for(int i= n/2 - 1; i >=0 ; --i){
        heapify(a, n, i);
    }

    for(int i= n - 1; i > 0; --i){
        swap(a,a+i);
        heapify(a,i,0);
    }
}

void hprintf(arr_elem_t *a, int n){
    for(int i=0; i<n ; ++i){
        printf("%d ",*(a+i));
    }
    printf("\n");
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];

    for(int i = 0 ; i < n ; ++i ){
        scanf("%d",(a+i));
    }
    hsort(a,n);
    hprintf(a,n);
}