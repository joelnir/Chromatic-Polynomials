#include <iostream>
#include <fstream>

#include "graph.h"
#include "node.h"
#include "poly.h"


using namespace std;

Graph* getGraph(string& fileName);

int main()
{
    /*
    Node* a = new Node("a");
    Node* b = new Node("b");
    Node* c = new Node("c");
    Node* d = new Node("d");
    Node* e = new Node("e");

    a->addNeighbor(b);
    a->addNeighbor(c);

    b->addNeighbor(a);
    b->addNeighbor(d);

    c->addNeighbor(d);
    c->addNeighbor(a);

    d->addNeighbor(c);
    d->addNeighbor(b);
    d->addNeighbor(e);

    e->addNeighbor(d);

    Graph* g = new Graph(a);

    pair<Node*, Node*> edge;
    cout << g->isTree(&edge) << endl;
    cout << g->grade() << endl;

    g->contract(edge.first, edge.second);
    cout << g->isTree(&edge) << endl;
    cout << g->grade() << endl;

    g->contract(edge.first, edge.second);
    cout << g->isTree(&edge) << endl;
    cout << g->grade() << endl;
    */
    string graphFile = "g1.txt";
    Graph* g = getGraph(graphFile);
}

Poly* getChromaticPoly(Graph* g){
    //TODO implement
}

Graph* getGraph(string& fileName){
    //TODO implement reading graph from filefile:///F:/Repos/chromatic poly/Chromatic_Polynomial/res/g1.txt

    /* file content:
     * a b c d e
     * a-b a-c c-d b-d d-e
     */

    ifstream fStream(fileName);

    if(fStream.is_open()){
        //Read
        char tmpChar;

        do{
            tmpChar = fStream.get();
            cout << tmpChar << endl;
        }while(true);
    }
    else{
        cout << "no read" << endl;
        return nullptr;
    }

    fStream.close();
}
