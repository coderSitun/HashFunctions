#ifndef __HASH
#define __HASH

class Hash{
private:
    enum HashFunctionTypes{
        SHA160,
        MAX_HASH_FUNCTION_TYPES
    };
public:
    typedef HashFunctionTypes HashFunctionTypes;
    static HashFunction GetHashFunctionType(String type);
    static Hash* GetHashFunction(HashFunctionTypes hashFunctionType);
    bool checkHashFunctionTypeValidity(HashFunctionTypes hashFunctionType);
};

#endif