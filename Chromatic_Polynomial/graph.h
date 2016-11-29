#ifndef GRAPH_H
#define GRAPH_H

#include <set>
#include "node.h"

using namespace std;

class Graph
{
public:
    Graph();

    bool isTree() const;

    int grade() const;

    set<Node*> Nodes;
};

#endif // GRAPH_H
