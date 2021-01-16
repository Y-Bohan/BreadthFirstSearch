#include <iostream>
#include "BreadthFirstSearch.h"
#include "Graph.h"
#include <fstream>
using namespace std;
int main()
{
	Graph G(9);
	fstream ifs;
	ifs.open("Graph.txt");		//Graph.txt文件存放的是测试图的边
	int v, w;
	while (!ifs.eof())		//将测试图的边加入到g中，用邻接表来存储
	{
		ifs >> v >> w;
		G.addEdge(v, w);
	}
	BreadthFirstSearch BFS(G, 3);
	ifs.close();
	return 0;
}