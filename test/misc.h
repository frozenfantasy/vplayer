#ifndef MISC_H
#define MISC_H

#include "temp_manager.h"

namespace cv { class Mat; }
class QImage;

QImage mat2QImage(const cv::Mat& mat);

class misc
{
public:
    misc();
};

#endif // MISC_H
