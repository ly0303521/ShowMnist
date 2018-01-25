#ifndef MNIST_UTIL_HPP
#define MNIST_UTIL_HPP
#include <vector>
#include <opencv2/opencv.hpp>

class MnistUtil{

public:
    MnistUtil();

    inline int reverseInt(int i) {
        unsigned char c1, c2, c3, c4;
        c1 = i & 255;
        c2 = (i >> 8) & 255;
        c3 = (i >> 16) & 255;
        c4 = (i >> 24) & 255;
        return ((int) c1 << 24) + ((int) c2 << 16) + ((int) c3 << 8) + c4;
    }

    std::vector<cv::Mat> readMnistImage(char* path);

    std::vector<double> readMnistLabel(char* path);

};

#endif
