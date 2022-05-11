#pragma once
#include "CreatAdj.h"					//����ͼ�Ĵ洢�ṹ�����������㷨
#define MaxSize 100
typedef struct
{
	int u;			//�ߵ���ʼ����
	int v;			//�ߵ���ֹ����
	int w;			//�ߵ�Ȩֵ
} Edge;

void InsertSort(Edge E[], int n) //����ֱ�Ӳ������򷽷���E[0..n-1]��w��������
{
	int i, j;
	Edge temp;
	for (i = 1; i < n; i++)
	{
		temp = E[i];
		j = i - 1;				//����������������E[0..i-1]����E[i]�Ĳ���λ��
		while (j >= 0 && temp.w < E[j].w)
		{
			E[j + 1] = E[j];	//���ؼ��ִ���E[i].w�ļ�¼����
			j--;
		}
		E[j + 1] = temp;		//��j+1������E[i] 
	}
}
void Kruskal(MatGraph g)	//���ÿ�³˹�����㷨���ͼg����С������
{
	int i, j, u1, v1, sn1, sn2, k;
	int vset[MAXV];
	Edge E[MaxSize];				//������б�
	k = 0;							//E������±��0��ʼ��
	for (i = 0; i < g.n; i++)				//��g�����ı߼�E
		for (j = 0; j <= i; j++)
		{
			if (g.edges[i][j] != 0 && g.edges[i][j] != INF)
			{
				E[k].u = i; E[k].v = j; E[k].w = g.edges[i][j];
				k++;
			}
		}
	InsertSort(E, g.e);				//����ֱ�Ӳ��������E���鰴Ȩֵ��������
	for (i = 0; i < g.n; i++) 			//��ʼ����������
		vset[i] = i;
	k = 1;                 			//k��ʾ��ǰ�����������ĵڼ�����,��ֵΪ1
	j = 0;                 			//E�бߵ��±�,��ֵΪ0
	while (k < g.n)       			//���ɵı���С��nʱѭ��
	{
		u1 = E[j].u; v1 = E[j].v;        //ȡһ���ߵ�ͷβ����
		sn1 = vset[u1];
		sn2 = vset[v1]; 				//�ֱ�õ��������������ļ��ϱ��
		if (sn1 != sn2)     	  		//���������ڲ�ͬ�ļ���,�ñ�����С��������һ����
		{
			printf("  (%d,%d):%d\n", u1, v1, E[j].w);
			k++;                    //���ɱ�����1
			for (i = 0; i < g.n; i++)     //��������ͳһ���
				if (vset[i] == sn2)  	//���ϱ��Ϊsn2�ĸ�Ϊsn1
					vset[i] = sn1;
		}
		j++;   						//ɨ����һ����
	}
}