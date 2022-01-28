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

void Sha160::fillWords(std::string message, const uin32 offset){
    uint32 wordIndex = -1;
    uint32 curIndex  = 0;
    uint32 curLength = message.length() - offset;
    curLength = (curLength < setSize)?curLength:setSize;
    uint32 wordsForMessage = curLength >> charsPerWordBitLength;

    while(wordIndex < wordsForMessage){
        words[wordIndex] = 0;
        for(index = 0; index < charsPerWord; ++index, ++curIndex){
            fillCharInWord(wordIndex, message[offset + curIndex]);
        }
        ++wordIndex;
    }

    words[wordIndex] = 0;
    while(curIndex < curLength){
        fillCharInWord(wordIndex, message[offset + curIndex]);
    }
    curIndex = curLength & charsPerWordMinusOne;
    if(curIndex < charsPerWord){
        fillCharInWord(wordIndex, 0x80);
        ++curIndex;
    }
    while(curIndex < charsPerWord){
        fillCharInWord(wordIndex, 0x00);
        ++curIndex;
    }
    ++wordIndex;

    while(wordIndex < wordsPerSet)
        words[wordIndex++] = 0x00000000;
}

bool Sha160::checkValidity(){
    return true;
}

