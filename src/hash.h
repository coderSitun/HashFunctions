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
    typedef unsigned int uint32;
    static const std::vector<char> hexSymbols;
    std::string getHexString(std::vector<uint32> data);
public:
    typedef HashFunctionTypes HashFunctionEnumTypes;
    static HashFunctionTypes GetHashFunctionType(std::string type);
    static Hash* GetHashFunction(HashFunctionTypes eType);
    virtual bool checkValidity();
    virtual std::string getHash(std::string message);
};

#endif