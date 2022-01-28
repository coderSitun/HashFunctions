#ifndef __SHA160
#define __SHA160

#include"hash.h"

class Sha160:public Hash{
private:
    static const uint32 setSize;
    static const uint32 wordsPerSet;
public:
    bool checkValidity();
    std::string getHash(std::string message);
};

#endif