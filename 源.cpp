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
	int n = 6, e = 10;			//图中的数据
	CreateMat(g, A, n, e);
	printf("(1)图G的邻接矩阵:\n");	DispMat(g); printf("\n");
	CreateAdj(G, A, n, e);
	printf("(2)图G的邻接表:\n"); DispAdj(G); printf("\n");
	printf("(3)从顶点0开始的DFS(递归算法):\n"); 
	DFS(G, 0); printf("\n");
	printf("(4)从顶点0开始的DFS(非递归算法):\n"); 
	DFS1(G, 0);printf("\n");
	printf("(5)从顶点0开始的BFS:\n");
	BFS(G, 0); printf("\n");
	printf("请输入想求取路径的起点：\n");
	int v;
	scanf_s("%d", &v); printf("\n");
	printf("(6)狄克斯特拉算法求解结果:\n");
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
	n = 6, e = 10;			//图中的数据
	CreateMat(g, A1, n, e);		//建立图的邻接矩阵
	printf("图G的邻接矩阵:\n");	DispMat(g); printf("\n");
	printf("(7)普里姆算法求解结果:\n");
	Prim(g, 0); printf("\n");
	printf("(8)克鲁斯卡尔算法求解结果:\n");
	Kruskal(g);
	printf("(9)销毁图G的邻接表\n"); 
	DestroyAdj(G);printf("\n");
	return 1;
}