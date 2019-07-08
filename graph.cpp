#include <iostream>
#include <vector>
using namespace std;

struct node
{
	char data;
	vector<node> edge;
};

class Graph
{
	node *nodes;
	node *temp;
private:
public:
	Graph(int totalNodes)
	{
		nodes = new node[totalNodes];
		for (int i = 0; i < totalNodes; i++)
			nodes[i].data = 'A' + i;
	}

	void adjacentMatrix(int a[][5])
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (a[i][j] == 1)
					nodes[i].edge.push_back(nodes[j]);
			}
		}
	}

	void print()
	{
		for (int i = 0; i < 5; i++)
		{
			cout << char('A' + i) << " = ";
			for (int j = 0; j < nodes[i].edge.size(); j++)
			{
				cout << nodes[i].edge[j].data << ' ';
			}
			cout << endl;
		}
	}
};

int  main()
{
	int arr[5][5] =
	{ 
		{ 0, 1, 1, 0, 1 },
		{ 0, 0, 1, 0, 0 },
		{ 0, 1, 0, 1, 0 },
		{ 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 0 },
	};

	Graph a(5);

	a.adjacentMatrix(arr);

	a.print();

	cout << endl << endl;

//	system("pause");
}

