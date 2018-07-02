#include "towns.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "graderlib.c"

int main() {
    FILE *f;
    f = freopen("C:\\Users\\Sunny\\Downloads\\towns\\towns\\tests\\subtask_3\\01","r",stdin);
    assert(f != NULL);
    int ncase, R, N;
    int subtask;
    int ret;
    ret = scanf("%d%d",&subtask,&ncase);
    assert(ret == 2);
    for (int i = 0; i < ncase; i++) {
        ret = scanf("%d",&N);
	assert(ret == 1);
        _ini_query(N,subtask);
        R=hubDistance(N,subtask);
            printf("quota use: %d/%d\n", _user_query, _quota);
        printf("%d\n",R);
    }
//            while(true){
//            int a,b;scanf("%d %d", &a, &b);
//            printf("%d\n", getDistance(a,b));
//        }
    return 0;
}
