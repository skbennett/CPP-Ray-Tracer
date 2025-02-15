#include <iostream>
#include <fstream>
using namespace std;

#include "rt.hpp"
#include "Vec.hpp"
#include "Scene.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Light.hpp"

Color trace(RAY_T ray, SCENE_T scene, Light light){
    //Getting list and Light from scene
    Object* list = scene.objs;

    Color pixel_col; //Color to return
    Color background_color = Color(0.3, 0.3, 0.5); //Blue Color

    double closest_t = -1; //Closest value of t
    Vec closest_int_pt; //Int_pt for closest object
    Vec closest_normal; //Normal vector for closest object
    int closest_object_index = -1; //List index of closest object

    double t; //t for calculation
    Vec int_pt; //int_pt for calculation
    Vec normal; //normal for calculation

    Object* curr; //Current Linked List object
    int current_index = -1;
    for(curr = list; curr != nullptr; curr = curr->next){ //For loop over linked list
        current_index += 1;
        if(curr->intersect(ray, curr, &t, &int_pt, &normal)){
            if(closest_t < 0 || t < closest_t){ //Changes values to new closest intersection
                closest_t = t;
                closest_normal = normal;
                closest_int_pt = int_pt;
                closest_object_index = current_index;
            }
        }
    }

    if(closest_object_index != -1){ //Illuminates as long as not default value
        Object* curr_obj = list;
        for(int i = 0; curr_obj != nullptr && i < closest_object_index; i++){ //parses until closest object
            curr_obj = curr_obj -> next;
        }
        if(curr_obj != nullptr){
            //Illuminate comes here
            //Coloring Pixel
            pixel_col = light.illuminate(light, ray, scene, curr_obj, closest_int_pt, closest_normal);
        }
    } else {
        pixel_col = background_color; //Sets to default color if no intersection
    }
    return pixel_col;
}



static SCENE_T init(char filename[], Light* light){
    SCENE_T scene; //Scene to return to main

    Object* list = nullptr; //Linked list for scene

    ifstream file(filename);

    char c; //Char to see type of object
    while(file >> c){ //While there are still characters in the file
        if(c == 's'){
            cout << "Initializing Sphere\n";
            double locx, locy, locz; //Location of Sphere
            double rad;              //Radius of Sphere
            double colR, colG, colB; //Color of Sphere

            //Reading Information from File
            file >> locx >> locy >> locz >> rad >> colR >> colG >> colB;

            //Printing for user
            cout <<"Sphere - Center: ("<<locx<<", "<<locy<<", "<<locz<<"), Radius "<<rad<<"\n";

            //Sphere Parameters
            Vec center(locx, locy, locz);
            Color color(colR, colG, colB);
            //Sphere Object Init
            Sphere* sphere = new Sphere(center, rad, color, color, false);
            //Linked List Formatting
            sphere->next = list;
            list = sphere;

        } else if(c == 'p'){
            cout << "Initializing Plane\n";
            double normx, normy, normz; //Normal Vector of Plane
            double D;                   //D value of plane
            double col1R, col1G, col1B;
            double col2R, col2G, col2B;

            //Reading information from file
            file >> normx>>normy>>normz>>D>>col1R>>col1G>>col1B>>col2R>>col2G>>col2B;

            //Printing for user
            cout <<"Plane - Normal: ("<<normx<<", "<<normy<<", "<<normz<<") D - "<<D<<"\n";

            //Plane Init
            Vec normal(normx, normy, normz);
            Color col1(col1R, col1G, col1B);
            Color col2(col2R, col2G, col2B);

            Plane* plane = new Plane(D, normal, col1, col2, true);

            //Linked List Formatting
            plane->next = list;
            list = plane;

        } else if(c == 'l'){
            cout << "Initializing Light\n";
            double locx, locy, locz;
            file >> locx >> locy >> locz; //String to light parameters

            *light = Light(Vec(locx, locy, locz));
            //printing for user
            cout <<"Light - Location ("<<locx<<", "<<locy<<", "<<locz<<")\n";
        }
    }
    file.close(); //Close File
    scene.objs = list;
    return scene;
}

int main(){
    Light light; //Scene Light
    SCENE_T scene = init((char*)"scene1.txt", &light);

    ofstream image_file("img.ppm");

    //Image Formatting
    int rows, cols;
    rows = 480;
    cols = 640;
    scene.pix_size = (double)1 / (double)rows;
    scene.start_y = 0.5;
    scene.start_x = -((double)cols / (double)rows) / 2;

    //PPM Formatting
    image_file << "P6\n";
    image_file << cols << " " << rows << "\n";
    image_file << "255" << endl;

    for(int y = 0; y < rows; y++){ //y loop
        for(int x = 0; x < cols; x++){ //x loop

            //Initializing Ray for Pixel
            struct RAY_T ray;
            ray.origin = Vec(0, 0, 0);

            Vec direction;
            direction.set(scene.start_x + x * scene.pix_size, scene.start_y - y * scene.pix_size, 1);

            ray.dir = direction.normalize(); //Normalized direction of light through image plane

            Color pixel_col = trace(ray, scene, light);

            //PPM Output: WORKING
            double R = pixel_col.get_r();
            double G = pixel_col.get_g();
            double B = pixel_col.get_b();

            image_file << char(R * 255.0) << char(G * 255.0) << char(B * 255.0);
        }
    }
    image_file.close();
    return 0;
}