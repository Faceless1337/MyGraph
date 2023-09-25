#pragma once
#include <vector>
#include <iostream>
using namespace std;

typedef vector<vector<int>> Edges;

template <typename T>
class Node
{
public:
	typedef T valueType;
	Node(valueType node = valueType())
	{
		nodes = node;
	}
	string getObject()
	{
		return nodes;
	}
private:
	valueType nodes;
};