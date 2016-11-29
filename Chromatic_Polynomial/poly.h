#ifndef POLY_H
#define POLY_H

#include <string>
#include <map>

using namespace std;


class Poly
{
public:
    Poly();

    string toString() const;
    string toString(const string var) const;

    //toFunc() const;

    int grade() const;

    void mult(Poly& factor);
    void add(Poly& term);

    static Poly* getTreePoly(const int grade);
private:
    map<int,int> values;

};

#endif // POLY_H
