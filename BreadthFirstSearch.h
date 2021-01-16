//�������������˼������һ���������ֵܽ�㣬�����ӽ�㣬���ȵݹ�����ӽ�㣬�ٵݹ�����ֵܽ�㡣
#ifndef BreadthFirstSearch_H
#define BreadthFirstSearch_H
#include <iostream>
#include "Graph.h"
#include <iterator>
#include <vector>
#include <queue>
using namespace std;
class BreadthFirstSearch
{
public:
	BreadthFirstSearch(Graph G,int s);			//���캯�����Զ�����DFS�㷨
	~BreadthFirstSearch();
	void bfs(Graph G, int s);		//������������㷨���庯��
	int getCount();		//�����붥��s���������ж������
private:
	bool* marked;		//������Ƕ����Ƿ񱻷��ʹ�����i�Ѿ������ʹ�����marked[i]=true;
	int count;			//��¼�붥��s���������ж������
	vector<int> array;			//���չ������������˳�򣬴���붥��s�����Ķ��㣻
	queue<int> waitsearch;		//�������Ķ��У�Ҳ�������һ����������
};

BreadthFirstSearch::BreadthFirstSearch(Graph G,int s)
{
	int N = G.getVertex();		//��ȡͼ�еĶ�����
	marked = new bool[N];
	for (int i = 0; i < N; i++)			//��ʼÿ������Ϊδ�����ʹ�
		marked[i] = false;
	count = 0;
	bfs(G,s);			//����BFS�㷨
}

void BreadthFirstSearch::bfs(Graph G,int s)
{
	waitsearch.push(s);		//�����㵯�����������
	marked[s] = true;			//�Ѿ�������еĵ���Ϊtrue��������ظ�����
	while (!waitsearch.empty())
	{
		int v = waitsearch.front();
		array.push_back(v);				//���е�����˳����ǹ������������˳�򣬽������δ���array����������һ�����
		count++;
		waitsearch.pop();
		vector<int> adj = G.getAdj(v);
		for (vector<int>::iterator it = adj.begin(); it != adj.end(); it++)			//���v���ӽ��δ�����ʹ�������ӽ�㵯�뵽����������
		{
			if (!marked[*it])
			{
				waitsearch.push(*it);
				marked[*it] = true;		//�Ѿ�������еĵ���Ϊtrue��������ظ�����
			}
		}
	}
	cout << "BFS��";
	for (vector<int>::iterator it = array.begin(); it != array.end(); it++)		//���չ������˳��������
	{
		cout << *it << " ";
	}
	cout << endl;
}

int BreadthFirstSearch::getCount()
{
	return count;
}

BreadthFirstSearch::~BreadthFirstSearch()
{
	if (marked != NULL)
	{
		delete[] marked;
		marked = NULL;
	}
}


#endif 


