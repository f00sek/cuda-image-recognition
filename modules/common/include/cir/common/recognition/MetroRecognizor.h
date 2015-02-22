#ifndef METRORECOGNIZOR_H_
#define METRORECOGNIZOR_H_

#include "cir/common/recognition/Recognizor.h"
#include "cir/common/recognition/heuristic/PatternHeuristic.h"

namespace cir { namespace common { namespace recognition {

class MetroRecognizor : Recognizor {
public:
	MetroRecognizor(cir::common::ImageProcessingService& service);
	virtual ~MetroRecognizor();

	virtual const RecognitionInfo recognize(cir::common::MatWrapper& input) const;
	virtual void learn(cir::common::MatWrapper& input);
	virtual void learn(const char* filePath);

private:
	cir::common::MatWrapper detectAllColors(cir::common::MatWrapper& input) const;
	cir::common::MatWrapper detectRed(cir::common::MatWrapper& input) const;
	cir::common::MatWrapper detectYellow(cir::common::MatWrapper& input) const;

	cir::common::recognition::Pattern _pattern;
	cir::common::recognition::heuristic::PatternHeuristic* _heuristic;
};

}}}
#endif /* METRORECOGNIZOR_H_ */
