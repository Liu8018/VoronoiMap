//¸ÐÐ»https://github.com/preshing/RandomSequence
#ifndef RANDSEQ_H
#define RANDSEQ_H

class RandSeq
{
public:
    RandSeq(const unsigned int& seedBase, const unsigned int& seedOffset);

    void srand(const unsigned int& seedBase, const unsigned int& seedOffset);

    unsigned int next();

private:
    unsigned int m_index;
    unsigned int m_intermediateOffset;
};

#endif // RANDSEQ_H