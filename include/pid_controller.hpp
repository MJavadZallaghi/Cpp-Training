#ifndef PID_CONTROLLER_HPP
#define PID_CONTROLLER_HPP
#endif

class PID_Controller {
    private:
        // Controller gains
        float Kp;
        float Kd;
        float Ki;

        // Signal and setpoint
        float set_point;
        float signal_value;

        // Error signals
        float dt;
        float error;
        float error_previous;
        float error_drivative;
        float error_integral;
        int   loop_counter;

        // Controller output
        float U;

        // Update error signals
        void Error_Updater();

    public:
        // Constructor
        PID_Controller(float Kp_def, float Kd_def, float Ki_def);

        // Controller output computer
        float compute(float signal_val, float setpoint_val, float dt_def);
};