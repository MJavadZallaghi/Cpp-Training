#include "pid_controller.hpp"

// PID constructor
PID_Controller::PID_Controller(float Kp_def, float Kd_def, float Ki_def) {
    Kp = Kp_def;
    Kd = Kd_def;
    Ki = Ki_def;
    loop_counter = 0;
}

// PID Computer 
float PID_Controller::compute(float signal_val, float setpoint_val, float dt_def) {
    signal_value = signal_val;
    set_point = setpoint_val;
    dt = dt_def;

    Error_Updater();

    U = Kp * error + Kd * error_drivative + Ki * error_integral;
    return U;
}

void PID_Controller::Error_Updater() {
    if (loop_counter == 0) {
        error = set_point - signal_value;
        error_previous = 0;
        error_drivative = 0;
        error_integral = 0;
    }
    else {
        error_previous = error;
        error = set_point - signal_value;
        error_drivative = (error - error_previous)/dt;
        error_integral += (error_previous)*dt;
    }
    // Increase the loop counter
    loop_counter++;
}

