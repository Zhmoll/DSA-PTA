#include <stdio.h>
#include <stdlib.h>

struct node {
	int left;
	int right;
};

int q[1000];
int q_top = 0;
int q_rear = 0;

void enqueue(int num) {
	q[q_top] = num;
	q_top++;
}

int dequeue() {
	return q[q_rear++];
}

int main() {
	int size;
	struct node nodes[10] = { 0,0 };
	int check[10] = { 0 };
	int root = 0;

	scanf("%d", &size);
	getchar();

	char tmp_left, tmp_right;
	for (int i = 0; i < size; i++) {
		scanf("%c %c", &tmp_left, &tmp_right);
		nodes[i].left = (tmp_left == '-') ? (-1) : (tmp_left - '0');
		nodes[i].right = (tmp_right == '-') ? (-1) : (tmp_right - '0');
		if (nodes[i].left != -1) check[nodes[i].left] = 1;
		if (nodes[i].right != -1) check[nodes[i].right] = 1;
		getchar();
	}

	for (int i = 0; i < size; i++) {
		if (check[i] == 0) {
			root = i;
			break;
		}
	}

	int tmp_current = root;
	enqueue(tmp_current);
	while (q_top != q_rear) {
		tmp_current = dequeue();
		if (nodes[tmp_current].left != -1) {
			enqueue(nodes[tmp_current].left);
		}
		if (nodes[tmp_current].right != -1) {
			enqueue(nodes[tmp_current].right);
		}
		if (nodes[tmp_current].left == -1 && nodes[tmp_current].right == -1) {
			printf("%d", tmp_current);
			if (q_top != q_rear)
				printf(" ");
		}
	}

	return 0;
}