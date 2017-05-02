#include <stdio.h>

int main() {
    int n = 0;
    int arr[100000] = { 0 };
    int thisSum = 0;
    int maxSum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);

    for (int i = 0; i < n; i++) {
        thisSum += arr[i];
        if (thisSum > maxSum) {
            maxSum = thisSum;
        }
        else if (thisSum < 0) {
            thisSum = 0;
        }
    }
    printf("%d", maxSum);
}