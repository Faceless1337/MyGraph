
#include <iostream>
#include <string>
#include "Node.h"
#include <Windows.h>
#include "Graph.h"



int main(void)
{
	int choise = 1;
	string str_1 = "";
	string str_2 = "";

	Graph<string>* G = new Graph<string>();

	

	while (true)
	{
		cout << "1. Add nodes" << endl;
		cout << "2. Add edge" << endl;
		cout << "3. Delete nodes" << endl;
		cout << "4. Delete edge" << endl;
		cout << "6. Amount of edges and nodes" << endl;
		cout << "7. Show nodes" << endl;
		cout << "8. Show edges" << endl;
		cout << "9. Degree of nodes" << endl;
		cout << "10. Iterator for nodes" << endl;
		cout << "11. Iterator for edges" << endl;
		cout << "12. Does a node exist" << endl;
		cout << "13. Does a edge exist" << endl;
		cout << "14. Is container empty" << endl;
		cout << "15. Clear" << endl;
		cout << "16. Reverse iterator for nodes" << endl;
		cout << "17. Reverse iterator for edges" << endl;
		cout << "18. Const iterator for nodes" << endl;
		cout << "19. Const iterator for edges" << endl;
		cout << "0. Exit" << endl;
		cout << "Your choise: ";

		bool flag = true;
			cin >> choise;
			switch (choise)
		    {
			case 0:
			{

				return 0;
				break;
			}
			case 20:
			{
				Graph<string>::Edge_Iterator G_iterator(*G);
				for (int i = 0; i < G->countOfEdges(); i++)
				{
					cout << G_iterator.currentEdge().first << " - " << G_iterator.currentEdge().second << endl;
					G_iterator.next();
				}
				break;
			}
			case 1:
			{
				cout << endl << "Enter nodes name: ";
				cin >> str_1;
				system("cls");
				G->addNode(str_1);
				break;
			}
			case 3:
			{
				cout << endl << "Enter nodes name: ";
				cin >> str_1;
				system("cls");
				G->deleteNode(str_1);
				break;
			}
			case 2:
			{
				cout << endl << "Enter nodes names: ";
				cin >> str_1 >> str_2;
				system("cls");
				G->addEdge(str_1, str_2);
				break;
			}
			case 4:
			{
				cout << endl << "Enter nodes names: ";
				cin >> str_1 >> str_2;
				system("cls");
				G->deleteEdge(str_1, str_2);
				break;
			}
			case 5:
			{
				/*cout << endl << "Enter a file name: ";
				cin >> str_1;
				system("cls");
				G->edgesFromFile(str_1);*/
				break;
			}
			case 6:
			{
				cout << endl << "Nodes: " << G->countOfNodes()
					<< endl << "Edges: " << G->countOfEdges()
					<< endl;
				Sleep(1000);
				system("cls");
				break;
			}
			case 7:
			{
				if (G->countOfNodes() == 0)
				{
					cout << "No nodes" << endl;
					Sleep(1000);
					system("cls");
					break;
				}
				G->showNodes();
				Sleep(1000);
				system("cls");
				break;
			}
			case 8:
			{
				if (G->countOfEdges() == 0)
				{
					cout << "No edges";
					Sleep(1000);
					system("cls");
					break;
				}
				G->showEdges();
				Sleep(1000);
				system("cls");
				break;
			}
			case 9:
			{
				cout << endl << "Enter a nodes name: ";
				cin >> str_1;
				int degree = G->nodeDegree(str_1);
				if (degree == -1)
				{
					cout << "No nodes with this name" << endl;
				}
				else
				{
					cout << "Node degree: " << degree;
				}
				Sleep(1000);
				system("cls");
				break;
			}
			case 10:
			{
				Graph<string>::Node_Iterator G_iterator(*G);
				while (choise != 7)
				{
					cout << endl << "1. Next node" << endl;
					cout << "2. Previous node" << endl;
					cout << "3.Get adjacent nodes" << endl;
					cout << "4.Get incident edges" << endl;
					cout << "5.Get current node" << endl;
					cout << "6.Delete current node" << endl;
					cout << "7.Exit" << endl;
					cout << "Your choise: ";
					cin >> choise;

					switch (choise)
					{
					case 1:
					{
						if (!G_iterator.next())
						{
							cout << endl << "There isn't next node" << endl;
						}
						else
						{
							cout << endl << "Iterator moved to next nodes" << endl;
						}
						Sleep(1000);
						system("cls");
						break;
					}
					case 2:
					{
						if (!G_iterator.prev())
						{
							cout << endl << "There isn't previous node" << endl;
						}
						else
						{
							cout << endl << "Iterator moved to previous nodes" << endl;
						}
						Sleep(1000);
						system("cls");
						break;
					}
					case 3:
					{
						G_iterator.getAdjacentNodes();
						Sleep(1000);
						system("cls");
						break;
					}
					case 4:
					{
						G_iterator.getIncidentEdges(); Sleep(1000);
						system("cls");

						break;
					}
					case 5:
					{
						G_iterator.getCurrent();
						Sleep(1000);
						system("cls");
						break;
					}
					case 6:
					{
						G_iterator.deleteNode();
						break;
					}
					default:
						Sleep(1000);
						system("cls");
						break;
					}
				}
				break;
			}

			case 18:
			{
				Graph<string>::Const_Node_Iterator G_iterator(*G);
				while (choise != 6)
				{
					cout << endl << "1. Next node" << endl;
					cout << "2. Previous node" << endl;
					cout << "3.Get adjacent nodes" << endl;
					cout << "4.Get incident edges" << endl;
					cout << "5.Get current node" << endl;
					cout << "6.Exit" << endl;
					cout << "Your choise: ";
					cin >> choise;

					switch (choise)
					{
					case 1:
					{
						if (G_iterator.next() == false)
						{
							cout << endl << "There isn't next node" << endl;
						}
						else
						{
							cout << endl << "Iterator moved to next nodes" << endl;
						}
						Sleep(1000);
						system("cls");
						break;
					}
					case 2:
					{
						if (G_iterator.prev() == false)
						{
							cout << endl << "There isn't previous node" << endl;
						}
						else
						{
							cout << endl << "Iterator moved to previous nodes" << endl;
						}
						Sleep(1000);
						system("cls");
						break;
					}
					case 3:
					{
						G_iterator.getAdjacentNodes();
						Sleep(1000);
						system("cls");
						break;
					}
					case 4:
					{
						G_iterator.getIncidentEdges();
						Sleep(1000);
						system("cls");
						break;
					}
					case 5:
					{
						G_iterator.getCurrent();
						Sleep(1000);
						system("cls");
						break;
					}
					default:
						Sleep(1000);
						system("cls");
						break;
					}
				}
				break;
			}
			case 16:
			{
				Graph<string>::Reverse_Node_Iterator G_iterator(*G);
				while (choise != 7)
				{
					cout << endl << "1. Next node" << endl;
					cout << "2. Previous node" << endl;
					cout << "3.Get adjacent nodes" << endl;
					cout << "4.Get incident edges" << endl;
					cout << "5.Get current node" << endl;
					cout << "6.Delete current node" << endl;
					cout << "7.Exit" << endl;
					cout << "Your choise: ";
					cin >> choise;

					switch (choise)
					{
					case -1:
					{
						if (G_iterator.next() == false)
						{
							cout << endl << "There isn't next node" << endl;
						}
						else
						{
							cout << endl << "Iterator moved to next nodes" << endl;
						}
						Sleep(1000);
						system("cls");
						break;
					}
					case 2:
					{
						if (G_iterator.prev() == false)
						{
							cout << endl << "There isn't previous node" << endl;
						}
						else
						{
							cout << endl << "Iterator moved to previous nodes" << endl;
						}
						Sleep(1000);
						system("cls");
						break;
					}
					case 3:
					{
						G_iterator.getAdjacentNodes();
						Sleep(1000);
						system("cls");
						break;
					}
					case 4:
					{
						G_iterator.getIncidentEdges();
						Sleep(1000);
						system("cls");
						break;
					}
					case 5:
					{
						G_iterator.getCurrent();
						Sleep(1000);
						system("cls");
						break;
					}
					case 6:
					{
						G_iterator.deleteNode();
						break;
					}
					default:
						Sleep(1000);
						system("cls");
						break;
					}
				}
				break;
			}


			case 12:
			{
				cout << endl << "Enter the node's name: ";
				cin >> str_1;
				//cout << str_1;
				if (G->isNodeExist(str_1) == -1)
				{
					cout << endl << "This node doesn't exist" << endl;
				}
				else
				{
					cout << endl << "This node exists" << endl;
				}
				Sleep(1000);
				system("cls");
				break;
			}
			case 11:
			{
				Graph<string>::Edge_Iterator G_iterator(*G);
				while (choise != 5)
				{
					cout << endl << "1. Next edge" << endl;
					cout << "2. Previous edge" << endl;
					cout << "3. Show current edge" << endl;
					cout << "4. Delete current edge" << endl;
					cout << "5. Exit" << endl;
					cout << endl << "Your choice: ";
					cin >> choise;

					switch (choise)
					{
					case 1:
					{
						
							if (G_iterator.next() == false)
							{
								cout << endl << "There isn't next edge" << endl;
								Sleep(1000);
								system("cls");
							}
							else
							{
								cout << endl << "Iterator moved to next edge" << endl;
								Sleep(1000);
								system("cls");
							}
						
						
						break;
					}
					case 2:
					{
						if (G_iterator.prev() == false)
						{
							cout << endl << "There isn't previous edge" << endl;
							Sleep(1000);
							system("cls");
						}
						else
						{
							cout << endl << "Iterator moved to previous edge" << endl;
							Sleep(1000);
							system("cls");
						}
						break;
					}
					case 3:
					{
						if (G_iterator.currentEdge().first == -1)
						{
							cout << "There aren't any edges" << endl;
							Sleep(1000);
							system("cls");
							break;
						}
						cout << G_iterator.currentEdge().first << " - " << G_iterator.currentEdge().second << endl;
						Sleep(1000);
						system("cls");
						break;
					}
					case 4:
					{
						G_iterator.deleteEdge();
						break;
					}

					default:
						Sleep(1000);
						system("cls");
						break;
					}
				}
				break;
			}
			case 19:
			{
				Graph<string>::Const_Edge_Iterator G_iterator(*G);
				while (choise != 4)
				{
					cout << endl << "1. Next edge" << endl;
					cout << "2. Previous edge" << endl;
					cout << "3. Show current edge" << endl;
					cout << "4. Exit" << endl;
					cout << endl << "Your choice: ";
					cin >> choise;

					switch (choise)
					{
					case 1:
					{

						if (G_iterator.next() == false)
						{
							cout << endl << "There isn't next edge" << endl;
							Sleep(1000);
							system("cls");
						}
						else
						{
							cout << endl << "Iterator moved to next edge" << endl;
							Sleep(1000);
							system("cls");
						}


						break;
					}
					case 2:
					{
						if (G_iterator.prev() == false)
						{
							cout << endl << "There isn't previous edge" << endl;
							Sleep(1000);
							system("cls");
						}
						else
						{
							cout << endl << "Iterator moved to previous edge" << endl;
							Sleep(1000);
							system("cls");
						}
						break;
					}
					case 3:
					{
						if (G_iterator.currentEdge().first == -1)
						{
							cout << "There aren't any edges" << endl;
							Sleep(1000);
							system("cls");
							break;
						}
						cout << G_iterator.currentEdge().first << " - " << G_iterator.currentEdge().second << endl;
						Sleep(1000);
						system("cls");
						break;
					} 
					default:
						Sleep(1000);
						system("cls");
						break;
					}
				}
				break;
			}
			case 17:
			{
				Graph<string>::Reverse_Edge_Iterator G_iterator(*G);
				while (choise != 5)
				{
					cout << endl << "1. Next edge" << endl;
					cout << "2. Previous edge" << endl;
					cout << "3. Show current edge" << endl;
					cout << "4. Delete current edge" << endl;
					cout << "5. Exit" << endl;
					cout << endl << "Your choice: ";
					cin >> choise;

					switch (choise)
					{
					case 1:
					{

						if (G_iterator.next() == false)
						{
							cout << endl << "There isn't next edge" << endl;
							Sleep(1000);
							system("cls");
						}
						else
						{
							cout << endl << "Iterator moved to next edge" << endl;
							Sleep(1000);
							system("cls");
						}


						break;
					}
					case 2:
					{
						if (G_iterator.prev() == false)
						{
							cout << endl << "There isn't previous edge" << endl;
							Sleep(1000);
							system("cls");
						}
						else
						{
							cout << endl << "Iterator moved to previous edge" << endl;
							Sleep(1000);
							system("cls");
						}
						break;
					}
					case 3:
					{
						if (G_iterator.currentEdge().first == -1)
						{
							cout << "There aren't any edges" << endl;
							Sleep(1000);
							system("cls");
							break;
						}
						cout << G_iterator.currentEdge().first << " - " << G_iterator.currentEdge().second << endl;
						Sleep(1000);
						system("cls");
						break;
					}
					case 4:
					{
						G_iterator.deleteEdge();
						break;
					}

					default:
						Sleep(1000);
						system("cls");
						break;
					}
				}
				break;
			}
			case 13:
			{
				cout << endl << "Enter a nodes names: ";
				cin >> str_1 >> str_2;
				if (G->isEdgeExist(str_1, str_2) != -1)
				{
					cout << endl << "This edge exist" << endl;
				}
				else
				{
					cout << endl << "This edge doesn't exist" << endl;
				}
				Sleep(1000);
				system("cls");
				break;
			}
			case 14:
			{
				(G->empty() == true) ? cout << endl << "Empty" << endl : cout << endl << "Not empty" << endl;
				Sleep(1000);
				system("cls");
				break;
			}
			case 15:
			{
				G->clear();
				Sleep(1000);
				system("cls");
				break;
			}
			default: break;
		   }
	}
		return 0;
}

