#include "graph.h"
#include <algorithm>

Graph::Graph(Node* startNode): start(startNode)
{

}

bool Graph::isTree(pair<Node*, Node*>* foundCycle) const{
    vector<Node*> visited;
    return treeRec(start, nullptr, visited, foundCycle);
}

int Graph::grade() const{

}

bool Graph::treeRec(Node* current, Node* pre, vector<Node*> visited, pair<Node*, Node*> *found) const{
    if(current->Neighbors.empty()){
        //Single Node
        return true;
    }

    visited.push_back(current);

    for(Node* node: current->Neighbors){
        if(node != pre){
            if(find(visited.begin(), visited.end(), node) != visited.end()){
                found->first = current;
                found->second = node;
                return false;
            }
            else if(!treeRec(node, current, visited, found)){
                return false;
            }
        }
    }

    return true;
}
