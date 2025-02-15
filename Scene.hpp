#ifndef SCENE_HPP
#define SCENE_HPP

#include "Object.hpp"
#include "Vec.hpp"

class SCENE_T{
    //Image Formatting
    public:
    double start_x;
    double start_y;
    double pix_size;

    Object* objs; //Linked list of OBJ_T

    SCENE_T(){
        this->start_x = 0;
        this->start_y = 0;
        this->pix_size = 0;
        this->objs = nullptr;
    }
};
#endif