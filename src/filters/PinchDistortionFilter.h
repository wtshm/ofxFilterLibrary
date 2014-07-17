//
//  PinchDistortionFilter.h
//  filterSandbox
//
//  Created by Kenta Watashima on 7/17/14.
//
//

#ifndef __filterSandbox__PinchDistortionFilter__
#define __filterSandbox__PinchDistortionFilter__

#include "AbstractFilter.h"

class PinchDistortionFilter : public AbstractFilter {
public:
	PinchDistortionFilter(float width, float height, float radius=1.0, float scale=0.5, ofVec2f center=ofVec2f(0.5, 0.5));
	virtual ~PinchDistortionFilter();
	
    virtual void    onKeyPressed(int key);
    virtual string  getInstructions() { return "Left and Right change scale: " + ofToString(_scale) + "\nUp and Down change radius: " + ofToString(_radius); }
	
    
protected:
    virtual string  _getFragSrc();
    float           _radius;
	float			_scale;
	ofVec2f			_center;
};

#endif /* defined(__filterSandbox__PinchDistortionFilter__) */
