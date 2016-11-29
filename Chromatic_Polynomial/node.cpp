#include "node.h"
#include <algorithm>

Node::Node(string v) : value(v)
{

}

void Node::addNeighbor(Node* addNode){
    neighbors.push_back(addNode);
}

void Node::removeNeighbor(Node* remNode){
    auto it = find(neighbors.begin(), neighbors.end(), remNode);

    if(it != neighbors.end()){
        neighbors.erase(it);
    }
}

bool Node::hasNeighbor(Node* node) const{
    return (find(neighbors.begin(), neighbors.end(), node) != neighbors.end());
}
