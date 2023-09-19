#include "mass_spring_damper.hpp"
#include "pid_controller.hpp"

int main() {
    MassSpringDamper MSD1(1.5, 0.8, 0.2, 1.0, 0.0);
    PID_Controller PID1(1.0, 0.3, 0.2);

    for (int i = 0; i <100; i++) {
        double dt = 0.1;

        MSD1.setInput(PID1.compute(MSD1.get_pose_signal(), 10, dt));
        MSD1.simulateSystem(dt);

        MSD1.print_state();
    }
    return 0;
}