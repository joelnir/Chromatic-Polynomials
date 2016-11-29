#ifndef GRAPH_H
#define GRAPH_H

#include <set>
#include "node.h"

using namespace std;

class Graph
{
public:
    Graph(Node* startNode);

    bool isTree(pair<Node*, Node*>* foundCycle = new pair<Node*, Node*>) const;

    int grade() const;
private:
    Node* start;
    bool treeRec(Node* current, Node* pre, vector<Node*> visited, pair<Node*, Node*> *found) const;


};

#endif // GRAPH_H
