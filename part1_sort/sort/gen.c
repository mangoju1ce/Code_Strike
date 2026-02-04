#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000   // 修改这里控制规模,最大100000

int main() {
    srand(time(NULL));
    printf("%d\n", N);
    for(int i = 0; i < N; i++) {
        printf("%d ", rand());
    }
    return 0;
}
