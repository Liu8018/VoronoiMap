#ifndef VORONOISE_H
#define VORONOISE_H

#include <vector>

//输入：随机种子，x坐标，y坐标，x上限,y上限，单位格子从小到大的尺度列表
//输出：距离(x,y)最近的根点的坐标
void genVoroNoiseB(const unsigned int& rdseed, 
    const int& x, const int& y, const int& xb, const int& yb,
    const std::vector<int>& uList, int& rootX, int& rootY);

#endif //VORONOISE_H