#include <iostream>

#include "graph.h"
#include "node.h"
#include "poly.h"


using namespace std;

int main()
{

    Poly* a = Poly::getTreePoly(5);
    cout << a->toString() << endl;

    /*
    Poly a(0, 1);
    Poly b(1, 1);
    Poly c(2, 1);

    Poly d;
    d.add(a);
    d.add(b);

    Poly e;
    e.add(a);
    e.add(c);

    d.mult(e);
    cout << d.toString() << endl;
    */
}

Poly* getChromaticPoly(Graph* g){

}
