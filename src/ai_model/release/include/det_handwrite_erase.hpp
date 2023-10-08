///////////////////////////////////////////////////////////////////////////////////////
///  Copyright (C) 2017, TAL AILab Corporation, all rights reserved.
///
///  @file: det_handwrite_erase.hpp
///  @brief 手写痕迹擦除
///  @details 722.102.1.0.0.0
//
//
///  @version 1.0.0.0
///  @author Jie He
///  @date 2021-07-16
///
///  @see 使用参考：performance_testing.cpp
///
///////////////////////////////////////////////////////////////////////////////////////
#ifndef __FACETHINK_API_DET_HANDWRITE_ERASE_HPP__
#define __FACETHINK_API_DET_HANDWRITE_ERASE_HPP__
#include <math.h>

#include <opencv2/opencv.hpp>
#include <string>

#define EXPORT_CLASS
#define EXPORT_API extern "C" __attribute__((visibility("default")))
#define EXPORT_CLASS_API __attribute__((visibility("default")))
namespace ocrdetapi {
class EXPORT_CLASS DetHandwriteErase {
   public:
    EXPORT_CLASS_API explicit DetHandwriteErase(void);
    EXPORT_CLASS_API virtual ~DetHandwriteErase(void);

    /// \brief SDK初始化函数，必须先于任何其他SDK函数之前调用，create的重载函数。
    /// @param [in] det_model_file 指定SDK对应的模型文件路径。
    /// @param [in] config_file 指定SDK对应的参数配置文件路径,详情见config.ini文件。
    /// @return
    /// @remarks 初始化函数需要读取模型等文件，需要一定时间等待。
    EXPORT_CLASS_API static DetHandwriteErase* create(
        const std::string& det_model_file,
        const std::string& config_file);

    /// \brief 生成擦除后图片。
    /// @param [in] input_imgs, 输入图片组成的vector
    /// @param [out] ret_img, 输出图片，格式为cv::Mat
    /// @return
    /// @retval 0 检测成功。
    /// @retval -1 模型初始化失败或模型推理出错
    /// @retval -2 模型推理结果为空
    /// @retval -3 输入图片为空或图片比例异常或图片通道异常
    EXPORT_CLASS_API virtual int detection(std::vector<cv::Mat>& input_imgs,
                                           cv::Mat& ret_img) = 0;
};
}  // namespace ocrdetapi
#endif