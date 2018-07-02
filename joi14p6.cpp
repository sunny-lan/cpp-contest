#define _CRT_SECURE_NO_WARNINGS
#include "secret.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N                  1000
#define MAX_Q                 10000
#define MAX_VALUE        1000000000

#define SCORE_1                 100
#define MAX_CALL_INIT_1        8000
#define MAX_CALL_QUERY_1          1

#define SCORE_2                  30
#define MAX_CALL_INIT_2        8000
#define MAX_CALL_QUERY_2         20

#define SCORE_3                   6

static int N;
static int A[MAX_N];
static int Q;
static int L[MAX_Q];
static int R[MAX_Q];

static int bits[29];
static int correct_answer[MAX_N][MAX_N];

static int secret_count;

static void SecretInit() {
  int j, p, p0, p1;
  for (p = 0; p < 29; ++p) {
    bits[p] = p;
  }
  for (j = 0; j < Q; ++j) {
    p0 = (j ^ L[j]) % 29;
    p1 = R[j] % 29;
    if (p0 != p1) {
      bits[p0] ^= bits[p1];
      bits[p1] ^= bits[p0];
      bits[p0] ^= bits[p1];
    }
  }
}

static int SecretImpl(int X, int Y) {
  int i, j, p;
  int x_sym = 0, y_sym = 0, z_sym = 0;
  int x_min = 0, y_min = 0, z_min = 0;
  int x_perm[10], y_perm[10], z_perm[10];
  int Z = 0;
  for (p = 0; p < 22; ++p) {
    x_sym |= ((X >> bits[p]) & 1) << p;
    y_sym |= ((Y >> bits[p]) & 1) << p;
  }
  for (p = 22; p < 29; ++p) {
    x_min |= ((X >> bits[p]) & 1) << (p - 22);
    y_min |= ((Y >> bits[p]) & 1) << (p - 22);
  }
  for (i = 10; i-- > 0; ) {
    x_perm[i] = x_sym % (10 - i);
    x_sym /= (10 - i);
    for (j = i + 1; j < 10; ++j) {
      if (x_perm[i] <= x_perm[j]) {
        ++x_perm[j];
      }
    }
  }
  for (i = 10; i-- > 0; ) {
    y_perm[i] = y_sym % (10 - i);
    y_sym /= (10 - i);
    for (j = i + 1; j < 10; ++j) {
      if (y_perm[i] <= y_perm[j]) {
        ++y_perm[j];
      }
    }
  }
  for (i = 0; i < 10; ++i) {
    z_perm[i] = x_perm[y_perm[i]];
  }
  for (i = 0; i < 10; ++i) {
    z_sym = z_sym * (10 - i) + z_perm[i];
    for (j = i + 1; j < 10; ++j) {
      if (z_perm[i] < z_perm[j]) {
        --z_perm[j];
      }
    }
  }
  z_min = (x_min <= y_min) ? x_min : y_min;
  for (p = 0; p < 22; ++p) {
    Z |= ((z_sym >> p) & 1) << bits[p];
  }
  for (p = 22; p < 29; ++p) {
    Z |= ((z_min >> (p - 22)) & 1) << bits[p];
  }
  if ((Z | 1 << 29) <= MAX_VALUE &&
      (((Z % 2 == 0) ? L : R)[Z / 2 % Q] & 2) != 0) {
    Z |= 1 << 29;
  }
  return Z;
}

int Secret(int X, int Y) {
  ++secret_count;
  if (!(0 <= X && X <= MAX_VALUE)) {
    fprintf(stderr, "Wrong Answer [1]\n");
    exit(0);
  }
  if (!(0 <= Y && Y <= MAX_VALUE)) {
    fprintf(stderr, "Wrong Answer [1]\n");
    exit(0);
  }
  return SecretImpl(X, Y);
}

int main() {
  int i, j;
  int secret_count_by_init;
  int max_secret_count_by_query = 0;
  int answer;

  if (1 != scanf("%d", &N)) {
    fprintf(stderr, "error: cannot read N.\n");
    exit(1);
  }
  if (!(1 <= N && N <= MAX_N)) {
    fprintf(stderr, "error: N is out of bounds.\n");
    exit(1);
  }
  for (i = 0; i < N; ++i) {
    if (1 != scanf("%d", &A[i])) {
      fprintf(stderr, "error: cannot read A[%d].\n", i);
      exit(1);
    }
    if (!(0 <= A[i] && A[i] <= MAX_VALUE)) {
      fprintf(stderr, "error: A[%d] is out of bounds.\n", i);
      exit(1);
    }
  }
  if (1 != scanf("%d", &Q)) {
    fprintf(stderr, "error: cannot read Q.\n");
    exit(1);
  }
  if (!(0 <= Q && Q <= MAX_Q)) {
    fprintf(stderr, "error: Q is out of bounds.\n");
    exit(1);
  }
  for (j = 0; j < Q; ++j) {
    if (2 != scanf("%d%d", &L[j], &R[j])) {
      fprintf(stderr, "error: cannot read L[%d] and R[%d].\n", j, j);
      exit(1);
    }
    if (!(0 <= L[j] && L[j] <= R[j] && R[j] <= N - 1)) {
      fprintf(stderr,
              "error: L[%d] and R[%d] do not satisfy the constraints.\n",
              j, j);
      exit(1);
    }
  }

  SecretInit();
  for (i = 0; i < N; ++i) {
    correct_answer[i][i] = A[i];
    for (j = i + 1; j < N; ++j) {
      correct_answer[i][j] = SecretImpl(correct_answer[i][j - 1], A[j]);
    }
  }

  secret_count = 0;
  Init(N, A);
  secret_count_by_init = secret_count;

  for (j = 0; j < Q; ++j) {
    secret_count = 0;
    answer = Query(L[j], R[j]);
    if (correct_answer[L[j]][R[j]] != answer) {
      fprintf(stderr,
              "Wrong Answer: Query(%d, %d) - expected : %d, actual : %d.\n",
              L[j], R[j], correct_answer[L[j]][R[j]], answer);
	  scanf("%d", &N);
      exit(0);
    }
    if (max_secret_count_by_query < secret_count) {
      max_secret_count_by_query = secret_count;
    }
  }

  printf("Accepted\n");
  printf("number of calls to Secret by Init : %d\n",
          secret_count_by_init);
  printf("maximum number of calls to Secret by Query : %d\n",
          max_secret_count_by_query);
  if (secret_count_by_init <= MAX_CALL_INIT_1 &&
      max_secret_count_by_query <= MAX_CALL_QUERY_1) {
    printf("score : %d\n", SCORE_1);
  } else if (secret_count_by_init <= MAX_CALL_INIT_2 &&
             max_secret_count_by_query <= MAX_CALL_QUERY_2) {
    printf("score : %d\n", SCORE_2);
  } else {
    printf("score : %d\n", SCORE_3);
  }


  return 0;
}
