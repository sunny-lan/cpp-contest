#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include"factories.h"

int main(){
    freopen("C:\\Users\\Sunny\\Downloads\\factories-data\\factories-data\\in\\03-10.txt", "r", stdin);

    int N, Q;
    assert(scanf("%i %i", &N, &Q) == 2);
    int *A = (int*)malloc(sizeof(int) * (N - 1));
    int *B = (int*)malloc(sizeof(int) * (N - 1));
    int *D = (int*)malloc(sizeof(int) * (N - 1));
    for(int a = 0; a < N - 1; a++){
        assert(scanf("%i %i %i", A + a, B + a, D + a) == 3);
    }
    printf("begin init\n");
    Init(N, A, B, D);
    printf("done init\n");
    for(int a = 0; a < Q; a++){
        int S, T;
        assert(scanf("%i %i", &S, &T) == 2);
        int *X = (int*)malloc(sizeof(int) * S);
        int *Y = (int*)malloc(sizeof(int) * T);
        for(int b = 0; b < S; b++){
            assert(scanf("%i", X + b) == 1);
        }
        for(int b = 0; b < T; b++){
            assert(scanf("%i", Y + b) == 1);
        }
        Query(S, X, T, Y);
        free(X);
        free(Y);
    }
    free(A);
    free(B);
    free(D);
}
