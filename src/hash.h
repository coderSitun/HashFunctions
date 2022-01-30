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
    static const uint32 hexSymbolsPerWord;
    static const uint32 charBitLength;
    static const uint32 wordBitLength;
    static const uint32 charsPerWord;
    static const uint32 charsPerWordMinusOne;
    static const uint32 charsPerWordBitLength;
    uint32 *hash;
    std::string getHexString(std::vector<uint32> data);
    uint32 leftRotate(uint32 word, uint32 rotate);
    uint32 rightRotate(uint32 word, uint32 rotate);
public:
    Hash();
    typedef HashFunctionTypes HashFunctionEnumTypes;
    static HashFunctionTypes GetHashFunctionType(std::string type);
    static Hash* GetHashFunction(HashFunctionTypes eType);
    virtual bool checkValidity();
    virtual std::string getHash(std::string message);
};

#endif