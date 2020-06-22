#include <opencv2/opencv.hpp>

#include "PerlinNoise.h"
#include "VoroNoise.h"
#include "RandSeq.h"
#include "utils.h"

int main()
{
    int rdseed = 14268;

    int mapSize = 256;
    int refLen = 64;
    int refBound = mapSize / refLen;

    //
    cv::Mat pimg(mapSize, mapSize, CV_8UC3);

    for (int i = 0; i < mapSize; i++) {
        for (int j = 0; j < mapSize; j++) {
            
            float noise1 = genPerlinNoiseB(rdseed,j/float(refLen),i/float(refLen),refBound,refBound);
            float noise2 = genPerlinNoiseB(rdseed*rdseed,j/float(refLen),i/float(refLen),refBound,refBound);

            //RandSeq rng(noise * 100, 0);
            //pimg.at<cv::Vec3b>(i, j) = cv::Vec3b(rng.next()%256, rng.next()%256, rng.next()%256);

            cv::Vec3b pixclr;
            if (noise1 > 0 && noise2 > 0)
                pixclr = cv::Vec3b(255, 0, 0);
            else if (noise1 > 0 && noise2 <= 0)
                pixclr = cv::Vec3b(0, 255, 0);
            else if (noise1 <= 0 && noise2 > 0)
                pixclr = cv::Vec3b(0, 0, 255);
            else
                pixclr = cv::Vec3b(255, 255, 0);
            

            /*
            float noise = genPerlinNoiseB(rdseed, j / float(refLen), i / float(refLen), refBound, refBound);

            cv::Vec3b pixclr;
            if (noise < -0.25)
                pixclr = cv::Vec3b(255, 0, 0);
            else if(noise < -0.1)
                pixclr = cv::Vec3b(0, 255, 255);
            else if (noise < 0)
                pixclr = cv::Vec3b(255, 255, 0);
            else
                pixclr = cv::Vec3b(0, 255, 0);
            */

            pimg.at<cv::Vec3b>(i, j) = pixclr;
        }
    }

    cv::namedWindow("pimg", 0);
    cv::imshow("pimg", pimg);
    //cv::waitKey();

    //
    cv::Mat vimg(mapSize, mapSize, CV_8UC3);

    std::vector<int> uList = { 2,16 };

    {
    timer tmr("vnoise");
    for (int i = 0; i < mapSize; i++) {
        for (int j = 0; j < mapSize; j++) {
            int rootX, rootY;
            genVoroNoiseB(rdseed, j, i, mapSize, mapSize, uList, rootX, rootY);
            vimg.at<cv::Vec3b>(i, j) = pimg.at<cv::Vec3b>(rootY, rootX);
        }
    }
    }

    cv::namedWindow("vimg", 0);
    cv::imshow("vimg", vimg);
    cv::waitKey();

    return 0;
}