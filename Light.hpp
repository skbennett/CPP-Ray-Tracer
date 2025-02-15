#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "Vec.hpp"
#include "Color.hpp"
#include "rt.hpp"
#include "Scene.hpp"

class Light{
    private:
        Vec loc;

        bool shadow_test(Light light, Vec int_pt, Object* list, Vec normal);


    public:
        Light(); //Constructor

        Light(Vec location); //Constructor

        Color illuminate(Light light, RAY_T ray, SCENE_T scene, Object* obj, Vec int_pt, Vec normal); //Illuminate Method
};

#endif
