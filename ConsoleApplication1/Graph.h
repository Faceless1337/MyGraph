#pragma once
#include "Node.h"





template <typename T>
class Graph
{
private:
	vector<Node<T>> nodes;
	Edges edges;
public:
	typedef T valueType;
	typedef Graph<valueType>* pointer;
	typedef Graph<valueType>& reference;
	Graph(void) {};
	~Graph(void) {};

	bool empty(void)
	{
		if (nodes.size() == 0)
		{
			return true;
		}
		return false;
	}

	void clear(void)
	{
		nodes.clear();
		edges.clear();
	}

	void addNode(valueType nodeObject)
	{
		vector <int> node;
		if (isNodeExist(nodeObject) == -1)
		{
			node.push_back(edges.size());
			nodes.push_back(Node<T>(nodeObject));
		}
	}
	void deleteNode(valueType nodeObject)
	{
		int nodeNumber = isNodeExist(nodeObject);
		if (nodeNumber != -1)
		{
			nodes.erase(nodes.begin() + nodeNumber);
			for (int i = 0; i < edges.size(); i++)
			{
				if (isEdgeExist(i, nodeNumber))
				{
					deleteEdge(i, nodeNumber);
				}
			}
		}
	}

	void addEdge(valueType iObject, valueType jObject)
	{
		int i = isNodeExist(iObject), j = isNodeExist(jObject);
		if (edges.size() == i)
			edges.push_back({ i });
		if (i != -1 && j != -1 && !isEdgeExist(i, j))
		{
			edges[i].push_back(j);
		}
	}
	void deleteEdge(int i, int j)
	{
		int pos;
		if (isEdgeExist(i, j))
		{
			for (int k = 0; k < edges[i].size(); k++)
			{
				if (edges[i][k] == j)
					pos = k;
			}
			edges[i].erase(edges[i].begin() + pos);
		}
		else
			cout << "this edge doesn't exist" << endl;
	}
	void deleteEdge(valueType iObject, valueType jObject)
	{
		int node1Pos, node2Pos;
		if (isEdgeExist(iObject, jObject) != -1)
		{
			for (int i = 0; i < edges.size(); i++)
				if (nodes[edges[i][0]].getObject() == iObject)
					node1Pos = i;

			for (int i = 0; i < edges[node1Pos].size(); i++)
				if (nodes[edges[node1Pos][i]].getObject() == jObject)
					node2Pos = i;

			edges[node1Pos].erase(edges[node1Pos].begin() + node2Pos);
		}
		else cout << "this edge doesn't exist" << endl;
	}

	int nodeDegree(int nodeNumber)
	{
		int degree;
		for (int i = 1; i < edges[nodeNumber].sise(); i++)
			degree++;
		return degree;
	}
	int nodeDegree(valueType nodeObject)
	{
		int degree = 0;
		int nodeNumber = isNodeExist(nodeObject);
		if (nodeNumber != -1)
		{
			for (int i = 0; i < nodes.size(); i++)
			{
				bool isExist = isEdgeExist(i, nodeNumber);
				degree += isExist == true ? 1 : 0;
			}
			return degree;
		}
		else
		{
			return -1;
		}
	}

	bool isEdgeExist(int i, int j)
	{
		if (edges.size() > 0)
		{
			for (int k = 0; k < edges[i].size(); k++)
			{
				if (edges[i][k] == j)
				{
					return true;
				}
			}
		}
		return false;
	}
	int isEdgeExist(valueType iObject, valueType jObject)
	{
		for (int k = 0; k < edges.size(); k++)
		{
			if (nodes[edges[k][0]].getObject() == iObject)
			{
				for (int i = 0; i < edges[k].size(); i++)
					if (nodes[edges[k][i]].getObject() == jObject)
					{
						return k;
					}
			}
		}
		return -1;
	}
	int isNodeExist(valueType nodeObject)
	{
		for (int i = 0; i < nodes.size(); i++)
		{
			if (nodes[i].getObject() == nodeObject)
			{
				return i;
			}
		}
		return -1;
	}
	bool isNodeExist(int nodeNumber)
	{
		return nodeNumber < nodes.size();
	}

	int countOfNodes()
	{
		return nodes.size();
	}

	int countOfEdges()
	{
		int amount = 0;
		for (int i = 0; i < edges.size(); i++)
			amount += edges[i].size() - 1;
		return amount;
	}

	void showNodes()
	{
		cout << endl;
		for (int i = 0; i < nodes.size(); i++)
		{
			cout << nodes[i].getObject() << endl;
		}
	}
	void showEdges()
	{
		cout << endl;
		for (int i = 0; i < edges.size(); i++)
			for (int j = 1; j < edges[i].size(); j++)
			{
				cout << nodes[edges[i][0]].getObject() << " - " << nodes[edges[i][j]].getObject() << endl;
			}
	}


	class Const_Node_Iterator
	{
	private:
		int index;
		pointer graphForIteration;
	public:
		Const_Node_Iterator(Graph<valueType> reference)
		{
			graphForIteration = &reference;
			index = 0;
		}
		//Const_Node_Iterator() {}
		bool next()
		{
			if (this->graphForIteration->nodes.size() == 0)
			{
				return false;
			}

			if (this->graphForIteration->nodes.size() == this->index + 1)
			{
				this->index++;
				return false;
			}
			if (this->graphForIteration->nodes.size() <= this->index + 1)
			{
				return false;
			}
			this->index++;
			return true;
		}
		bool prev()
		{
			if (this->graphForIteration->nodes.size() == 0)
			{
				return false;
			}
			if (this->index == 1)
			{
				this->index--;
				return false;
			}
			if (index == 0)
			{
				return false;
			}
			this->index--;
			return true;
		}
		void getCurrent()
		{
			if (this->graphForIteration->nodes.size() == 0)
			{
				cout << "There aren't any nodes" << endl;
				return;
			}
			cout << this->graphForIteration->nodes[index].getObject() << endl;
		}
		void getAdjacentNodes()
		{
			int countOfAdjacent = 0;
			cout << endl;
			for (int i = 0; i < this->graphForIteration->nodes.size(); i++)
			{
				if (this->graphForIteration->isEdgeExist(index, i) == true)
				{
					countOfAdjacent++;
					cout << this->graphForIteration->nodes[i].getObject() << ' ';
				}
			}
			if (countOfAdjacent == 0)
			{
				cout << "there are not nodes adjacent to this node";
			}
			cout << endl;
		}
		void getIncidentEdges()
		{
			cout << endl;
			int countOfIncident = 0;
			for (int i = 0; i < this->graphForIteration->nodes.size(); i++)
			{
				if (this->graphForIteration->isEdgeExist(index, i))
				{
					countOfIncident++;
					cout << this->graphForIteration->nodes[index].getObject() << " - " << this->graphForIteration->nodes[i].getObject() << endl;
				}
			}
			if (countOfIncident == 0)
			{
				cout << "there are not edges incident to this nodes";
			}
			cout << endl;
		}
	};



	class Node_Iterator
	{
	private:
		pointer graphForIteration;
		int index;
	public:

		Node_Iterator(Graph<valueType> reference)
		{
			graphForIteration = &reference;
			index = 0;
		}
		void deleteNode()
		{

			if (graphForIteration->nodes.size() == 0)
			{
				return;
			}
			bool isLastNode = false;
			if (index == graphForIteration->nodes.size() - 1)
				isLastNode = true;
			graphForIteration->nodes.erase(graphForIteration->nodes.begin() + index);

			if (graphForIteration->edges.size() > 0)
			{
				graphForIteration->edges.erase(graphForIteration->edges.begin() + index);
				for (int i = 0; i < graphForIteration->edges.size(); i++)
					for (int j = 0; j < graphForIteration->edges[i].size(); j++)
					{
						if (graphForIteration->edges[i][j] == index)
							graphForIteration->edges[i].erase(graphForIteration->edges[i].begin() + j);
					}
			}
			if (isLastNode)
				index--;
		}
		bool next()
		{
			if (this->graphForIteration->nodes.size() == 0)
			{
				return false;
			}

			if (this->graphForIteration->nodes.size() == this->index + 1)
			{
				this->index++;
				return false;
			}
			if (this->graphForIteration->nodes.size() <= this->index + 1)
			{
				return false;
			}
			this->index++;
			return true;
		}
		bool prev()
		{
			if (this->graphForIteration->nodes.size() == 0)
			{
				return false;
			}
			if (this->index == 1)
			{
				this->index--;
				return false;
			}
			if (index == 0)
			{
				return false;
			}
			this->index--;
			return true;
		}
		void getCurrent()
		{
			if (this->graphForIteration->nodes.size() == 0)
			{
				cout << "There aren't any nodes" << endl;
				return;
			}
			cout << this->graphForIteration->nodes[index].getObject() << endl;
		}
		void getAdjacentNodes()
		{
			int countOfAdjacent = 0;
			cout << endl;
			for (int i = 0; i < this->graphForIteration->nodes.size(); i++)
			{
				if (this->graphForIteration->isEdgeExist(index, i) == true)
				{
					countOfAdjacent++;
					cout << this->graphForIteration->nodes[i].getObject() << ' ';
				}
			}
			if (countOfAdjacent == 0)
			{
				cout << "there are not nodes adjacent to this node";
			}
			cout << endl;
		}
		void getIncidentEdges()
		{
			cout << endl;
			int countOfIncident = 0;
			for (int i = 0; i < this->graphForIteration->nodes.size(); i++)
			{
				if (this->graphForIteration->isEdgeExist(index, i))
				{
					countOfIncident++;
					cout << this->graphForIteration->nodes[index].getObject() << " - " << this->graphForIteration->nodes[i].getObject() << endl;
				}
			}
			if (countOfIncident == 0)
			{
				cout << "there are not edges incident to this nodes";
			}
			cout << endl;
		}

	};


	class Reverse_Node_Iterator
	{
	private:
		pointer graphForIteration;
		int index;
	public:
		void deleteNode()
		{
			if (graphForIteration->nodes.size() == 0)
			{
				return;
			}
			bool isLastNode = false, isFirstNode = false;
			if (index == 0)
				isLastNode = true;
			if (index == graphForIteration->nodes.size() - 1)
				isFirstNode = true;
			graphForIteration->nodes.erase(graphForIteration->nodes.begin() + index);
			if (graphForIteration->edges.size() > 0)
			{
				graphForIteration->edges.erase(graphForIteration->edges.begin() + index);
				for (int i = 0; i < graphForIteration->edges.size(); i++)
					for (int j = 0; j < graphForIteration->edges[i].size(); j++)
					{
						if (graphForIteration->edges[i][j] == index)
							graphForIteration->edges[i].erase(graphForIteration->edges[i].begin() + j);
					}
			}
			if (isLastNode)
			{
				index++;
				return;
			}
			if (isFirstNode)
			{
				index--;
				return;
			}
			index--;
		}

		Reverse_Node_Iterator(Graph<valueType> reference)
		{
			graphForIteration = &reference;
			index = graphForIteration->nodes.size() - 1;
		}

		bool next()
		{
			if (graphForIteration->nodes.size() == 0)
			{
				return false;
			}

			if (index == 1)
			{
				index--;
				return false;
			}
			if (index == 0)
			{
				return false;
			}
			index--;
			return true;
		}
		bool prev()
		{
			if (graphForIteration->nodes.size() == 0)
			{
				return false;
			}
			if (index == graphForIteration->nodes.size() - 2)
			{
				index++;
				return false;
			}
			if (index == graphForIteration->nodes.size() - 1)
			{
				return false;
			}
			index++;
			return true;
		}
		void getCurrent()
		{
			if (graphForIteration->nodes.size() == 0)
			{
				cout << "There aren't any nodes" << endl;
				return;
			}
			cout << graphForIteration->nodes[index].getObject() << endl;
		}
		void getAdjacentNodes()
		{
			int countOfAdjacent = 0;
			cout << endl;
			for (int i = 0; i < graphForIteration->nodes.size(); i++)
			{
				if (graphForIteration->isEdgeExist(index, i) == true)
				{
					countOfAdjacent++;
					cout << graphForIteration->nodes[i].getObject() << ' ';
				}
			}
			if (countOfAdjacent == 0)
			{
				cout << "there are not nodes adjacent to this node";
			}
			cout << endl;
		}
		void getIncidentEdges()
		{
			cout << endl;
			int countOfIncident = 0;
			for (int i = 0; i < graphForIteration->nodes.size(); i++)
			{
				if (graphForIteration->isEdgeExist(index, i))
				{
					countOfIncident++;
					cout << graphForIteration->nodes[index].getObject() << " - " << graphForIteration->nodes[i].getObject() << endl;
				}
			}
			if (countOfIncident == 0)
			{
				cout << "there are not edges incident to this nodes";
			}
			cout << endl;
		}
	};


	class Const_Edge_Iterator
	{
	private:
		pointer graphForIteration;
		int node1;
		int node2;
	public:
		Const_Edge_Iterator(Graph<valueType> reference)
		{
			graphForIteration = &reference;
			node1 = 0;
			node2 = 1;
		}
		Const_Edge_Iterator() {}

		bool next()
		{
			if (graphForIteration->edges.size() == 0)
			{
				cout << "there are not edges" << endl;
				return false;
			}
			if (graphForIteration->edges.size() - 1 == node1 && node2 == graphForIteration->edges[node1].size() - 1)
			{
				return false;
			}
			if (graphForIteration->edges[node1].size() - 1 > node2)
			{
				node2++;
				return true;
			}
			if (graphForIteration->edges[node1].size() - 1 <= node2 && node1 < graphForIteration->edges.size() - 1)
			{
				node1++;
				node2 = 1;
				return true;
			}

		}
		bool prev()
		{
			if (graphForIteration->edges.size() == 0)
			{
				cout << "there are not edges" << endl;
				return false;
			}
			if (node1 == 0 && node2 == 1)
			{
				return false;
			}

			if (node2 > 0 && node1 > 0)
			{
				node2--;
				return true;
			}
			if (node2 == 0 && node1 > 0)
			{
				node1--;
				node2++;
				return true;
			}
			if (node2 > 1 && node1 == 0)
			{
				node2--;
				return true;
			}
		}
		pair<int, int> currentEdge()
		{
			if (graphForIteration->edges.size() == 0)
				return make_pair(-1, -1);
			return make_pair(graphForIteration->edges[node1][0], graphForIteration->edges[node1][node2]);
		}
	};



	class Edge_Iterator
	{
	private:
		pointer graphForIteration;
		int node1;
		int node2;
	public:
		Edge_Iterator(reference reference)
		{
			graphForIteration = &reference;
			node1 = 0;
			node2 = 1;
		}

		void deleteEdge()
		{
			if (graphForIteration->edges.size() == 0)
			{
				cout << "there are not edges" << endl;
				return;
			}
			if (node2 == graphForIteration->edges[node1].size() - 1 && graphForIteration->edges[node1].size() == 2)
			{
				graphForIteration->edges.erase(graphForIteration->edges.begin() + node1);
				if (node1 > 0)
					node1--;
				return;
			}
			if (graphForIteration->edges[node1].size() > 2)
			{
				graphForIteration->edges[node1].erase(graphForIteration->edges[node1].begin() + node2);
				return;
			}
			if (graphForIteration->edges[node1].size() == 2)
			{
				graphForIteration->edges.erase(graphForIteration->edges.begin() + node1);
				node2 = 1;
				return;
			}

			graphForIteration->edges[node1].erase(graphForIteration->edges[node1].begin() + node2);
			if (graphForIteration->edges[node1].size() == 1 && node1 < graphForIteration->edges.size() - 1)
			{
				graphForIteration->edges.erase(graphForIteration->edges.begin() + node1);
				node2 = 1;
			}
			if (graphForIteration->edges[node1].size() == 1 && node1 == graphForIteration->edges.size() - 1)
			{
				graphForIteration->edges.erase(graphForIteration->edges.begin() + node1);
				node2 = 1;
				node1--;
			}

		}
		bool next()
		{
			if (graphForIteration->edges.size() == 0)
			{
				cout << "there are not edges" << endl;
				return false;
			}
			if (graphForIteration->edges.size() - 1 == node1 && node2 == graphForIteration->edges[node1].size() - 1)
			{
				return false;
			}
			if (graphForIteration->edges[node1].size() - 1 > node2)
			{
				node2++;
				return true;
			}
			if (graphForIteration->edges[node1].size() - 1 <= node2 && node1 < graphForIteration->edges.size() - 1)
			{
				node1++;
				node2 = 1;
				return true;
			}

		}
		bool prev()
		{
			if (graphForIteration->edges.size() == 0)
			{
				cout << "there are not edges" << endl;
				return false;
			}
			if (node1 == 0 && node2 == 1)
			{
				return false;
			}

			if (node2 > 0 && node1 > 0)
			{
				node2--;
				return true;
			}
			if (node2 == 0 && node1 > 0)
			{
				node1--;
				node2++;
				return true;
			}
			if (node2 > 1 && node1 == 0)
			{
				node2--;
				return true;
			}
		}
		pair<int, int> currentEdge()
		{
			if (graphForIteration->edges.size() == 0)
				return make_pair(-1, -1);
			return make_pair(graphForIteration->edges[node1][0], graphForIteration->edges[node1][node2]);
		}
	};


	class Reverse_Edge_Iterator
	{
	private:
		pointer graphForIteration;
		int node1;
		int node2;
	public:
		Reverse_Edge_Iterator(Graph<valueType> reference)
		{
			graphForIteration = &reference;
			node1 = graphForIteration->edges.size() - 1;
			node2 = graphForIteration->edges[node1].size() - 1;
		}

		void deleteEdge()
		{
			if (graphForIteration->edges.size() == 0)
			{
				cout << "there are not edges" << endl;
				return;
			}
			if (node2 == 1 && graphForIteration->edges[node1].size() == 2)
			{
				graphForIteration->edges.erase(graphForIteration->edges.begin() + node1);
				if (node1 == 0)
				{
					graphForIteration->edges.clear();
					return;
				}
				if (node1 > 0)
					node1--;
				node2 = graphForIteration->edges[node1].size() - 1;
				return;
			}
			if (graphForIteration->edges[node1].size() > 2)
			{
				graphForIteration->edges[node1].erase(graphForIteration->edges[node1].begin() + node2);
				node2--;
				return;
			}
			if (graphForIteration->edges[node1].size() == 2)
			{
				graphForIteration->edges.erase(graphForIteration->edges.begin() + node1);
				node1--;
				node2 = graphForIteration->edges[node1].size() - 1;
				return;
			}

			graphForIteration->edges[node1].erase(graphForIteration->edges[node1].begin() + node2);
			if (graphForIteration->edges[node1].size() == 1 && node1 > 0)
			{
				graphForIteration->edges.erase(graphForIteration->edges.begin() + node1);
				node2 = graphForIteration->edges[node1].size() - 1;
			}
			if (graphForIteration->edges[node1].size() == 1 && node1 == 0)
			{
				graphForIteration->edges.erase(graphForIteration->edges.begin() + node1);
				node2 = 1;
				node1++;
			}

		}
		bool next()
		{
			if (graphForIteration->edges.size() == 0)
			{
				cout << "there are not edges" << endl;
				return false;
			}
			if (0 == node1 && node2 == 1)
			{
				return false;
			}
			if (node2 > 1)
			{
				node2--;
				return true;
			}
			if (node2 == 1 && node1 > 0)
			{
				node1--;
				node2 = graphForIteration->edges[node1].size() - 1;
				return true;
			}

		}
		bool prev()
		{
			if (graphForIteration->edges.size() == 0)
			{
				cout << "there are not edges" << endl;
				return false;
			}
			if (node1 == graphForIteration->edges.size() - 1 && node2 == graphForIteration->edges[node1].size() - 1)
			{
				return false;
			}

			if (node2 < graphForIteration->edges[node1].size() - 1)
			{
				node2++;
				return true;
			}
			if (node2 == graphForIteration->edges[node1].size() - 1 && node1 < graphForIteration->edges.size() - 1)
			{
				node1++;
				node2 = 1;
				return true;
			}
			if (node2 < graphForIteration->edges[node1].size() - 1 && node1 == graphForIteration->edges.size() - 1)
			{
				node2++;
				return true;
			}
		}
		pair<int, int> currentEdge()
		{
			if (graphForIteration->edges.size() == 0)
				return make_pair(-1, -1);
			return make_pair(graphForIteration->edges[node1][0], graphForIteration->edges[node1][node2]);
		}
	};




};

/*ostream& operator<<(ostream& out,  & )
{
	out << ;
	return out;
}*/