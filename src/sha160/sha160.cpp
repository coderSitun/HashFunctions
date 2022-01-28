#include"sha160.h"

const Hash::uint32 Sha160::setSize     = 512;
const Hash::uint32 Sha160::wordsPerSet = 16;

bool Sha160::checkValidity(){
    return true;
}

