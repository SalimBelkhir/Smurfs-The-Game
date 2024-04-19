#ifndef OBJECT_H
#define OBJECT_H


class Object
{
    public:
        Object() {}
        virtual ~Object() {}
        virtual void Draw()=0;
        virtual void Update(float dt)=0;
        virtual void Clean()=0;
};

#endif // OBJECT_H
