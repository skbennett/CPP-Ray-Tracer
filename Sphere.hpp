#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "Vec.hpp"
#include "rt.hpp"
#include "Object.hpp"

class Sphere: public Object {
    private:
    //Parameters of Sphere
    Vec center;
    double radius;

    public:
    Sphere(Vec Center, double Radius, Color Col1, Color Col2, bool Checker); //Constructor
    //intersect_sphere function
    bool intersect(RAY_T ray, Object *obj, double *t, Vec *int_pt, Vec *normal) override;
};
#endif
