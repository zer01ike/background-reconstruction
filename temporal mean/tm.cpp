//
// Created by zer01ike on 2018/11/5.
//
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include "../common/tools.h"

using namespace std;

int main(){
    tools tool;
    string path = "K:\\SubjectDataSet\\test_sequence\\BookArrival_QP\\264_t34_BookArrival.mkv";

    vector<cv::Mat> video = tool.readVideo(path);


    return 0;
}
