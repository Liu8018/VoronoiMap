#ifndef PERLINNOISE_H
#define PERLINNOISE_H

#include <vector>

//���룺������ӣ�x���꣬y���꣬x���ޣ�y����
//���������-1��1֮�������ֵ
float genPerlinNoiseB(const unsigned int& rdseed, 
    const float& x, const float& y, const int& xb, const int& yb);

#endif //PERLINNOISE_H