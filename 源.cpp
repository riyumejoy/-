#include "CreatAdj.h"
#include"travsal.h"
#include"Dijkstra.h"
#include"Prim.h"
#include"Kruskal.h"
int main()
{
	MatGraph g;
	AdjGraph* G;
	int A[MAXV][MAXV] = {
		{0,5,INF,7,INF,INF},
		{INF,0,4,INF,INF,INF},
		{8,INF,0,INF,INF,9},
		{INF,INF,5,0,INF,6},
		{INF,INF,INF,5,0,INF},
		{3,INF,INF,INF,1,0} };
	int n = 6, e = 10;			//ͼ�е�����
	CreateMat(g, A, n, e);
	printf("(1)ͼG���ڽӾ���:\n");	DispMat(g); printf("\n");
	CreateAdj(G, A, n, e);
	printf("(2)ͼG���ڽӱ�:\n"); DispAdj(G); printf("\n");
	printf("(3)�Ӷ���0��ʼ��DFS(�ݹ��㷨):\n"); 
	DFS(G, 0); printf("\n");
	printf("(4)�Ӷ���0��ʼ��DFS(�ǵݹ��㷨):\n"); 
	DFS1(G, 0);printf("\n");
	printf("(5)�Ӷ���0��ʼ��BFS:\n");
	BFS(G, 0); printf("\n");
	printf("����������ȡ·������㣺\n");
	int v;
	scanf_s("%d", &v); printf("\n");
	printf("(6)�ҿ�˹�����㷨�����:\n");
	Dijkstra(g, v);
	
	v = 3;
	int u = 3;
	int A1[MAXV][MAXV] = {
		{0,5,8,7,INF,3},
		{5,0,4,INF,INF,INF},
		{8,4,0,5,INF,9},
		{7,INF,5,0,5,6},
		{INF,INF,INF,5,0,1},
		{3,INF,9,6,1,0} };
	n = 6, e = 10;			//ͼ�е�����
	CreateMat(g, A1, n, e);		//����ͼ���ڽӾ���
	printf("ͼG���ڽӾ���:\n");	DispMat(g); printf("\n");
	printf("(7)����ķ�㷨�����:\n");
	Prim(g, 0); printf("\n");
	printf("(8)��³˹�����㷨�����:\n");
	Kruskal(g);
	printf("(9)����ͼG���ڽӱ�\n"); 
	DestroyAdj(G);printf("\n");
	return 1;
}