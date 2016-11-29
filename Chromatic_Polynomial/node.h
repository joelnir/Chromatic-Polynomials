#ifndef NODE_H
#define NODE_H
#include <list>
#include <string>

using namespace std;

class Node
{
friend class Graph;
public:
    Node(string v);

    void addNeighbor(Node* addNode);
    void removeNeighbor(Node* remNode);

    bool hasNeighbor(Node* node) const;

    string value; //TODO Remove this property
private:
    list<Node*> neighbors;
};

#endif // NODE_H
