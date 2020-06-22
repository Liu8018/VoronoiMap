#include "RandSeq.h"

const unsigned int prime = 4294967291u;

unsigned int permuteQPR(const unsigned int& x)
{
    if (x >= prime)
        return x;  // The 5 integers out of range are mapped to themselves.
    unsigned int residue = ((unsigned long long) x * x) % prime;
    return (x <= prime / 2) ? residue : prime - residue;
}

RandSeq::RandSeq(const unsigned int& seedBase, const unsigned int& seedOffset)
{
    srand(seedBase, seedOffset);
}

void RandSeq::srand(const unsigned int& seedBase, const unsigned int& seedOffset)
{
    m_index = permuteQPR(permuteQPR(seedBase) + 0x682f0161);
    m_intermediateOffset = permuteQPR(permuteQPR(seedOffset) + 0x46790905);
}

unsigned int RandSeq::next()
{
    return permuteQPR((permuteQPR(m_index++) + m_intermediateOffset) ^ 0x5bf03635);
}
