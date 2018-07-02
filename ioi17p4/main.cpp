#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"prize.h"

const static int MAX_QUERY = 10000;

static int N;
static int* data;
static int** query;
static int query_used = 0;

int* ask(int i){
    assert(0 <= i && i < N);
    query_used++;
    if(query_used > MAX_QUERY){
        printf("Query limit exceeded\n");
        exit(0);
    }
    int* retv = (int*) malloc(sizeof(int) * 2);
    retv[0] = query[i][0];
    retv[1] = query[i][1];
    return retv;
}

int main(){
    freopen("C:\\Users\\Sunny\\Downloads\\prize\\prize\\tests\\2-18.in", "r", stdin);

    assert(scanf("%i", &N) == 1);

    data = (int*) malloc(sizeof(int) * N);
    query = (int**) malloc(sizeof(int*) * N);

    int max_data = 1;
    int answer = -1;
    for(int a = 0; a < N; a++){
        assert(scanf("%i", data + a) == 1);
//       printf("%d\n", data[a]);
        if(data[a]<5){
            printf("v[%d]=%d\n", a, data[a]);
        }
        assert(data[a] >= 1);
        query[a] = (int*) malloc(sizeof(int) * 2);
        if(data[a] == 1){
            assert(answer == -1); //duplicate answer
            answer = a;
        }
        if(data[a] > max_data){
            max_data = data[a];
        }
    }
    assert(answer != -1); //missing answer
    for(int cost = max_data; cost >= 1; cost--){
        int num_better = 0;
        for(int a = 0; a < N; a++){
            if(data[a] < cost){
                num_better++;
            } else if (data[a] == cost){
                query[a][0] = num_better;
            }
        }
        num_better = 0;
        for(int a = N - 1; a >= 0; a--){
            if(data[a] < cost){
                num_better++;
            } else if (data[a] == cost){
                query[a][1] = num_better;
            }
        }
    }
    int user_answer = find_best(N);
    if(user_answer == answer){
        printf("AC\n");
    } else {
        printf("WA %d\n", answer);
    }
    printf("Used %i queries\n", query_used);
}
