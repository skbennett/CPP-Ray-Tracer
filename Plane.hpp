#ifndef PLANE_HPP
#define PLANE_HPP

#include "Vec.hpp"
#include "rt.hpp"
#include "Object.hpp"

class Plane : public Object{
    private:
    //Plane Parameters
    double D;
    Vec normal;

    public:
    Plane(double d, Vec Normal, Color col1, Color col2, bool Checker); //Constructor
    //intersect_plane function
    bool intersect(RAY_T ray, Object *obj, double *t, Vec *int_pt, Vec *normal) override;
};

#endif
