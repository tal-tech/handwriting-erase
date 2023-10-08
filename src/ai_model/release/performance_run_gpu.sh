mkdir det_res
export PATH=$PATH:/usr/local/cuda-11.2/bin
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/cuda-11.2/lib64:./lib

# Set head pose model
MODEL=data/models/det_handwrite_erase_v1.0.0.onnx
# MODEL=/data/wangdeqiang/det_handwrite_erase/data/models/det_handwrite_erase_v1.0.0.onnx

# Set test data
IMAGES_PATH=data/images/testing
#IMAGES_PATH=/data/rongcuo_all
# IMAGES_PATH=/data/wangdeqiang/det_handwrite_erase/data/images/testing

# Set test data
CONFIG_PATH=data/config.ini
# CONFIG_PATH=/data/wangdeqiang/det_handwrite_erase/data/config.ini

MAX_BATCH=1

OUTPUT_TO_LOG=0

REPEAT_COUNT=1

bin/performance_testing $MODEL $IMAGES_PATH $CONFIG_PATH $MAX_BATCH $OUTPUT_TO_LOG $REPEAT_COUNT





