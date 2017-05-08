#include <stdio.h>
#include <stdlib.h>

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode {
    ElementType Element;
    Tree Left;
    Tree Right;
}T1[MaxTree], T2[MaxTree];

Tree BuildTree(struct TreeNode T[]) {
    int N, root = -1;
    int check[MaxTree] = { 0 };
    scanf("%d", &N);
    getchar();

    char tmp_data, tmp_left, tmp_right;
    for (int i = 0; i < N; i++) {
        scanf("%c %c %c", &tmp_data, &tmp_left, &tmp_right);
        getchar();
        T[i].Element = tmp_data;
        T[i].Left = (tmp_left == '-') ? -1 : (tmp_left - '0');
        T[i].Right = (tmp_right == '-') ? -1 : (tmp_right - '0');

        if (T[i].Left != -1)
            check[T[i].Left] = 1;
        if (T[i].Right != -1)
            check[T[i].Right] = 1;
    }

    for (int i = 0; i < N; i++) {
        if (check[i] == 0) {
            root = i;
            break;
        }
    }

    return root;
}

int Isomorphic(Tree R1, Tree R2) {
    // 均为空
    if ((R1 == Null) && R2 == Null)
        return 1;
    // 一侧为空
    if (((R1 == Null) && (R2 != Null)) || ((R1 != Null) && (R2 == Null)))
        return 0;
    // 根元素不相等
    if (T1[R1].Element != T2[R2].Element)
        return 0;
    // 都没有左
    if ((T1[R1].Left == Null) && (T2[R2].Left == Null))
        return Isomorphic(T1[R1].Right, T2[R2].Right);
    // 不需要交换
    if (((T1[R1].Left != Null) && (T2[R2].Left != Null)) &&
        ((T1[T1[R1].Left].Element) == (T2[T2[R2].Left].Element)))
        return (Isomorphic(T1[R1].Left, T2[R2].Left) &&
            Isomorphic(T1[R1].Right, T2[R2].Right));
    else {
        return (Isomorphic(T1[R1].Left, T2[R2].Right) &&
            Isomorphic(T1[R1].Right, T2[R2].Left));
    }
}

int main() {
    Tree R1, R2;

    R1 = BuildTree(T1);
    R2 = BuildTree(T2);

    if (Isomorphic(R1, R2)) printf("Yes");
    else printf("No");

    return 0;
}