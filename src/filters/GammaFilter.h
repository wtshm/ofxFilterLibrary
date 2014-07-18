//
//  GammaFilter.h
//  filterSandbox
//
//  Created by Kenta Watashima on 7/18/14.
//
//

#ifndef __filterSandbox__GammaFilter__
#define __filterSandbox__GammaFilter__

#include "AbstractFilter.h"

class GammaFilter : public AbstractFilter {
public:
	GammaFilter(float width, float height, float gamma=1.f);
	virtual ~GammaFilter();
    void            setGamma(float gamma);
    virtual void    onKeyPressed(int key);
    virtual string  getInstructions() { return "Up and Down change gamma: " + ofToString(_gamma); }
	
protected:
    virtual string  _getFragSrc();
    float           _gamma;
};

#endif /* defined(__filterSandbox__GammaFilter__) */
