#include "Vec.hpp"
#include <cmath>

void Vec::set(double X, double Y, double Z) { //Set x,y,z
    this->x = X;
    this->y = Y;
    this->z = Z;
}
Vec Vec::normalize() { //Normalize Vector
    Vec new_vec;
    double mag = this->len();
    double x = this->x / mag;
    double y = this->y / mag;
    double z = this->z / mag;
    new_vec.set(x, y, z);
    return new_vec;
}
double Vec::distance(Vec vec2) {
    return sqrt((vec2.x - this->x) * (vec2.x - this->x) +
                   (vec2.y - this->y) * (vec2.y - this->y) +
                   (vec2.z - this->z) * (vec2.z - this->z));
}
//Adding functions
Vec Vec::operator+(Vec vec) const {
    Vec new_vec;
    double x = this->x + vec.x;
    double y = this->y + vec.y;
    double z = this->z + vec.z;
    new_vec.set(x, y, z);
    return new_vec;
}
Vec Vec::add(Vec vec){
    return *this + vec;
}
//Subraction functions
Vec Vec::operator-(Vec vec){
    Vec new_vec;
    double x = this->x - vec.x;
    double y = this->y - vec.y;
    double z = this->z - vec.z;
    new_vec.set(x, y, z);
    return new_vec;
}
Vec Vec::sub(Vec vec){
    return *this - vec;
}
//Mult Functions
Vec Vec::operator*(Vec vec) {
    Vec new_vec;
    double x = this->x * vec.x;
    double y = this->y * vec.y;
    double z = this->z * vec.z;
    new_vec.set(x, y, z);
    return new_vec;
}
Vec Vec::mult(Vec vec) {
    return *this * vec;
}
//Scalar Mult Functions
Vec Vec::operator*(double num){
    Vec new_vec;
    double x = this->x * num;
    double y = this->y * num;
    double z = this->z * num;
    new_vec.set(x, y, z);
    return new_vec;
};
Vec Vec::scalar_mult(double num) {
    return *this * num;
}
//Scalar Division Functions
Vec Vec::operator/(double num) {
    Vec new_vec;
    double x = this->x / num;
    double y = this->y / num;
    double z = this->z / num;
    new_vec.set(x, y, z);
    return new_vec;
}
Vec Vec::scalar_divide(double num) {
    return *this / num;
}

inline double Vec::sum_components() {
    return this->x + this->y + this->z;
}

int Vec::sum_floor_components() {
    return floor(this->x) + floor(this->y) + floor(this->z);
}