#include <iostream>
#include <thread>
#include <chrono>
#include <queue>
#include <fstream>
#include <sstream>
#include "data_structs.hpp"

std::string LogFileNameDated(const std::string& inputName) {
    time_t now = time(0);
    tm* localTime = localtime(&now);

    int year = 1900 + localTime->tm_year;
    int month = 1 + localTime->tm_mon;
    int day = localTime->tm_mday;
    int hour = localTime->tm_hour;
    int min = localTime->tm_min;
    int sec = localTime->tm_sec;

    std::string fileName = inputName + "_" + std::to_string(year) + "_" +
                           std::to_string(month) + "_" + std::to_string(day) + "_" +
                           std::to_string(hour) + "_" + std::to_string(min) + "_" +
                           std::to_string(sec) + ".csv";

    return fileName;
}

void logKinData(std::ofstream *ptr_File, const struct Kinematic3DoF *ptr_KinData) {
    *ptr_File << ptr_KinData->x << ",";
    *ptr_File << ptr_KinData->y << ",";
    *ptr_File << "\n";
}

int main() {
    std::ofstream KinDataLogFile;
    KinDataLogFile.open(LogFileNameDated("KinDataLogFile"), std::ios::out);

    struct Kinematic3DoF dataKinematic1 = {0.};
    dataKinematic1.x = 10; dataKinematic1.y = 11;
    struct Kinematic3DoF dataKinematic2 = {1.};
    dataKinematic2.x = 20; dataKinematic2.y = 21;
    struct Kinematic3DoF dataKinematic3 = {2.};
    dataKinematic3.x = 30; dataKinematic3.y = 31;

    std::queue<Kinematic3DoF> dataKinematicQueue;
    dataKinematicQueue.emplace(dataKinematic1);
    dataKinematicQueue.emplace(dataKinematic2);
    dataKinematicQueue.emplace(dataKinematic3);

   
    while (!dataKinematicQueue.empty())
    {
        logKinData(&KinDataLogFile, &dataKinematicQueue.front()); 
        dataKinematicQueue.pop();  
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
        
    KinDataLogFile.close();
    return 0;
}