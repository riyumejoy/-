#pragma once
//ͼ�Ļ��������㷨
#include <stdio.h>
#include <malloc.h>
//ͼ�����ִ洢�ṹ
#define INF 32767				//�����
#define	MAXV 100				//��󶥵����
typedef char InfoType;

//���¶����ڽӾ�������
typedef struct
{
	int no;						//������
	InfoType info;				//����������Ϣ
} VertexType;					//��������
typedef struct
{
	int edges[MAXV][MAXV];		//�ڽӾ�������
	int n, e;					//������������
	VertexType vexs[MAXV];		//��Ŷ�����Ϣ
} MatGraph;						//������ͼ�ڽӾ�������

//���¶����ڽӱ�����
typedef struct ANode
{
	int adjvex;					//�ñߵ��ڽӵ���
	struct ANode* nextarc;		//ָ����һ���ߵ�ָ��
	int weight;					//�ñߵ������Ϣ����Ȩֵ�������ͱ�ʾ��
} ArcNode;						//�߽ڵ�����
typedef struct Vnode
{
	InfoType info;				//����������Ϣ
	int count;					//��Ŷ������,����������������
	ArcNode* firstarc;			//ָ���һ����
} VNode;						//�ڽӱ�ͷ�ڵ�����
typedef struct
{
	VNode adjlist[MAXV];		//�ڽӱ�ͷ�ڵ�����
	int n, e;					//ͼ�ж�����n�ͱ���e
} AdjGraph;						//������ͼ�ڽӱ�����

//------------------------------------------------------------
//----�ڽӾ���Ļ��������㷨----------------------------------
//------------------------------------------------------------
void CreateMat(MatGraph& g, int A[MAXV][MAXV], int n, int e) //����ͼ���ڽӾ���
{
	int i, j;
	g.n = n; g.e = e;
	for (i = 0; i < g.n; i++)
		for (j = 0; j < g.n; j++)
			g.edges[i][j] = A[i][j];
}
void DispMat(MatGraph g)	//����ڽӾ���g
{
	int i, j;
	for (i = 0; i < g.n; i++)
	{
		for (j = 0; j < g.n; j++)
			if (g.edges[i][j] != INF)
				printf("%4d", g.edges[i][j]);
			else
				printf("%4s", "��");
		printf("\n");
	}
}
//------------------------------------------------------------

//------------------------------------------------------------
//----�ڽӱ�Ļ��������㷨------------------------------------
//------------------------------------------------------------
void CreateAdj(AdjGraph*& G, int A[MAXV][MAXV], int n, int e) //����ͼ���ڽӱ�
{
	int i, j;
	ArcNode* p;
	G = (AdjGraph*)malloc(sizeof(AdjGraph));
	for (i = 0; i < n; i++)						//���ڽӱ�������ͷ�ڵ��ָ�����ó�ֵ
		G->adjlist[i].firstarc = NULL;
	for (i = 0; i < n; i++)						//����ڽӾ�����ÿ��Ԫ��
		for (j = n - 1; j >= 0; j--)
			if (A[i][j] != 0 && A[i][j] != INF)	//����һ����
			{
				p = (ArcNode*)malloc(sizeof(ArcNode));	//����һ���ڵ�p
				p->adjvex = j;
				p->weight = A[i][j];
				p->nextarc = G->adjlist[i].firstarc;	//����ͷ�巨����ڵ�p
				G->adjlist[i].firstarc = p;
			}
	G->n = n; G->e = n;
}
void DispAdj(AdjGraph* G)	//����ڽӱ�G
{
	ArcNode* p;
	for (int i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		printf("%3d: ", i);
		while (p != NULL)
		{
			printf("%3d[%d]��", p->adjvex, p->weight);
			p = p->nextarc;
		}
		printf("��\n");
	}
}
void DestroyAdj(AdjGraph*& G)	//����ͼ���ڽӱ�
{
	ArcNode* pre, * p;
	for (int i = 0; i < G->n; i++)		//ɨ�����еĵ�����
	{
		pre = G->adjlist[i].firstarc;	//pָ���i����������׽ڵ�
		if (pre != NULL)
		{
			p = pre->nextarc;
			while (p != NULL)			//�ͷŵ�i������������б߽ڵ�
			{
				free(pre);
				pre = p; p = p->nextarc;
			}
			free(pre);
		}
	}
	free(G);						//�ͷ�ͷ�ڵ�����
}
//------------------------------------------------------------
