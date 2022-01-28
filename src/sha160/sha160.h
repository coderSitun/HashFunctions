#ifndef __SHA160
#define __SHA160

#include"hash.h"

class Sha160:public Hash{
private:
public:
    bool checkValidity();
    std::string getHash(std::string message);
};
#endif