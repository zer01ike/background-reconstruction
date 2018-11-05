//
// Created by zer01ike on 2018/11/5.
//

#ifndef BR_TOOLS_H
#include <opencv2/opencv.hpp>
#include <vector>
#define BR_TOOLS_H

using namespace std;

class tools {

public:
    vector<cv::Mat> readVideo(string path);

};


#endif //BR_TOOLS_H
