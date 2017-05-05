#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int next;
};

int q1[100005];
int q2[100005];
int q1_size = 0;
int q2_size = 0;

void enqueue(int address, int q) {
    if (q == 1) {
        q1[q1_size] = address;
        q1_size++;
    }
    if (q == 2) {
        q2[q2_size] = address;
        q2_size++;
    }
}

int stack[100005];
int stack_size = 0;

void push(int address) {
    stack[stack_size] = address;
    stack_size++;
}

int pop() {
    int result = stack[stack_size - 1];
    stack_size--;
    return result;
}

int main() {
    int start, total, reverse;
    struct node arr[100000] = { -1,-1 };

    scanf("%d %d %d", &start, &total, &reverse);

    int tmp_address, tmp_data, tmp_next;

    for (int i = 0; i < total; i++) {
        scanf("%d %d %d", &tmp_address, &tmp_data, &tmp_next);
        arr[tmp_address].data = tmp_data;
        arr[tmp_address].next = tmp_next;
    }

    tmp_address = start;
    int size = 0;
    while (tmp_address != -1) {
        enqueue(tmp_address, 1);
        tmp_address = arr[tmp_address].next;
        size++;
    }

    for (int i = 0; i < size; i++) {
        push(q1[i]);
        if (stack_size < reverse)
            continue;
        while (stack_size != 0) {
            enqueue(pop(), 2);
        }
    }

    for (int i = 0; i < stack_size; i++) {
        enqueue(stack[i], 2);
    }

    for (int i = 0; i < size; i++) {
        if (i + 1 == size) {
            printf("%05d %d -1", q2[i], arr[q2[i]].data);
        }
        else {
            printf("%05d %d %05d\n", q2[i], arr[q2[i]].data, q2[i + 1]);
        }
    }
    return 0;
}