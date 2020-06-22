#ifndef VORONOISE_H
#define VORONOISE_H

#include <vector>

//���룺������ӣ�x���꣬y���꣬x����,y���ޣ���λ���Ӵ�С����ĳ߶��б�
//���������(x,y)����ĸ��������
void genVoroNoiseB(const unsigned int& rdseed, 
    const int& x, const int& y, const int& xb, const int& yb,
    const std::vector<int>& uList, int& rootX, int& rootY);

#endif //VORONOISE_H