#include "mnist_util.hpp"
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;
using namespace cv;

MnistUtil::MnistUtil(){

}

vector<Mat> MnistUtil::readMnistImage(char* path) {

    ifstream is(path, ios::in | ios::binary);

    vector<Mat> vec;

    if (!is) {
        cout << "cannot open file: "<< path  << endl;
    } else {
        int numHeader = 4;
        int header[numHeader];
        cout << "read image header" << endl;
        is.read(reinterpret_cast<char*>(&header), sizeof(header));
        if (is) {
            for (int i = 0; i < numHeader; ++i) {
                header[i] = reverseInt(header[i]);
            }
            cout << "read successful " << endl;
            cout << "magic number: " << header[0] << endl;
            cout << "image number: " << header[1] << endl;
            cout << "rows  number: " << header[2] << endl;
            cout << "cols  number: " << header[3] << endl;
            vec.resize(header[1]);
            unsigned char temp = 0;
            for (int i = 0; i < header[1]; ++i) {
                Mat image = Mat::zeros(header[2], header[3], CV_64FC1);

                for (int r = 0; r < header[2]; ++r) {
                    for (int c = 0; c < header[3]; ++c) {
                        is.read((char*) &temp, sizeof(temp));
                        image.at < double > (r, c) = (double) temp;
                    }
                }

                vec[i] = image;
            }
        }
    }
    is.close();
    return vec;
}

vector<double> MnistUtil::readMnistLabel(char* path){

    ifstream is(path, ios::in | ios::binary);

    vector<double> labels;

    if (!is) {
        cout << "cannot open file: "<< path << endl;
    } else {
        int numHeader = 2;
        int header[numHeader];
        cout << "read label header" << endl;
        is.read(reinterpret_cast<char*>(&header), sizeof(header));
        if (is) {
            for (int i = 0; i < numHeader; ++i) {
                header[i] = reverseInt(header[i]);
            }

            cout << "read successful " << endl;
            cout << "magic number: " << header[0] << endl;
            cout << "label number: " << header[1] << endl;

            labels.resize(header[1]);
            unsigned char temp = 0;
            int size = sizeof(temp);
            for (int i = 0; i < header[1]; ++i) {
                is.read((char*) &temp,size);
                labels[i]=(double)temp;
            }
        }
    }
    is.close();
    return labels;
}
