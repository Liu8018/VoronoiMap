#include "VoroNoise.h"
#include "RandSeq.h"

#include <algorithm>

//单位格子内随机取点
void getRandPt(const unsigned int& rdseed, float& x, float& y)
{
    RandSeq rng(rdseed,0);
    x = (rng.next() % 100) / float(100);
    y = (rng.next() % 100) / float(100);
}

void genVoroNoiseB(const unsigned int& rdseed,
    const int& x, const int& y, const int& xb, const int& yb,
    const std::vector<int>& uList, int& rootX, int& rootY)
{
    int cx = x;
    int cy = y;

    int uListSize = int(uList.size());
    for (int i = 0; i < uListSize; i++) {
        int u = uList[i];

        int blockX = cx / u;
        int blockY = cy / u;
        int blockXb = xb / u;
        int blockYb = yb / u;

        int minDist = xb*yb;
        int mx, my;
        for (int offx = -1; offx <= 1; offx++) {
            for (int offy = -1; offy <= 1; offy++) {
                int offBlockX = blockX + offx;
                int offBlockY = blockY + offy;

                bool flag_xl = false;
                bool flag_xu = false;
                bool flag_yl = false;
                bool flag_yu = false;
                int offBlockX_bound = offBlockX;
                if (offBlockX_bound < 0) {
                    offBlockX_bound += blockXb;
                    flag_xl = true;
                }
                else if (offBlockX_bound >= blockXb) {
                    offBlockX_bound -= blockXb;
                    flag_xu = true;
                }
                int offBlockY_bound = offBlockY;
                if (offBlockY_bound < 0) {
                    offBlockY_bound += blockYb;
                    flag_yl = true;
                }
                else if (offBlockY_bound >= blockYb) {
                    offBlockY_bound -= blockYb;
                    flag_yu = true;
                }

                float rx, ry;
                getRandPt(rdseed+offBlockY_bound*blockXb+offBlockX_bound,rx,ry);

                int x1 = offBlockX * u + int(u * rx);
                int y1 = offBlockY * u + int(u * ry);
                int dist = (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy);
                if (dist < minDist) {
                    minDist = dist;
                    mx = x1;
                    my = y1;

                    if (flag_xl) mx += xb;
                    else if (flag_xu) mx -= xb;
                    if (flag_yl) my += yb;
                    else if (flag_yu) my -= yb;
                }
            }
        }
        cx = mx;
        cy = my;
    }

    rootX = cx;
    rootY = cy;
}