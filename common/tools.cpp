//
// Created by zer01ike on 2018/11/5.
//

#include "tools.h"

vector<cv::Mat> tools::readVideo(string path) {
    cv::VideoCapture capture;
    capture.open(path);
    cv::vector<cv::Mat> video;

    int frames = capture.get(CV_CAP_PROP_FRAME_COUNT);

    if (frames == 0){
        cout<<"error for reading "<<endl;
    }else{
        for(int i=0;i<frames;i++){
            cv::Mat temp_frame;
            capture >> temp_frame;
            video.push_back(temp_frame);
        }
    }
    return video;
}
