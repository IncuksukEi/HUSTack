#include <stdio.h>
#include <string.h>

typedef int vec_elem_t;

void set0(int *s, int vt, int n) { 
    for (int i = vt; i < n; ++i) {
        s[i] = 0;
    }
}

void Sinh(int n) {
    int s[n] ;
    set0(s, 0, n); 
    for (int i = 0; i < n; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");
    int i = n - 1;
    while (i >= 0) {
        if (s[i] == 1) {
            --i;
        } else {
            s[i] = 1;
            set0(s, i + 1, n); 
            for (int j = 0; j < n; j++) {
                printf("%d ", s[j]);
            }
            printf("\n");
            i = n - 1; 
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Sinh(n);
    return 0;
}