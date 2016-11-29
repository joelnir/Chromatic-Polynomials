#ifndef NODE_H
#define NODE_H
#include <vector>

using namespace std;

class Node
{
public:
    Node();

    vector<Node*> Neighbors;
};

#endif // NODE_H
