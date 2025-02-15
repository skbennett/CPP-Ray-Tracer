#ifndef COLOR_HPP
#define COLOR_HPP

class Color{
    private:
    double R, G, B; //RGB values

    public:
    Color(){ //Constructor with no parameters
        R = 0;
        G = 0;
        B = 0;
    }
    Color(double r, double g, double b){ //Constructor with parameters
        R = r;
        G = g;
        B = b;
    }
    //Inline Get Functions for R, G, B
    inline double get_r() const{
        return R;
    }
    inline double get_g() const{
        return G;
    }
    inline double get_b() const{
        return B;
    }
    //Add
    Color operator+(Color col) const; //Color + operator overload

    Color operator+(double num) const; //Double + operator overload

    Color add(Color col) const; //Color add

    Color add(double num) const; //Double add

    //Mult
    Color operator*(double num) const; //Multiplies each value by a double

    Color scalar_mult(double num) const; //Multiplies each value by a double

    void cap(void); //Caps Color Values at 1. No Return
};
#endif