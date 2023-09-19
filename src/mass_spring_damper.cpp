#include "mass_spring_damper.hpp"
#include <iostream>

MassSpringDamper::MassSpringDamper(float I_def, float K_def, float B_def, float x_init, float x_dot_init) {
    MassSpringDamper::setParams(I_def, K_def, B_def);
    MassSpringDamper::setInitialCondition(x_init, x_dot_init);
}

void MassSpringDamper::setParams(float I_def, float K_def, float B_def) {
    I = I_def;
    K = K_def;
    B = B_def;
}

void MassSpringDamper::setInitialCondition(float x_init, float x_dot_init) {
    x = x_init;
    x_dot = x_dot_init;
}

void MassSpringDamper::setInput(float U_inp) {
    U = U_inp;
}


void MassSpringDamper::simulateSystem(float dt) {
    // m*xdd = F - b*xd - k*x  --> xdd = 1/m * (F - b*xd - k*x)
    x_dot += dt *  1/I * (U - B*x_dot - K*x);
    x += dt * x_dot;
}

void MassSpringDamper::print_state() {
    std::cout << "X: " << x <<std::endl;
    std::cout << "V: " << x_dot <<std::endl;
}

float MassSpringDamper::get_pose_signal() {
    return x;
}

// Object destructor
MassSpringDamper::~MassSpringDamper() {
    // How to mamage resources here?
}