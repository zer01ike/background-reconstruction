//
// Created by zer01ike on 2018/11/5.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;

vector<cv::Mat> readVideo(string path);
bool showResult(cv::vector<cv::Mat> );
bool saveResult_image(cv::Mat image,string path);
int main(){
    string path = "K:\\SubjectDataSet\\test_sequence\\BookArrival_QP\\264_t34_BookArrival.mkv";
    string saved_path = "background.jpg";
    vector<cv::Mat> video;
    video = readVideo(path);

    int I_1=0,I_2=1;
    int rows = video[I_1].rows;
    int cols = video[I_2].cols;
    cv::Vec3b Null_color = {0,0,0};
    cv::Mat result_chafen = cv::abs(video[I_1] - video[I_2]);
    cv::Mat grey_result_chafen;
    cv::cvtColor(result_chafen,grey_result_chafen,CV_BGR2GRAY);
    int T=5;
    cv::Mat forground = video[I_1].clone();
    cv::Mat background = video[I_1].clone();
    for (int i = 0 ;i<rows;i++){
        for(int j=0;j<cols;j++){
            //cout<<int(grey_result_chafen.at<char>(i,j))<<endl;
            if (int(grey_result_chafen.at<char>(i,j)) <= T){
                //cout<<int(grey_result_chafen.at<char>(i,j))<<endl;
                forground.at<cv::Vec3b>(i,j) = Null_color;
            }else{
                background.at<cv::Vec3b>(i,j) = Null_color;
            }
        }
    }

    saveResult_image(background,saved_path);

    cv::namedWindow("background");
    cv::namedWindow("foreground");
//    cv::namedWindow("result");
//    cv::imshow("result",grey_result_chafen);
    cv::imshow("foreground",forground);
    cv::imshow("background",background);
    cv::waitKey();
    cv::destroyAllWindows();
    return 0;
}

vector<cv::Mat> readVideo(string path){
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

bool saveResult_image(cv::Mat image,string path){
    cv::imwrite(path,image);
}