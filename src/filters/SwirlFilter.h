//
//  SwirlFilter.h
//  filterSandbox
//
//  Created by Kenta Watashima on 7/17/14.
//
//

#ifndef __filterSandbox__SwirlFilter__
#define __filterSandbox__SwirlFilter__

#include "AbstractFilter.h"

class SwirlFilter : public AbstractFilter {
public:
	SwirlFilter(float width, float height, float radius=0.5, float angle=1.0, ofVec2f center=ofVec2f(0.5, 0.5));
	virtual ~SwirlFilter();
	
    virtual void    onKeyPressed(int key);
    virtual string  getInstructions() { return "Left and Right change angle: " + ofToString(_angle) + "\nUp and Down change radius: " + ofToString(_radius); }
	
    
protected:
    virtual string  _getFragSrc();
    float           _radius;
	float			_angle;
	ofVec2f			_center;
};

#endif /* defined(__filterSandbox__SwirlFilter__) */
