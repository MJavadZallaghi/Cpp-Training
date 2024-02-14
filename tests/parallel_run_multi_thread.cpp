#include <iostream>
#include <thread>
#include <chrono>
#include <queue>
#include "data_structs.hpp"

void funcA() {
    for(int i=0;i<10;i++){
        std::cout<< "Func A, i = "<< i <<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
void funcB() {
    for(int i=10;i<20;i++){
        std::cout<< "Func B, i = "<< i <<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
void funcC() {
    for(int i=20;i<30;i++){
        std::cout<< "Func C, i = "<< i <<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    struct Kinematic3DoF dataKinematic1 = {0.};
    struct Kinematic3DoF dataKinematic2 = {1.};
    struct Kinematic3DoF dataKinematic3 = {2.};

    std::queue<Kinematic3DoF> dataKinematicQueue;

    dataKinematicQueue.emplace(dataKinematic1);
    dataKinematicQueue.emplace(dataKinematic2);
    dataKinematicQueue.emplace(dataKinematic3);

    int queue_counter = 0;
    struct Kinematic3DoF queue_current_data_element_first_item;
    struct Kinematic3DoF queue_current_data_element_last_item;
    while (!dataKinematicQueue.empty())
    {
        queue_current_data_element_first_item = dataKinematicQueue.front(); // Front --> First item added {0.} by emplace
        queue_current_data_element_last_item = dataKinematicQueue.back(); // Back --> Last item added {2.} by emplace
        dataKinematicQueue.pop();  // Eliminate the first item of the que (front) [Not the last added one]
        std::cout<< "x of first data added to the que by emplace: " <<queue_current_data_element_first_item.x<<std::endl; 
        std::cout<< "x of last data added to the que by emplace: " <<queue_current_data_element_last_item.x<<std::endl; 

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        queue_counter++;
        if (queue_counter>=10) {
            break;
        }
    }
    
    // Serial executation of the functions
    funcA();
    funcB();
    funcC();
    // Parallel executation of the functions
    std::thread funcAThread(funcA);
    std::thread funcBThread(funcB);
    std::thread funcCThread(funcC);
    funcAThread.join();
    funcBThread.join();
    funcCThread.join();

    return 0;
}