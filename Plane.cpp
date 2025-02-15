#include "Plane.hpp"
#include "rt.hpp"
#include "Vec.hpp"

Plane::Plane(double d, Vec Normal, Color col1, Color col2, bool Checker) {
    this->D = d;
    this->normal = Normal;
    this->color = col1;
    this->checker = Checker;
    this->color2 = col2;
}

bool Plane::intersect(RAY_T ray, Object *obj, double *t, Vec *int_pt, Vec *normal_vec) {
    double dp = this->normal.dot(ray.dir);
    if(dp == 0){ //No intersection
        return false;
    } else {
        *t = -(this->normal.dot(ray.origin) + this->D) / dp;
        if(*t <= 0){ //No intersection, intersection behind point
            return false;
        } else {
            //int_pt calculations
            (*int_pt) = ray.dir * (*t);

            *normal_vec = this->normal; //Normal is plane normal
            return true;
        }
    }
}
