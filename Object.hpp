#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Color.hpp"
#include "rt.hpp"

class Object{
    public:
        Color color; //Primary Color
        bool checker{}; //Boolean for Checkerboard
        Color color2;  //Secondary Color

        Object* next{}; //Next object in linked list

        virtual bool intersect(RAY_T ray, Object* obj, double *t, Vec *int_pt, Vec *normal){ //Intersect Sphere and Plane
            return false; //Default Behaviour
        }
};

#endif