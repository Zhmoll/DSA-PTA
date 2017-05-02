#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */


List Merge(List L1, List L2) {
    List L = (List)malloc(sizeof(struct Node));

    PtrToNode pL1, pL2, pL;
    pL = L;
    pL1 = L1->Next;
    pL2 = L2->Next;

    while (pL1&&pL2) {
        if (pL1->Data < pL2->Data) {
            pL->Next = pL1;
            pL = pL->Next;
            pL1 = pL1->Next;
        }
        else if (pL1->Data > pL2->Data) {
            pL->Next = pL2;
            pL = pL->Next;
            pL2 = pL2->Next;
        }
        else {
            pL->Next = pL1;
            pL1 = pL1->Next;

            pL->Next->Next = pL2;
            pL2 = pL2->Next;

            pL = pL->Next->Next;
        }
    }

    if (pL1) {
        pL->Next = pL1;
    }
    if (pL2) {
        pL->Next = pL2;
    }
    L1->Next = NULL;
    L2->Next = NULL;
    return L;
}