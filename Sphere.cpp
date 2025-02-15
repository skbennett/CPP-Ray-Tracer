#include "Sphere.hpp"
#include <cmath>

Sphere::Sphere(Vec Center, double Radius, Color Col1, Color Col2, bool Checker) { //Sphere Constructor
    this->center = Center;
    this->radius = Radius;
    this->color = Col1;
    this->checker = Checker;
    this->color2 = Col2;
}

bool Sphere::intersect(RAY_T ray, Object *obj, double *t, Vec *int_pt, Vec *normal) {
    double A = 1;
    double B = 2 * ray.dir.dot(ray.origin - this->center);
    double C = (ray.origin - this->center).dot((ray.origin - this->center)) - (this->radius * this->radius);


    if(((B * B) - (4 * A * C)) <= 0){ //Discriminant <= 0, no intersection
        return false;

    } else { //Discriminant > 0, intersection

        double t1 = (-B + sqrt((B * B) - (4 * A * C))) / (2 * A); //1st value of t
        double t2 = (-B - sqrt((B * B) - (4 * A * C))) / (2 * A); //2nd value of t

        if(t1 > 0 && t2 > 0){ //both positive
            if(t1 < t2){ //t1 smaller
                *t = t1;
                //return 1;
            } else { //t2 smaller
                *t = t2;
                //return 1;
            }
        } else if(t1 > 0 && t2 < 0){ //only t1 positive
            *t = t1;
            //return 1;
        } else if(t2 > 0 && t1 < 0){ //only t2 positive
            *t = t2;
            //return 1;
        } else {
            return false;
        }

        //int_pt calculations
        *int_pt = ray.dir * (*t);

        //normal vector calculations
        Vec norm = *int_pt - this->center;
        *normal = norm.normalize();//sets normal vector in memory to normalized normal vector

        return true; //Intersection Occurs
    }
}