#include <strings.h>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/cuda.hpp>

using namespace std;

int main(int argc, char** argv)
{
    if ( argc != 2 ) {
      printf("no args\n");
      return -1;
    }
    cv::Mat frame;
    cv::VideoCapture cap;
    //cap.open(argv[1]);
    cap.open(argv[1]);
    if (!cap.isOpened()) {
        printf("ERROR! Unable to open camera\n");
        return -1;
    }
    printf("Start grabbing\n");
    for (;;)
    {
        cap.read(frame);
        double fps2 = cap.get(cv::CAP_PROP_FPS);
        std::cout << "fps2 : " << fps2 << std::endl;
        double frmwidt = cap.get(cv::CAP_PROP_FRAME_WIDTH);
        std::cout << "frmwidt : " << frmwidt << std::endl;
        double frmheiht = cap.get(cv::CAP_PROP_FRAME_HEIGHT);
        std::cout << "frmheiht : " << frmheiht << std::endl;
        double vidposms = cap.get(cv::CAP_PROP_POS_MSEC);
        std::cout << "vidposms : " << vidposms << std::endl;
       // double frmcount = cap.get(cv::CAP_PROP_FRAME_COUNT);
        //std::cout << "frmcount : " << frmcount << std::endl;


        if (frame.empty()) {
            printf("ERROR! blank frame grabbed\n");
            break;
        }
        vector<int> p;
        vector<unsigned char> buf;
        p.push_back(cv::IMWRITE_JPEG_QUALITY);
        p.push_back(50);
        //imencode(".jpg", frame, buf, p);
        // Do something with buf ......
        printf("READY JPEG\n");
        cv::imshow("result", frame);
        cv::waitKey(0);
    }
    return 0;
}
