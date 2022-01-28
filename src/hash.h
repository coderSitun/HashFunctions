#ifndef __HASH
#define __HASH

#include<string>

class Hash{
private:
    enum HashFunctionTypes{
        SHA160,
        MAX_HASH_FUNCTION_TYPES
    };
public:
    typedef HashFunctionTypes HashFunctionEnumTypes;
    static HashFunctionTypes GetHashFunctionType(std::string type);
    static Hash* GetHashFunction(HashFunctionTypes hashFunctionType);
    bool checkHashFunctionTypeValidity(HashFunctionTypes hashFunctionType);
};

#endif