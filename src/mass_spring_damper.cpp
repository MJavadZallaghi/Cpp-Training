#include <iostream>

class MassSpringDamper
{
private:
    // States of the System
    float x;
    float x_dot;

    // Syatem Parameters
    float I;
    float K;
    float B;

    // Input Value
    float U;

public:
    // Mass Spring Damper Constructor
    MassSpringDamper(float I_def, float K_def, float B_def, float x_init, float x_dot_init) {
        I = I_def;
        K = K_def;
        B = B_def;
        x = x_init;
        x_dot = x_dot_init;
    }

    // Calculation methods

    void setInput(float U_inp) {
        U = U_inp;
    }

    void simulateSystem(float dt) {
        // m*xdd = F - b*xd - k*x  --> xdd = 1/m * (F - b*xd - k*x)
        x_dot += dt *  1/I * (U - B*x_dot - K*x);
        x += dt * x_dot;
    }

    void print_state() {
        std::cout << "X: " << x <<std::endl;
        std::cout << "V: " << x_dot <<std::endl;
    }

    // Object destructor
    ~MassSpringDamper() {
        // How to mamage resources here?
    }
};