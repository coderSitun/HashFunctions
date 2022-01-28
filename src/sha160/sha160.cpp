#include"sha160.h"

const Hash::uint32 Sha160::setSize     = 512;
const Hash::uint32 Sha160::wordsPerSet = 16;
const Hash::uint32 Sha160::totalWords  = 80;

Sha160::Sha160(){
    words = new uint32[totalWords];
}

void Sha160::fillCharInWord(const uint32 wordIndex, const char theChar){
    words[wordIndex] <<= charBitLength;
    words[wordIndex] |= theChar
}

bool Sha160::checkValidity(){
    return true;
}

