#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
class Graph
{
public:
	Graph(int N);		//初始化构造一个包含N个顶点但不包含边的图
	Graph(const Graph& G);		//私有成员变量有堆上开辟的内存，需要拷贝构造函数和重载=进行深拷贝
	Graph& operator=(const Graph& G);
	int getVertex();	//获取图中顶点的数量
	int getEdge();		//获取图中边的数量
	void addEdge(int v, int w);			//向图中加入一条连接顶点v和顶点w的边
	vector<int> getAdj(int v);			//获取连接顶点v的所有顶点
	bool connected(int v, int w);	//判断顶点v和顶点w之间是否已经有边存在
	~Graph();
private:
	int vertexCount;		//顶点个数
	int edgeCount;		//边个数
	vector<int>* adj;	//存储图结构的邻接表
};

Graph::Graph(int N)
{
	vertexCount = N;
	edgeCount = 0;
	adj = new vector<int>[N];
}

Graph::Graph(const Graph& G)
{
	vertexCount = G.vertexCount;
	edgeCount = G.edgeCount;
	adj = new vector<int>[vertexCount];
	for (int i = 0; i < vertexCount; i++)
		for (vector<int>::iterator it = G.adj[i].begin(); it != G.adj[i].end(); it++)
			adj[i].push_back(*it);
}

Graph& Graph::operator=(const Graph& G)
{
	vertexCount = G.vertexCount;
	edgeCount = G.edgeCount;
	adj = new vector<int>[vertexCount];
	for (int i = 0; i < vertexCount; i++)
		for (vector<int>::iterator it = G.adj[i].begin(); it != G.adj[i].end(); it++)
			adj[i].push_back(*it);
	return *this;
}

int Graph::getVertex()
{
	return vertexCount;
}

int Graph::getEdge()
{
	return edgeCount;
}

void Graph::addEdge(int v, int w)		//由于无向图是双向的，所以添加边时需要同时添加到v的邻接表和w的邻接表
{
	if (!connected(v, w))
	{
		adj[v].push_back(w);
		adj[w].push_back(v);
		edgeCount++;		//添加完后不要忘记边的条数加1
	}
}

vector<int> Graph::getAdj(int v)
{
	return adj[v];
}

bool Graph::connected(int v, int w)
{
	for (vector<int>::iterator it = adj[v].begin(); it != adj[v].end(); it++)
	{
		if (*it == w)		//说明v的邻接表中有w，两点之间有边
			return true;
	}
	return false;		//遍历完v的邻接表都没有w，说明两点之间没有边
}

Graph::~Graph()
{
	if (adj != NULL)
	{
		delete[] adj;
		adj = NULL;
	}
}
#endif 








