#include "Light.hpp"
#include "Vec.hpp"
#include "Color.hpp"
//Constructors
Light::Light() {
    this->loc.set(0, 0, 0);
}
Light::Light(Vec location) {
    this->loc = location;
}

bool Light::shadow_test(Light light, Vec int_pt, Object* list, Vec normal){
    RAY_T shadow_ray;
    shadow_ray.origin = int_pt;
    shadow_ray.dir = (this->loc - int_pt).normalize();

    //Offset from surface to stop random shadows
    shadow_ray.origin = shadow_ray.origin + normal * 0.001;

    //Dummy Variables
    double dummy_t;
    Vec dummy_int_pt, dummy_normal;
    //Intersect Check
    Object* curr;
    for (curr = list; curr!= nullptr; curr = curr->next){
        if(curr->intersect(shadow_ray, curr, &dummy_t, &dummy_int_pt, &dummy_normal)){
            //Intersection occurs between point and light
            if(dummy_t < int_pt.distance(light.loc)){
                return true;
            }
        }
    }
    return false;
}

Color Light::illuminate(Light light, RAY_T ray, SCENE_T scene, Object* obj, Vec int_pt, Vec normal) {
    Vec light_loc = this->loc;
    Color col; //Return Color
    Color obj_col;

    //light attenuation
    double atten = 1/(.002 * (int_pt.distance(light_loc) * int_pt.distance(light_loc)) +
            (0.02 * int_pt.distance(light_loc)) + 0.2);

    //Checker Functionality
    if(obj->checker && (int_pt.sum_floor_components() & 1)){
        obj_col = obj->color2;
    } else {
        obj_col = obj->color;
    }

    //Ambient light
    col = col + (obj_col * .1); //col.C += .1 * obj_col.C

    if(!shadow_test(light, int_pt, scene.objs, normal)){ //Nor in shadow
        //diffuse light
        Vec light_vec = (light_loc - int_pt).normalize();
        double dp = light_vec.dot(normal);
        if(dp > 0){
            col = col + (obj_col * (dp * atten));
            //Specular
            Vec ref_vec = (light_vec - normal * 2 * dp).normalize(); //Reflective Vector
            double dp2 = ref_vec.dot(ray.dir.normalize());
            if(dp2 > 0){
                col = col + pow(dp2, 200) * atten;
            }
        }
    }
    //Light Correction
    col.cap();
    return col;
}