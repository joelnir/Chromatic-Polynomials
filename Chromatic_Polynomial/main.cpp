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
        }
    }
}

Poly* getChromaticPoly(Graph* g){
    //check if tree
    pair<Node*, Node*> cycle;

    if(g->isTree(cycle)){
        return Poly::getTreePoly(g->grade());
    }
    else{
        Graph* g1 =g->copy();
        Graph* g2 =g->copy();
        g1->removeEdge(cycle.first, cycle.second);
        g2->contract(cycle.first, cycle.second);

        Poly* posPoly = getChromaticPoly(g1);
        Poly* negPoly = getChromaticPoly(g1);

        negPoly->mult(Poly(0, -1));

        posPoly->add(*negPoly);

        return posPoly;
    }

    return Poly::getTreePoly(1);
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
