#pragma once

#include "jsoncpp/json.h"
#include "./3rdParty/opencv/include/opencv2/opencv.hpp"
#include <vector>
#include <string>
#include "./ai_model/release/include/det_handwrite_erase.hpp"

using namespace std;
using namespace ocrdetapi;

class AIModel {
private:
    static DetHandwriteErase* model_;
public:
    AIModel() = delete;
    static bool Init();
    static void Release();
    static void AlgProcess(const cv::Mat &img);
};

