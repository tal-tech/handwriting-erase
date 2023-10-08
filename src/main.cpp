#include "ai_model.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    // 读取图片
    cv::Mat m1 = cv::imread("../ai_model/release/data/images/testing/1.jpg");
    // 初始化模型
    AIModel::Init();
    // 处理图片
    AIModel::AlgProcess(m1);
    // 释放模型
    AIModel::Release();
    return 0;
}