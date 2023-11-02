
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF 1000




int parent[MAX_VERTICES]; // �θ� ���

void set_init(int n) {
	for (int i = 0; i < n; i++) {
		parent[i] = -1;
	}
}

// curr�� ���� ���� ��ȯ
int set_find(int curr) {
	if (parent[curr] == -1) {
		return curr;
	}
	while (parent[curr] != -1) curr = parent[curr];
	return curr;
}

// �� ���� ���Ұ� ���� ������ ��ħ
void set_union(int a, int b) {
	int root1 = set_find(a); // ��� a�� ��Ʈ�� ã�´�.
	int root2 = set_find(b); // ��� b�� ��Ʈ�� ã�´�.
	if (root1 != root2) { // ���Ѵ�.
		parent[root1] = root2;
	}
}

struct Edge { // ������ ��Ÿ���� ����ü
	int start, end, weight;
};

typedef struct Graph {
	int n;
	struct Edge edges[2 * MAX_VERTICES];
} Graph;

// �׷��� �ʱ�ȭ
void graph_init(Graph* g) {
	g->n  = 0;
	for (int i = 0; i < 2 * MAX_VERTICES; i++) {
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = INF;
	}
}

// ���� ���� ����
void insert_edge(Graph* g, int start, int end, int w) {
	g->edges[g->n].start = start;
	g->edges[g->n].end = end;
	g->edges[g->n].weight = w;
	g->n++;
}

// qsort()�� ���Ǵ� �Լ�
int compare(const void* a, const void* b) {
	struct Edge* x = (struct Edge*)a;
	struct Edge* y = (struct Edge*)b;
	return (x->weight - y->weight);
}

void kruskal(Graph* g) {
	int edge_accepted = 0; // ������� ���õ� ������ ��
	int uset, vset; // ���� u�� ���� v�� ���� ��ȣ
	struct Edge e;

	set_init(g->n); // ���� �ʱ�ȭ
	qsort(g->edges, g->n, sizeof(struct Edge), compare);

	printf("ũ�罺Į �ּ� ���� Ʈ�� �˰��� \n");

	printf("Qsort��� \n");
	int i = 0;
	while (edge_accepted < (g->n-1)) { // ������ �� < (n - 1)

	
		e = g->edges[i];
		uset = set_find(e.start); // ���� u�� ���� ��ȣ
		vset = set_find(e.end); // ���� v�� ���� ��ȣ
		if (uset != vset) { // ���� ���� ������ �ٸ���
			printf("����( % d, % d) % d ����\n", e.start, e.end, e.weight);
		
			set_union(uset, vset); // �� ���� ������ ��ģ��.
		}
		edge_accepted++;
		i++;
	}
}

int main() {

	Graph* g;
	g = (Graph*)malloc(sizeof(Graph));
	graph_init(g);
	

	insert_edge(g, 1, 2, 3);
	insert_edge(g, 1, 6,11);
	insert_edge(g, 1, 7, 12);

	insert_edge(g, 2, 1, 3);
	insert_edge(g, 2, 3, 5);
	insert_edge(g, 2, 5, 1);
	insert_edge(g, 2, 6, 7);
	insert_edge(g, 2, 7, 8);
	insert_edge(g, 2, 4, 4);

	insert_edge(g, 3, 2, 5);
	insert_edge(g, 3, 4, 2);
	insert_edge(g, 3, 7, 6);
	insert_edge(g, 3, 8, 5);


	insert_edge(g, 4, 2, 4);
	insert_edge(g, 4, 3, 2);
	insert_edge(g, 4, 5, 13);
	insert_edge(g, 4, 10, 16);


	insert_edge(g, 5, 2, 1);
	insert_edge(g, 5, 4, 13);
	insert_edge(g, 5, 6, 9);
	insert_edge(g, 5, 9, 18);
	insert_edge(g, 5, 10, 17);

	insert_edge(g, 6, 1, 11);
	insert_edge(g, 6, 2, 7);
	insert_edge(g, 6, 5, 9);

	insert_edge(g, 7, 1, 12);
	insert_edge(g, 7, 2, 8);
	insert_edge(g, 7, 3, 6);
	insert_edge(g, 7, 8, 13);

	insert_edge(g, 8, 3, 5);
	insert_edge(g, 8, 4, 14);
	insert_edge(g, 8, 7, 13);
	insert_edge(g, 8, 10, 15);

	insert_edge(g, 9, 5, 18);
	insert_edge(g, 9, 10, 10);

	insert_edge(g, 10, 4, 16);
	insert_edge(g, 10, 5, 17);
	insert_edge(g, 10, 8, 15);
	insert_edge(g, 10, 9, 10);



	kruskal(g);
	free(g);
	return 0;
}