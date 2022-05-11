#pragma once
#include "CreatAdj.h"					//����ͼ�Ĵ洢�ṹ�����������㷨
int visited[MAXV];						//ȫ������
void DFS(AdjGraph* G, int v)				//�ݹ�������ȱ����㷨
{
	ArcNode* p;
	visited[v] = 1;                   	//���ѷ��ʱ��
	printf("%3d", v); 					//��������ʶ���ı��
	p = G->adjlist[v].firstarc;      		//pָ�򶥵�v�ĵ�һ�����Ļ�ͷ���
	while (p != NULL)
	{
		if (visited[p->adjvex] == 0)		//��p->adjvex����δ����,�ݹ������
			DFS(G, p->adjvex);
		p = p->nextarc;              		//pָ�򶥵�v����һ�����Ļ�ͷ���
	}
}
void DFS1(AdjGraph* G, int v)		//�ǵݹ�������ȱ����㷨
{
	ArcNode* p;
	int St[MAXV];
	int top = -1, w, x, i;
	for (i = 0; i < G->n; i++)
		visited[i] = 0;				//������ʱ�־���ó�0
	printf("%3d", v);				//���ʶ���v
	visited[v] = 1;					//�ö���v�ѷ���
	top++; St[top] = v;				//������v��ջ
	while (top > -1)					//ջ����ѭ��
	{
		x = St[top]; 					//ȡջ������x��Ϊ��ǰ����
		p = G->adjlist[x].firstarc;	//�Ҷ���x�ĵ�һ�����ڵ�
		while (p != NULL)
		{
			w = p->adjvex;			//x�����ڵ�Ϊw
			if (visited[w] == 0)		//������wû�з���
			{
				printf("%3d", w);	//���ʶ���w
				visited[w] = 1;		//�ö���w�ѷ���
				top++;				//������w��ջ
				St[top] = w;
				break;				//�˳�ѭ�������ٴ���ջ���Ķ���(���ֺ���ȳ�)
			}
			p = p->nextarc;			//�Ҷ���x����һ�����ڵ�
		}
		if (p == NULL) top--;			//������x��û�����ڵ㣬������ջ
	}
	printf("\n");
}
void BFS(AdjGraph* G, int v)					//������ȱ����㷨		
{
	ArcNode* p;
	int queue[MAXV], front = 0, rear = 0;			//���廷�ζ��в���ʼ��
	int visited[MAXV];            			//�����Ŷ���ķ��ʱ�־������
	int w, i;
	for (i = 0; i < G->n; i++) visited[i] = 0;		//���ʱ�־�����ʼ��
	printf("%3d", v); 						//��������ʶ���ı��
	visited[v] = 1;              				//���ѷ��ʱ��
	rear = (rear + 1) % MAXV;
	queue[rear] = v;             				//v����
	while (front != rear)       				//�����в���ʱѭ��
	{
		front = (front + 1) % MAXV;
		w = queue[front];       				//���Ӳ�����w
		p = G->adjlist[w].firstarc; 			//�Ҷ���w�ĵ�һ�����ڵ�
		while (p != NULL)
		{
			if (visited[p->adjvex] == 0) 		//�����ڵ�δ������
			{
				printf("%3d", p->adjvex);  	//�������ڵ�
				visited[p->adjvex] = 1;		//�øö����ѱ����ʵı�־
				rear = (rear + 1) % MAXV;			//�ö������
				queue[rear] = p->adjvex;
			}
			p = p->nextarc;              		//����һ�����ڵ�
		}
	}
	printf("\n");
}
