#include "mass_spring_damper.hpp"
#include "pid_controller.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

void write_mass_sping_data_to_file(std::string file_name ,std::vector<float> data_array_1,  std::vector<float> data_array_2) {
    std::ofstream MSD_Data(file_name);
    MSD_Data << "# The file for storing data from Mass-Spring-Damper simulation with the PID Controller." <<std::endl;
    MSD_Data << "# time \t \t data" <<std::endl;
    
    int data_length = data_array_1.size();

    for (int i = 0; i < data_length; i++) {
        MSD_Data  << data_array_1[i] << " \t \t " << data_array_2[i] << std::endl;
    }

}

int main() {
    MassSpringDamper MSD1(1.5, 0.8, 0.2, 1.0, 0.0);
    PID_Controller PID1(1.0, 0.3, 0.2);

    // Simulation settings
    float dt = 0.1;
    float time = 0.0;

    // Controller settings
    float set_point = 10.;
    float pose_feedback; 
    float controller_effort;

    // Data collection for plot
    std::vector<float> time_array = {};
    std::vector<float> pose_feedback_array = {};
    std::vector<float> controller_effort_array = {};

    // Simulation loop
    for (int i = 0; i <100; i++) {
        time += dt;
        time_array.push_back(time);

        pose_feedback = MSD1.get_pose_signal();
        controller_effort = PID1.compute(pose_feedback, set_point, dt);

        pose_feedback_array.push_back(pose_feedback);
        controller_effort_array.push_back(controller_effort);

        MSD1.setInput(controller_effort);
        MSD1.simulateSystem(dt);
        MSD1.print_state();
    }

    // Save data in a file to plot with gnuplot
    write_mass_sping_data_to_file("MSD_Pos_data.txt" ,time_array, pose_feedback_array);
    return 0;
}


