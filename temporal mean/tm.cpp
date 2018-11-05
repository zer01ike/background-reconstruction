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


    int rows = video[0].rows;
    int cols = video[0].cols;
    double frames = video.size();
    cout<<rows<<" "<<cols<<endl;
    cv::Mat reference = cv::Mat(cv::Size(cols,rows),CV_64FC3,cv::Scalar(0.0f,0.0f,0.0f));
    cv::Mat count = cv::Mat(cv::Size(cols,rows),CV_64FC3,cv::Scalar(frames,frames,frames));
    cv::namedWindow("result");

    vector<cv::Mat>::iterator frame = video.begin();

    for(;frame != video.end();++frame){
        //count ++;
        cv::Mat temp = *frame;
        temp.convertTo(temp,CV_64FC3);
        reference +=temp;
    }

    reference = reference/count;

    cv::Mat result;
    reference.convertTo(result,CV_8UC3);

    cv::imshow("result",result);
    cv::waitKey();
    cv::destroyAllWindows();


    return 0;
}
