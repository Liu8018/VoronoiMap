#include "PerlinNoise.h"
#include "RandSeq.h"

float PNoiseUnit(const float& dx, const float& dy,
    const float& g0x, const float& g0y, const float& g1x, const float& g1y,
    const float& g2x, const float& g2y, const float& g3x, const float& g3y)
{
    float dx1 = dx - 1;
    float dy1 = dy - 1;


    float i0 = dx * g0x + dy * g0y;
    float i1 = dx1 * g1x + dy * g1y;
    float i2 = dx * g2x + dy1 * g2y;
    float i3 = dx1 * g3x + dy1 * g3y;

    float fade_dx = dx * dx * dx * (6 * dx * dx - 15 * dx + 10);
    float i01 = i0 + fade_dx * (i1 - i0);
    float i23 = i2 + fade_dx * (i3 - i2);
    float i = i01 + dy * dy * dy * (6 * dy * dy - 15 * dy + 10) * (i23 - i01);

    return i;
}

float genPerlinNoiseB(const unsigned int& rdseed, 
    const float& x, const float& y, const int& xb, const int& yb)
{
    int x0 = int(x);
    int x1 = x0 + 1;
    int y0 = int(y);
    int y1 = y0 + 1;

    float dx = x - x0;
    float dy = y - y0;

    if (x1 == xb)
        x1 = 0;
    if (y1 == yb)
        y1 = 0;

    RandSeq rng(rdseed, y0 * xb + x0);
    float g0x = float((rng.next() % 100) / float(50) - 1.0);
    float g0y = float((rng.next() % 100) / float(50) - 1.0);
    rng.srand(rdseed, y0 * xb + x1);
    float g1x = float((rng.next() % 100) / float(50) - 1.0);
    float g1y = float((rng.next() % 100) / float(50) - 1.0);
    rng.srand(rdseed, y1 * xb + x0);
    float g2x = float((rng.next() % 100) / float(50) - 1.0);
    float g2y = float((rng.next() % 100) / float(50) - 1.0);
    rng.srand(rdseed, y1 * xb + x1);
    float g3x = float((rng.next() % 100) / float(50) - 1.0);
    float g3y = float((rng.next() % 100) / float(50) - 1.0);

    return PNoiseUnit(dx, dy, g0x, g0y, g1x, g1y, g2x, g2y, g3x, g3y);
}