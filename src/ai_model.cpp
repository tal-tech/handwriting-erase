#include "ai_model.h"
#include <mutex>
#include <unistd.h>
#include <iostream>

// new
#include "opencv2/imgcodecs/legacy/constants_c.h"
#include <regex>

static const int ALG_SUC = 0;
static const int ALG_ERROR = -1;
static const int ALG_FAILED = -2;
static const int ALG_IMG_ABNORMAL = -3;

std::mutex g_reger_lock;

DetHandwriteErase* AIModel::model_ = nullptr;

bool AIModel::Init() {
    if(!model_) {
        try {
            const std::string str_model_file = "../ai_model/release/data/models/det_handwrite_erase_v1.0.8.onnx";
            const std::string str_config_file = "../ai_model/release/data/config.ini";
            // 留着opencv库
            model_ = DetHandwriteErase::create(str_model_file, str_config_file);
            if(!model_) {
                std::cout <<  "AIModel::init failed!";
                return false;
            }
        } catch (std::exception &e) {
            std::cout <<  "AIModel::init exception:" << e.what();
            return false;
        }
        std::cout <<  "AIModel::init success";
        return true;
    }
    return true;
}

void AIModel::Release() {
    if(model_) {
        delete model_;
        model_ = nullptr;
    }
}

void AIModel::AlgProcess(const cv::Mat &srcMat) {
    try {
        std::cout << "alg_process start!!! " << std::endl;
        if(!model_) {
            std::cout <<  " model_ == null";
            return ;
        }
        std::vector<cv::Mat> img_list;
        img_list.push_back(srcMat);

        // 调用算法模型
        int recode = 1;
        cv::Mat ret_img;
        int n_code = 0;
        {
            std::unique_lock<std::mutex> lock_guard{g_reger_lock};
            recode = model_->detection(img_list, ret_img);
            std::cout << "model_->detection() return code: " << recode << std::endl;
            switch (recode)
            {
            case 0:
                std::cout << "检测成功。" << std::endl;
                break;
            case -1:
                std::cout << "模型初始化失败或模型推理出错" << std::endl;
            case -2:
                std::cout << "模型推理结果为空" << std::endl;
            case -3:
                std::cout << "输入图片为空或图片比例异常或图片通道异常" << std::endl;
            default:
                break;
            }
        }
        std::cout << "alg_process end!!!" << std::endl;
        cv::imwrite("../demo.jpg",ret_img);
        std::cout << "path: " << "../demo.jpg" << std::endl;
    } catch (std::exception &e) {
        std::cout << "exception: " << e.what() << std::endl;
        return ;
    }
}
