#include "BitlockerCode.h"

#include <stdexcept>

BitlockerCode::BitlockerCode() {
    this->codeStr = "000000000000000000000000000000000000000000000000";
}

BitlockerCode::BitlockerCode(std::string code) {
    int dashCounter = 0;
    for (long unsigned int i = 0; i < code.length(); i++) {
        if (code[i] == '-') {
            dashCounter++;
        }
    }

    if (dashCounter != 7) {
        throw new std::invalid_argument("the given code is invalid");
    }

    this->codeStr = "";

    for (long unsigned int i = 0; i < code.length(); i++ ) {
        if (code[i] != '-') {
            this->codeStr += code[i];
        }
    }
}

bool BitlockerCode::increment() { 
    if (this->codeStr == "999999999999999999999999999999999999999999999999") {
        return false;
    }

    bool reminder = false;
    int index = this->codeStr.length()-1;

    do {
        if (this->codeStr[index] != 0x39) { // 0x39 = '9'
            this->codeStr[index]++;
            reminder = false;
        }
        else {
            this->codeStr[index] = 0x30; // 0x30 = '0'

            reminder = true;
            index--;
        }
    } while (reminder == true && index > 0);

    return true;
}


std::string BitlockerCode::Serialize() {
    std::string out = "";

    int digitCounter = 0;

    for (unsigned long int i = 0; i < this->codeStr.length(); i++) {
        out += this->codeStr[i];
        digitCounter++;
        if (digitCounter == 6 && i+1 < this->codeStr.length()) {
            out += "-";
            digitCounter = 0;
        }
    }

    return out;
}

int BitlockerCode::codeLength() {
    return this->codeStr.length();
}

BitlockerCode::~BitlockerCode() {
    this->codeStr.clear();
}

bool BitlockerCode::isEqual(BitlockerCode other) {
    return this->Serialize() == other.Serialize();
}

bool BitlockerCode::set(std::string value) {
    int dashCounter = 0;
    for (long unsigned int i = 0; i < value.length(); i++ ) {
        if (value[i] == '-') {
            dashCounter++;
        }
    }

    if (dashCounter != 7) {
        return false;
    }

    this->codeStr = value;

    return true;
}