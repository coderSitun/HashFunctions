#ifndef __HASH
#define __HASH

#include<string>
#include<vector>

class Hash{
private:
    enum HashFunctionTypes{
        SHA160,
        MAX_HASH_FUNCTION_TYPES
    };
protected:
    typedef unsigned int uint32;
    static const std::vector<char> hexSymbols;
    static const uint32 charBitLength;
    static const uint32 wordBitLength;
    static const uint32 charPerWord;
    std::string getHexString(std::vector<uint32> data);
public:
    typedef HashFunctionTypes HashFunctionEnumTypes;
    static HashFunctionTypes GetHashFunctionType(std::string type);
    static Hash* GetHashFunction(HashFunctionTypes eType);
    virtual bool checkValidity();
    virtual std::string getHash(std::string message);
};

#endif