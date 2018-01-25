#include <cv.hpp>
#include <highgui.h>
#include "mnist_util.hpp"

using namespace cv;
int main( int argc, char** argv )
{
    /*
    Mat image;
    image = imread( argv[1], 1 );

    if( argc != 2 || !image.data )
    {
        printf( "No image data \n" );
        return -1;
    }

    namedWindow( "Display Image", CV_WINDOW_AUTOSIZE );
    imshow( "Display Image", image );
	*/
	vector<Mat> vec;
	MnistUtil Mnist;
	vec = Mnist.readMnistImage(argv[1]);
	namedWindow( "Display Image", CV_WINDOW_AUTOSIZE );
    imshow( "Display Image", vec[1] );
    waitKey(0);

    return 0;
}
