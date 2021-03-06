#ifndef __SHA160
#define __SHA160

#include"hash.h"

class Sha160 : public Hash{
private:
    enum Rounds{
        FIRST_ROUND,
        SECOND_ROUND,
        THIRD_ROUND,
        FOURTH_ROUND,
        TOTAL_ROUNDS
    };
    static const uint32 wordsPerHash;
    static const uint32 setSize;
    static const uint32 wordsPerSet;
    static const uint32 totalWords;
    static const uint32 iterationsPerRound;
    uint32 *words;
    uint32 keys[TOTAL_ROUNDS];
    void fillCharInWord(const uint32 wordIndex, const char theChar);
    void fillWords(std::string message, const uint32 offset, const bool isLastChunk);
    void initializeHashes();
    uint32 functionOperator(Rounds round, uint32 a, uint32 b, uint32 c);
public:
    Sha160();
    bool checkValidity();
    std::string getHash(std::string message);
    ~Sha160();
};

#endif