#include <stdio.h>

int main() {
    int n1, n2;
    int item1[1001] = { 0 };
    int item2[1001] = { 0 };
    int tmp1, tmp2;
    int result_mul[2002] = { 0 };
    int result_add[1001] = { 0 };
    int flag = 0;

    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d %d", &tmp1, &tmp2);
        item1[tmp2] = tmp1;
    }

    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d %d", &tmp1, &tmp2);
        item2[tmp2] = tmp1;
    }

    // ³Ë·¨
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            result_mul[i + j] += item1[i] * item2[j];
        }
    }
    // ¼Ó·¨
    for (int i = 0; i < 1001; i++) {
        result_add[i] = item1[i] + item2[i];
    }

    for (int i = 2001; i >=0; i--) {
        if (result_mul[i] != 0) {
            if (flag == 1) {
                printf(" ");
            }
            printf("%d %d", result_mul[i], i);
            flag = 1;
        }
    }
    if (flag == 0) {
        printf("0 0");
    }
    printf("\n");
    flag = 0;
    for (int i = 1000; i >= 0; i--) {
        if (result_add[i] != 0) {
            if (flag == 1) {
                printf(" ");
            }
            printf("%d %d", result_add[i], i);
            flag = 1;
        }
    }
    if (flag == 0) {
        printf("0 0");
    }
    return 0;
}