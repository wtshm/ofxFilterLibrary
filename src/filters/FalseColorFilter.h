//
//  FalseColorFilter.h
//  filterSandbox
//
//  Created by Kenta Watashima on 7/17/14.
//
//

#ifndef __filterSandbox__FalseColorFilter__
#define __filterSandbox__FalseColorFilter__

#include "AbstractFilter.h"

class FalseColorFilter : public AbstractFilter {
public:
	FalseColorFilter(ofVec3f firstColor = ofVec3f(0.0, 0.0, 0.5), ofVec3f secondColor = ofVec3f(1.0, 0.0, 0.0));
	virtual ~FalseColorFilter();
	void setFirstColor(ofVec3f firstColor);
	void setSecondColor(ofVec3f secondColor);
	
protected:
    virtual string  _getFragSrc();
	ofVec3f         _firstColor;
	ofVec3f         _secondColor;
};

#endif /* defined(__filterSandbox__FalseColorFilter__) */
