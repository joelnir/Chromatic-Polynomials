#ifndef POLY_H
#define POLY_H

#include <string>
#include <map>
#include <functional>

using namespace std;


class Poly
{
public:
    Poly();
    Poly(const int grade, const int value);

    void copy(Poly* other);

    string toString(const string var = "X") const;

    function<int (int)> getFuncLambda() const;

    //toFunc() const;

    int grade() const;

    void mult(Poly& factor);
    void add(Poly& term);
    void pow(int n);

    static Poly* getTreePoly(const int grade);
private:
    map<int,int> values;

};

#endif // POLY_H
