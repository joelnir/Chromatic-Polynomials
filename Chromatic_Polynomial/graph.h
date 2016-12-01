#ifndef GRAPH_H
#define GRAPH_H

#include <set>
#include <vector>
#include <map>
#include "node.h"

using namespace std;

class Graph
{
public:
    Graph(Node* startNode);

    Graph* copy() const;

    bool isTree(pair<Node*, Node*>* foundCycle = new pair<Node*, Node*>) const;

    void contract(Node* n1, Node* n2);
    void removeEdge(Node* n1, Node* n2);

    int grade() const;
private:
    Node* start;
    bool treeRec(Node* current, Node* pre, vector<Node*>* visited, pair<Node*, Node*> *found) const;

    void countHelp(Node* current, vector<Node*>* visited) const;
    void copyHelp(Node* current, map<Node*, Node*>* created) const;
};

#endif // GRAPH_H
