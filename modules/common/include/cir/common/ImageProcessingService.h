#ifndef IMAGEPROCESSINGSERVICE_H_
#define IMAGEPROCESSINGSERVICE_H_

#include "cir/common/MatWrapper.h"
#include "cir/common/SegmentArray.h"
#include "cir/common/Pattern.h"
#include <iostream>
#include <map>
#include "cir/common/logger/Logger.h"
#include "cir/common/Hsv.h"

namespace cir { namespace common {

class ImageProcessingService {
protected:
	static int DEFAULT_LOW_PASS_KERNEL_SIZE;

public:
	ImageProcessingService(cir::common::logger::Logger& logger);
	virtual ~ImageProcessingService();

	virtual const char* getModule() = 0;

	virtual MatWrapper toGrey(const MatWrapper& input);
	virtual MatWrapper threshold(const MatWrapper& input, double thresholdValue);
	virtual MatWrapper lowPass(const MatWrapper& input, int size = 3);
	virtual MatWrapper highPass(const MatWrapper& input, int size = 1);
	virtual MatWrapper bgrToHsv(const MatWrapper& input);
	virtual MatWrapper hsvToBgr(const MatWrapper& input);
	virtual MatWrapper detectColorHsv(const MatWrapper& input, const int hsvRangesNumber, const HsvRange* hsvRanges);
	virtual SegmentArray* segmentate(const MatWrapper& input);
	virtual MatWrapper mark(MatWrapper& input, SegmentArray* segmentArray) = 0;
	virtual MatWrapper crop(MatWrapper& input, Segment* segment) = 0;
	virtual double* countHuMoments(const MatWrapper& matWrapper);
	virtual void loadPattern(std::string filePath);

protected:
	static cv::Mat DEFAULT_LOW_PASS_KERNEL;

	std::map<std::string, Pattern*> _patterns;
	cir::common::logger::Logger& _logger;

	virtual MatWrapper doToGrey(const MatWrapper& input) = 0;
	virtual MatWrapper doThreshold(const MatWrapper& input, double thresholdValue) = 0;
	virtual MatWrapper doLowPass(const MatWrapper& input, int size = 3) = 0;
	virtual MatWrapper doHighPass(const MatWrapper& input, int size = 1) = 0;
	virtual MatWrapper doBgrToHsv(const MatWrapper& input) = 0;
	virtual MatWrapper doHsvToBgr(const MatWrapper& input) = 0;
	virtual MatWrapper doDetectColorHsv(const MatWrapper& input, const int hsvRangesNumber, const HsvRange* hsvRanges) = 0;
	virtual SegmentArray* doSegmentate(const MatWrapper& input) = 0;
	virtual double* doCountHuMoments(const MatWrapper& matWrapper) = 0;
};

}}
#endif
