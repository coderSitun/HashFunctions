#ifndef __SHA160
#define __SHA160

#include"hash.h"

class Sha160 : public Hash{
private:
    static const uint32 wordsPerHash;
    static const uint32 setSize;
    static const uint32 wordsPerSet;
    static const uint32 totalWords;
    static const uint32 rounds;
    static const uint32 iterationsPerRound;
    uint32 *words;
    void fillCharInWord(const uint32 wordIndex, const char theChar);
    void fillWords(std::string message, const uint32 offset);
public:
    Sha160();
    bool checkValidity();
    std::string getHash(std::string message);
    ~Sha160();
};

#endif