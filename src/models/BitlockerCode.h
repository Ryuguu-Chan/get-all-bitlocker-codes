#ifndef _APP_BITLOCKERCODE_CLASS_
#define _APP_BITLOCKERCODE_CLASS_
#include <string>

class BitlockerCode {
private:
    std::string codeStr;
public:

    std::string Serialize();
    bool isEqual(BitlockerCode other);
    bool set(std::string value);
    bool increment();
    int codeLength();

    BitlockerCode();
    BitlockerCode(std::string code);
    ~BitlockerCode();
};
#endif