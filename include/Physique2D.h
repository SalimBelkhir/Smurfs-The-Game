#ifndef PHYSIQUE2D_H
#define PHYSIQUE2D_H
#include <iostream>
using namespace std ;

class Physique2D
{
   public:
        float X,Y ;
    public:
        Physique2D(float x=0, float y=0 ):X(x),Y(y) {}
        virtual ~Physique2D() {}
        Physique2D operator+(const Physique2D& autre){
            Physique2D res ;
            res.X = X + autre.X ;
            res.Y = Y + autre.Y ;
            return res ;
        }
        Physique2D operator-(const Physique2D& autre){
            return Physique2D(X-autre.X , Y-autre.Y);
        }
        Physique2D operator*(float scalaire){
            return Physique2D(X*scalaire,Y*scalaire);
        }
        friend ostream& operator<<(ostream& os,const Physique2D& vec){
            os << "(" << vec.X <<","<<vec.Y<<")"<<endl ;
            return os ;
        }
};

#endif // PHYSIQUE2D_H
