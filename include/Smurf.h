/*#ifndef SMURF_H
#define SMURF_H
#include "Character.h"

class Smurf : public ObjectGame
{
    public:
        Smurf(Properties* props);
        virtual void Draw();
        virtual void Clean();
        virtual void Update(float dt);
        void MoveForward();
        void MoveBackward();
        void Jump();

    private:
        int row , frame , framecount ;
};

#endif // SMURF_H*/
