#include <stdio.h>
#include <stdlib.h>

struct node {
    int address;
    int data;
    int nextAddress;
    struct node* prec;
    struct node* next;
};

struct stack {
    int size;
    struct node* top;
};

void push(struct stack* s, struct node* n) {
    if (s->top)    s->top->prec = n;
    n->next = s->top;
    n->prec = NULL;
    s->top = n;
    s->size++;
}

struct node* pop(struct stack* s) {
    struct node* tmp = s->top;
    s->top = s->top->next;
    s->size--;
    return tmp;
}

int main() {
    int firstNodeAddress;
    int total;
    int reverseCount;
    struct node* arr[100001] = { 0 };
    int address;

    scanf("%d %d %d", &firstNodeAddress, &total, &reverseCount);

    for (int i = 0; i < total; i++) {
        struct node* tmp = (struct node*)malloc(sizeof(struct node));
        scanf("%d %d %d", &(tmp->address), &(tmp->data), &(tmp->nextAddress));
        arr[tmp->address] = tmp;
    }

    struct stack s = { 0,NULL };
    int p_address = firstNodeAddress;
    for (int i = 0; i < total; i++) {
        if (s.size < reverseCount) {
            // Èë
            push(&s, arr[p_address]);
            p_address = arr[p_address]->nextAddress;
        }
        else {
            // ³ö
            while (s.size != 0) {
                printf("%05d %d %05d\n", s.top->address, s.top->data, s.top->nextAddress);
                pop(&s);
            }
        }
    }
    while (s.size != 0) {
        printf("%05d %d %05d\n", s.top->address, s.top->data, s.top->nextAddress);
        pop(&s);
    }
}