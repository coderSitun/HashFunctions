#include"sha160.h"

const Hash::uint32 Sha160::wordsPerHash       = 5;
const Hash::uint32 Sha160::setSize            = 512;
const Hash::uint32 Sha160::wordsPerSet        = 16;
const Hash::uint32 Sha160::totalWords         = 80;
const Hash::uint32 Sha160::iterationsPerRound = 20;

Sha160::Sha160(){
    hash  = new uint32[wordsPerHash];
    words = new uint32[totalWords];
    keys[FIRST_ROUND]  = 0x5a827999;
    keys[SECOND_ROUND] = 0x6ed9eba1;
    keys[THIRD_ROUND]  = 0x8f1bbcdc;
    keys[FOURTH_ROUND] = 0xca62c1d6;
}

void Sha160::fillCharInWord(const uint32 wordIndex, const char theChar){
    words[wordIndex] <<= charBitLength;
    words[wordIndex] |= theChar;
}

void Sha160::fillWords(std::string message, const uint32 offset){
    uint32 wordIndex = 0;
    uint32 curIndex  = 0;
    uint32 curLength = message.length() - offset;
    curLength = (curLength < setSize)?curLength:setSize;
    uint32 wordsForMessage = curLength >> charsPerWordBitLength;

    while(wordIndex < wordsForMessage){
        words[wordIndex] = 0;
        for(uint32 index = 0; index < charsPerWord; ++index, ++curIndex){
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

    while(wordIndex < totalWords){
        words[wordIndex] = leftRotate(words[wordIndex - 3] ^ words[wordIndex - 8] ^ words[wordIndex - 14] ^ words[wordIndex - 16], 1);
        ++wordIndex;
    }
}

void Sha160::initializeHashes(){
    hash[0] = 0x67452301;
    hash[1] = 0xefcdab89;
    hash[2] = 0x98badcfe;
    hash[3] = 0x10325476;
    hash[4] = 0xc3d2e1f0;
}

Hash::uint32 Sha160::functionOperator(Rounds round, uint32 a, uint32 b, uint32 c){
    uint32 ans;
    switch(round)
    {
        case FIRST_ROUND:
            ans = (a & b) | (!a & c);
            break;
        case SECOND_ROUND:
        case FOURTH_ROUND:
            ans = a ^ b ^ c;
            break;
        case THIRD_ROUND:
            ans = (a & b) | (b & c) | (c & a);
            break;
    }
    return ans;
}

bool Sha160::checkValidity(){
    return true;
}

std::string Sha160::getHash(std::string message){
    std::vector<uint32> data;
    initializeHashes();
    uint32 temp;
    for(uint32 index = 0; index < message.length(); index += setSize){
        fillWords(message, index);
        data.insert(data.end(), hash, hash + wordsPerHash);
        for(uint32 roundIndex = 0; roundIndex < TOTAL_ROUNDS; ++roundIndex){
            for(uint32 iteratorIndex = 0; iteratorIndex < iterationsPerRound; ++iteratorIndex){
                temp    =     leftRotate(data[0], 5)
                            + functionOperator(static_cast<Rounds>(roundIndex), data[1], data[2], data[3]) 
                            + data[4] 
                            + words[roundIndex*iterationsPerRound + iteratorIndex] 
                            + keys[roundIndex];
                data[4] = data[3];
                data[3] = data[2];
                data[2] = leftRotate(data[1], 30);
                data[1] = data[0];
                data[0] = temp;
            }
        }
        for(uint32 wordIndex = 0; wordIndex < wordsPerHash; ++wordIndex)
            hash[wordIndex] += data[wordIndex];
    }
    return getHexString(std::vector<uint32>(hash, hash + wordsPerHash));
}

Sha160::~Sha160(){
    delete[] words;
    delete[] hash;
}