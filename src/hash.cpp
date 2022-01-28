#include"hash.h"

const std::vector<char> Hash::hexSymbols = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
const Hash::uint32 Hash::charBitLength        = 8;
const Hash::uint32 Hash::wordBitLength        = 32;
const Hash::uint32 Hash::charsPerWord         = 4;
const Hash::uint32 Hash::charsPerWordMinusOne = charsPerWord - 1;

std::string Hash::getHexString(std::vector<uint32> data){
    std::string hex = "";
    std::vector<uint32>::iterator it;
    for(it = data.begin(); it != data.end(); ++it){
        hex += hexSymbols[*it >> 4];
        hex += hexSymbols[*it & 0x0f];
    }
    return hex;
}

Hash::HashFunctionTypes Hash::GetHashFunctionType(std::string type){
    if(type.compare("sha160"))
        return SHA160;
    return MAX_HASH_FUNCTION_TYPES;
}

Hash* Hash::GetHashFunction(HashFunctionTypes eType){
    switch(eType){
        case SHA160:
            break;
    }
    return new Hash();
}

bool Hash::checkValidity(){
    return false;
}
std::string Hash::getHash(std::string message){
    return "Invalid call";
}