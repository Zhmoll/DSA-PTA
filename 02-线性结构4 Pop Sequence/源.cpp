#include <stdio.h>
#include <stdlib.h>


int stack[1001] = { 0 };
int stack_size;

void push(int a) {
    stack[stack_size] = a;
    stack_size++;
}

int pop() {
    return stack[--stack_size];
}

int top() {
    return stack[stack_size - 1];
}

int main() {
    int max_stack_size;
    int N;
    int total;
    int seq[1001] = { 0 };

    scanf("%d %d %d", &max_stack_size, &N, &total);

    for (int i = 0; i < total; i++) {
        // ¶ÁÈ¡ÐòÁÐ
        for (int j = 0; j < N; j++) {
            scanf("%d", &seq[j]);
        }

        stack_size = 0;
        int expected = 0;
        int current = 1;
        while (current <= N && stack_size < max_stack_size) {
            push(current);
            current++;

            while (stack_size != 0 && seq[expected] == top()) {
                pop();
                expected++;
            }

        }
        if (stack_size == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}