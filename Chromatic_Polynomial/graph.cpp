#include "graph.h"
#include <algorithm>
#include <iostream>

Graph::Graph(Node* startNode): start(startNode)
{

}

bool Graph::isTree(pair<Node*, Node*>* foundCycle) const{
    vector<Node*> visited;
    return treeRec(start, nullptr, &visited, foundCycle);
}

int Graph::grade() const{
    vector<Node*> visited;
    countHelp(start, &visited);
    return visited.size();
}

bool Graph::treeRec(Node* current, Node* pre, vector<Node*>* visited, pair<Node*, Node*> *found) const{
    if(current->neighbors.empty()){
        //Single Node
        return true;
    }

    visited->push_back(current);

    for(Node* node: current->neighbors){
        if(node != pre){
            if(find(visited->begin(), visited->end(), node) != visited->end()){
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

void Graph::countHelp(Node* current, vector<Node*>* visited) const{
    visited->push_back(current);

    for(Node* neighbor : current->neighbors){
        if(find(visited->begin(), visited->end(), neighbor) == visited->end()){

            countHelp(neighbor, visited);
        }
    }
}

Graph* Graph::copy() const{
    map<Node*, Node*> newNodes;
    copyHelp(start, &newNodes);

    return new Graph(newNodes.begin()->second);
}

void Graph::copyHelp(Node* current, map<Node*, Node*>* created) const{
    Node* newNode = new Node(current->value);
    created->insert(pair<Node*, Node*>(current, newNode));

    for(Node* neighbor : current->neighbors){
        if(created->find(neighbor) == created->end()){
            //has not been created
            copyHelp(neighbor, created);
        }

        newNode->addNeighbor(created->at(neighbor));
    }
}

void Graph::contract(Node* n1, Node* n2){
    //Use n1 as contracted node

    for(Node* n2Neighbor : n2->neighbors){
        n2Neighbor->removeNeighbor(n2);

        if(!n2Neighbor->hasNeighbor(n1) && (n2Neighbor != n1)){
            n2Neighbor->addNeighbor(n1);
            n1->addNeighbor(n2Neighbor);
        }
    }

    if(n2 == start){
        start = n1;
    }

    delete n2;
}

void Graph::removeEdge(Node* n1, Node* n2){
    n1->removeNeighbor(n2);
    n2->removeNeighbor(n1);
}
