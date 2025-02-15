#include "Color.hpp"

Color Color::operator+(Color col) const{ //Color + operator overload
    Color new_col;
    new_col.R = this->R + col.R;
    new_col.G = this->G + col.G;
    new_col.B = this->B + col.B;
    return new_col;
}
Color Color::operator+(double num) const{ //Double + operator overload
    Color new_col;
    new_col.R = this->R + num;
    new_col.G = this->G + num;
    new_col.B = this->B + num;
    return new_col;
}
Color Color::add(Color col) const{ //Color add
    return *this + col;
}
Color Color::add(double num) const{ //Double add
    return *this + num;
}
//Mult
Color Color::operator*(double num) const{ //Multiplies each value by a double
    Color new_col;
    new_col.R = this->R * num;
    new_col.G = this->G * num;
    new_col.B = this->B * num;
    return new_col;
}
Color Color::scalar_mult(double num) const{ //Multiplies each value by a double
    return *this * num;
}

void Color::cap(void){ //Caps Color Values at 1. No Return
    if(this->R > 1){
        this->R = 1;
    }
    if(this->G > 1){
        this->G = 1;
    }
    if(this->B > 1){
        this->B = 1;
    }
}