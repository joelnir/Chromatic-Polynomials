#include <iostream>
#include <fstream>

#include "graph.h"
#include "node.h"
#include "poly.h"


using namespace std;

Graph* getGraph(string& fileName);
Poly* getChromaticPoly(Graph* g);

int main()
{
    bool run = true;
    string fileName;

    cout << "Chromatic Polynomial Calculator" << endl;

    while(run){
        cout << endl <<  "Input filename: ";
        cin >> fileName;

        Graph* g = getGraph(fileName);

        if(g == nullptr){
            //Failed to read file
            if(fileName == "quit"){
                run = false;
            }
            else{
                cout << "Could not read file" << endl;
            }
        }
        else{
            //Calculate
            Poly* graphP = getChromaticPoly(g);

            cout << endl << graphP->toString() << endl;

            string selection;
            cout << "Continue?: ";
            cin >> selection;

            if(selection.at(0) == 'n' || selection.at(0) == 'N'){
                run = false;
            }

            //TODO Fix memory leaks
        }
    }
}

Poly* getChromaticPoly(Graph* g){
    //check if tree
    pair<Node*, Node*>* cycle = new pair<Node*, Node*>(nullptr, nullptr);

    Graph* g1 = g->copy();

    if(g1->isTree(cycle)){
        return Poly::getTreePoly(g->grade());
    }
    else{
        g1->removeEdge(cycle->first, cycle->second);

        //Do same, but contract for g2
        Graph* g2 = g->copy();
        g2->isTree(cycle);
        g2->contract(cycle->first, cycle->second);

        Poly* posPoly = getChromaticPoly(g1);
        Poly* negPoly = getChromaticPoly(g2);

        Poly negOne = Poly(0, -1);

        negPoly->mult(negOne);

        posPoly->add(*negPoly);

        return posPoly;
    }

    return Poly::getTreePoly(1);
}

Graph* getGraph(string& fileName){
    /* file content example:
     * a b c d e
     * a-b a-c c-d b-d d-e
     */

    ifstream fStream(fileName);

    if(fStream.is_open()){
        //Read
        char tmpChar;
        map<char, Node*> nodeList;

        do{
            tmpChar = fStream.get();

            //Make Node
            Node* newNode = new Node(string(1, tmpChar));
            nodeList.insert(pair<char, Node*>(tmpChar, newNode));

            tmpChar = fStream.get();

        }while(tmpChar != ';');

        fStream.get();

        char endChar;
        do{
            char c1 = fStream.get();
            fStream.get();
            char c2 = fStream.get();

            //Make connection
            Node* n1 = nodeList.at(c1);
            Node* n2 = nodeList.at(c2);

            n1->addNeighbor(n2);
            n2->addNeighbor(n1);

            endChar = fStream.get();
        }while(endChar != ';');

        fStream.close();

        return new Graph(nodeList.begin()->second);
    }
    else{
        return nullptr;
    }
}
