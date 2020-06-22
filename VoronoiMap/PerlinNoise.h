#ifndef PERLINNOISE_H
#define PERLINNOISE_H

#include <vector>

//输入：随机种子，x坐标，y坐标，x上限，y上限
//输出：介于-1到1之间的噪声值
float genPerlinNoiseB(const unsigned int& rdseed, 
    const float& x, const float& y, const int& xb, const int& yb);

#endif //PERLINNOISE_H