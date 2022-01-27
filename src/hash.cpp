#include<string>
#include"hash.h"

Hash::HashFunctionTypes Hash::GetHashFunctionType(std::String type){
    if(type.compare("sha160"))
        return SHA160;
    return MAX_HASH_FUNCTION_TYPES;
}