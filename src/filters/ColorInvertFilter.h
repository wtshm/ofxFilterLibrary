//
//  ColorInvertFilter.h
//  filterSandbox
//
//  Created by Kenta Watashima on 7/17/14.
//
//

#ifndef __filterSandbox__ColorInvertFilter__
#define __filterSandbox__ColorInvertFilter__

#include "AbstractFilter.h"

class ColorInvertFilter : public AbstractFilter {
public:
	ColorInvertFilter();
	virtual ~ColorInvertFilter();
	
protected:
    virtual string  _getFragSrc();
};

#endif /* defined(__filterSandbox__ColorInvertFilter__) */
