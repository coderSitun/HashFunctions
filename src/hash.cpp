#include"hash.h"
#include"sha160.h"

const std::vector<char> Hash::hexSymbols = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
const Hash::uint32 Hash::charBitLength         = 8;
const Hash::uint32 Hash::wordBitLength         = 32;
const Hash::uint32 Hash::charsPerWord          = 4;
const Hash::uint32 Hash::charsPerWordMinusOne  = charsPerWord - 1;
const Hash::uint32 Hash::charsPerWordBitLength = 2;

Hash::Hash(){
    hash = nullptr;
}

std::string Hash::getHexString(std::vector<uint32> data){
    std::string hex = "";
    std::vector<uint32>::iterator it;
    for(it = data.begin(); it != data.end(); ++it){
        hex += hexSymbols[*it >> 4];
        hex += hexSymbols[*it & 0x0f];
    }
    return hex;
}

Hash::uint32 Hash::leftRotate(uint32 word, uint32 rotate){
    rotate &= 0x1f;
    if(word & 0x80000000)
        return ((word << rotate) & (word >> (0x1f - rotate)));
    else
        return ((word << rotate) | (word >> (0x1f - rotate)));
}
Hash::uint32 Hash::rightRotate(uint32 word, uint32 rotate){
    rotate &= 0x1f;
    if(word & 0x80000000)
        return ((word >> rotate) & (word << (0x1f -rotate)));
    else
        return ((word >> rotate) | (word << (0x1f - rotate)));
}

Hash::HashFunctionTypes Hash::GetHashFunctionType(std::string type){
    if(type.compare("sha160"))
        return SHA160;
    return MAX_HASH_FUNCTION_TYPES;
}

Hash* Hash::GetHashFunction(HashFunctionTypes eType){
    switch(eType){
        case SHA160:
            return new Sha160();
    }
    return new Hash();
}

bool Hash::checkValidity(){
    return false;
}
std::string Hash::getHash(std::string message){
    return "Invalid call";
}