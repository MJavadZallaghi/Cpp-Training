#ifndef MASS_SPRING_DAMPER_H
#define MASS_SPRING_DAMPER_H

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
    MassSpringDamper(float I_def, float K_def, float B_def, float x_init, float x_dot_init);

    // Calculation methods
    void setInput(float U_inp);
    void simulateSystem(float dt);
    void print_state();

    // Object destructor
    ~MassSpringDamper();
};