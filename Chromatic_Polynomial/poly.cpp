#include "poly.h"
#include <sstream>
#include <cmath>

Poly::Poly()
{

}

Poly::Poly(const int grade, const int value){
    values.insert(pair<int, int>(grade, value));
}

void Poly::copy(Poly* other){
    values.clear();

    for(auto v : other->values){
        values.insert(pair<int, int>(v.first, v.second));
    }
}

string Poly::toString(const string var) const{
    if(values.empty()){
        return "0";
    }

    ostringstream s;

    for(auto v : values){
        if(v.second != 0){
            if(v.second > 0){
                s << "+";
            }

            s << v.second;

            if(v.first != 0){
                s << var << "^" << v.first;
            }
        }
    }

    return s.str();
}

void Poly::mult(Poly& factor){
    Poly temp;

    for(auto v : values){
        for(auto w : factor.values){
            Poly newPoly(v.first + w.first, v.second * w.second);

            temp.add(newPoly);
        }
    }

    values.clear();
    this->add(temp);
}

void Poly::add(Poly& term){
    for(auto v:term.values){
        auto it = values.find(v.first);

        if(it != values.end()){
            //Grade exists
            int oldValue = values.at(v.first);
            values.erase(it);

            values.insert(pair<int, int>(v.first, (v.second + oldValue)));
        }
        else{
            //Create new grade
            values.insert(pair<int,int>(v.first, v.second));
        }
    }
}

void Poly::pow(int n){
    if(n == 0){
        values.clear();
        values.insert(pair<int, int>(0, 1));
    }

    Poly copy;
    copy.copy(this);

    for(int i = 1; i < n; i++){
        this->mult(copy);
    }
}

int Poly::grade() const{
    return values.rbegin()->first;
}

Poly* Poly::getTreePoly(const int grade){
    Poly* tree = new Poly(1, 1);

    if(grade == 1){
        return tree;
    }

    Poly second(1, 1);
    Poly negOne(0, -1);
    second.add(negOne);

    second.pow(grade - 1);

    tree->mult(second);

    return tree;
}

function<int (int)> Poly::getFuncLambda() const{
    return [&](int x){
        int sum = 0;

        for(auto value: values){
            sum += value.second * std::pow(x, value.first);
        }

        return sum;
    };
}


