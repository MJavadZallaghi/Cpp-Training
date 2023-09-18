#include "mass_spring_damper.hpp"

int main() {
    MassSpringDamper MSD1(1.5, 0.8, 0.2, 1.0, 0.0);
    for (int i = 0; i <50; i++) {
        MSD1.setInput(0.0);
        MSD1.simulateSystem(0.1);
        MSD1.print_state();
    }
    return 0;
}