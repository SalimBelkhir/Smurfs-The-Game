#ifndef TRANSFORME_H
#define TRANSFORME_H
#include "Physique2D.h"
#include <iostream>
using namespace std;
class Transforme
{
    public:
        Transforme(float x=0 , float y=0) :X(x),Y(y){}
        virtual ~Transforme() {}
        void TranslateX(float x){X+=x;}
        void TranslateY(float y){Y+=y;}
        void TranslateXY(Physique2D v){X+=v.X ; Y+=v.Y ;}
        friend ostream& operator<<(ostream& os ,const Transforme& t){
            os << "(" << t.X << ","<< t.Y<<")" <<endl;
            return os;
        }
    public:
        float X,Y ;
};

#endif // TRANSFORME_H
