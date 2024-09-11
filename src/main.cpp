#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>

#include "BitlockerCode.h"

int main(int argc, const char** argv) {
    BitlockerCode sampleCode;

    std::cout << "generating the Bitlocker codes..." << std::endl;

    // creating that 375GB text file at the same directory as where the executable is!
    std::ofstream outoputTextFile;
    outoputTextFile.open("bitlocker_codes.txt", std::ios::out | std::ios::app);

    while (sampleCode.Serialize() != "999999-999999-999999-999999-999999-999999-999999-999999") {
        if (sampleCode.increment() == false) {
            outoputTextFile << "something went wrong while incrementing" << std::endl;
            outoputTextFile.close();
            return EXIT_FAILURE;
        }
        outoputTextFile << sampleCode.Serialize();
        outoputTextFile << '\n';
    }

    outoputTextFile.close();
    std::cout << "all done!" << std::endl;

    return EXIT_SUCCESS;
}