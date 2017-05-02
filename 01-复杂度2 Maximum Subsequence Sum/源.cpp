#include <stdio.h>

int main() {
    int n = 0;
    int arr[100000] = { 0 };
    int thisSum = 0;
    int maxSum = 0;
    int left = 0;
    int newLeft = 0;
    int right = 0;
    int flag = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);

    for (int i = 0; i < n; i++) {
        thisSum += arr[i];
        if (thisSum > maxSum) {
            maxSum = thisSum;
            left = newLeft;
            right = i;
            flag = 1;
        }
        else if (thisSum < 0) {
            newLeft = i + 1;
            thisSum = 0;
        }
        else if (thisSum == 0) {
            if (flag == 0) {
                left = i;
                right = i;
                flag = 1;
            }
        }
    }
    if (flag == 0) right = n - 1;
    printf("%d %d %d", maxSum, arr[left], arr[right]);
}