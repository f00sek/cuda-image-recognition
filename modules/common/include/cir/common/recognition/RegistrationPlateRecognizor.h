#ifndef REGISTRATIONPLATERECOGNIZOR_H_
#define REGISTRATIONPLATERECOGNIZOR_H_

#include "cir/common/ImageProcessingService.h"
#include "cir/common/recognition/Recognizor.h"

namespace cir { namespace common { namespace recognition {

class RegistrationPlateRecognizor : Recognizor {
public:
	RegistrationPlateRecognizor(cir::common::ImageProcessingService& service);
	virtual ~RegistrationPlateRecognizor();

	virtual const RecognitionInfo recognize(cir::common::MatWrapper& input) const;
	virtual void learn(cir::common::MatWrapper& input);
	virtual void learn(const char* filePath);

private:
	cir::common::MatWrapper detectAllColors(cir::common::MatWrapper& input) const;
	cir::common::MatWrapper detectBlue(cir::common::MatWrapper& input) const;
	cir::common::MatWrapper detectWhite(cir::common::MatWrapper& input) const;
};

}}}
#endif /* REGISTRATIONPLATERECOGNIZOR_H_ */
