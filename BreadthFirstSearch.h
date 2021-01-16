//深度优先搜索的思想遇到一个结点既有兄弟结点，又有子结点，则先递归遍历子结点，再递归遍历兄弟结点。
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
	BreadthFirstSearch(Graph G,int s);			//构造函数内自动调用DFS算法
	~BreadthFirstSearch();
	void bfs(Graph G, int s);		//广度优先搜索算法主体函数
	int getCount();		//返回与顶点s相连的所有顶点个数
private:
	bool* marked;		//用来标记顶点是否被访问过，若i已经被访问过，则marked[i]=true;
	int count;			//记录与顶点s相连的所有顶点个数
	vector<int> array;			//按照广度优先搜索的顺序，存放与顶点s相连的顶点；
	queue<int> waitsearch;		//待搜索的队列，也即构造的一个辅助队列
};

BreadthFirstSearch::BreadthFirstSearch(Graph G,int s)
{
	int N = G.getVertex();		//获取图中的顶点数
	marked = new bool[N];
	for (int i = 0; i < N; i++)			//初始每个点标记为未被访问过
		marked[i] = false;
	count = 0;
	bfs(G,s);			//调用BFS算法
}

void BreadthFirstSearch::bfs(Graph G,int s)
{
	waitsearch.push(s);		//将顶点弹入代搜索队列
	marked[s] = true;			//已经弹入对列的点标记为true，否则会重复弹入
	while (!waitsearch.empty())
	{
		int v = waitsearch.front();
		array.push_back(v);				//队列弹出的顺序就是广度优先搜索的顺序，将其依次存入array，结束后再一起输出
		count++;
		waitsearch.pop();
		vector<int> adj = G.getAdj(v);
		for (vector<int>::iterator it = adj.begin(); it != adj.end(); it++)			//如果v的子结点未被访问过，则该子结点弹入到待搜索队列
		{
			if (!marked[*it])
			{
				waitsearch.push(*it);
				marked[*it] = true;		//已经弹入对列的点标记为true，否则会重复弹入
			}
		}
	}
	cout << "BFS：";
	for (vector<int>::iterator it = array.begin(); it != array.end(); it++)		//按照广度搜索顺序输出结点
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


