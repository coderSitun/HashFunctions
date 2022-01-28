#include"hash.h"

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