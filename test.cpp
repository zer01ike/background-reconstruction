//
// Created by zer01ike on 2018/11/2.
//
#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::namedWindow("haha");
    cv::Mat img = cv::imread("C:\\Users\\zer01ike\\CLionProjects\\background-reconstruction\\test.jpg");
    if(img.empty()){
        std::cout<<"ERROR!!"<<std::endl;

        return 25;
    }

    cv::imshow("haha",img);
    cv::waitKey();
    cv::destroyAllWindows();
    return 0;
}
