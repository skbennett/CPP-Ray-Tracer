#ifndef VEC_HPP
#define VEC_HPP

#include <cmath>

class Vec{
    private:
        double x, y, z; //Directions

    public:
        Vec(double X, double Y, double Z){ //Constructor with paramaters
            x = X;
            y = Y;
            z = Z;
        }
        inline Vec(){
            x = 0;
            y = 0;
            z = 0;
        }

        void set(double X, double Y, double Z); //Set x,y,z

        Vec normalize(); //Normalize Vector

        inline double len() { //Magnitude of vector
            return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
        }
        inline double dot(Vec vec){ //Dot Product
            return (this->x * vec.x) + (this->y * vec.y) + (this->z * vec.z);
        }
        double distance(Vec vec2); //Distance between 2 vectors

        //Adding Functions
        Vec operator+(Vec vec) const;
        Vec add(Vec vec);
        //Subtraction Functions
        Vec operator-(Vec vec);
        Vec sub(Vec vec);
        //Mult Functions
        Vec operator*(Vec vec);
        Vec mult(Vec vec);
        //Scalar Mult Functions
        Vec operator*(double num);
        Vec scalar_mult(double num);
        //Scalar Div Functions
        Vec operator/(double num);
        Vec scalar_divide(double num);

        inline double sum_components(); //Sum of x,y,z

        int sum_floor_components(); //Sum of floors of x,y,z
};

#endif
