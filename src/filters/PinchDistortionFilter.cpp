//
//  PinchDistortionFilter.cpp
//  filterSandbox
//
//  Created by Kenta Watashima on 7/17/14.
//
//

#include "PinchDistortionFilter.h"

PinchDistortionFilter::PinchDistortionFilter(float width, float height, float radius, float scale, ofVec2f center) : AbstractFilter(width, height) {
    _name = "Pinch Distortion";
	_radius = radius;
	_scale = scale;
	_center = center;
    _addParameter(new ParameterF("aspectRatio", getHeight()/getWidth() ));
    _addParameter(new ParameterF("radius", radius));
    _addParameter(new ParameterF("scale", scale));
	_addParameter(new Parameter2f("center", center));
    _setupShader();
}
PinchDistortionFilter::~PinchDistortionFilter() {}

void PinchDistortionFilter::onKeyPressed(int key) {
    if (key==OF_KEY_LEFT) _scale -= 0.1;
    else if (key==OF_KEY_RIGHT) _scale += 0.1;
    else if (key==OF_KEY_UP) _radius += 0.1;
    else if (key==OF_KEY_DOWN) _radius -= 0.1;
    if (_scale<-2.0) _scale = -2.0;
    if (_scale>2.0) _scale = 2.0;
    if (_radius<0) _radius = 0;
    if (_radius>2.0) _radius = 2.0;
    updateParameter("scale", _scale);
    updateParameter("radius", _radius);
}

void PinchDistortionFilter::setRadius(float radius) {
	_radius = radius;
	updateParameter("radius", radius);
}

void PinchDistortionFilter::setScale(float scale) {
	_scale = scale;
	updateParameter("scale", scale);
}

string PinchDistortionFilter::_getFragSrc() {
    return GLSL_STRING(120,
        uniform sampler2D inputImageTexture;
        
        uniform float aspectRatio;
        uniform vec2 center;
        uniform float radius;
        uniform float scale;
        
        void main()
        {
			vec2 textureCoordinate = gl_TexCoord[0].xy;
			
            vec2 textureCoordinateToUse = vec2(textureCoordinate.x, (textureCoordinate.y * aspectRatio + 0.5 - 0.5 * aspectRatio));
            float dist = distance(center, textureCoordinateToUse);
            textureCoordinateToUse = textureCoordinate;
            
            if (dist < radius)
            {
                textureCoordinateToUse -= center;
                float percent = 1.0 + ((0.5 - dist) / 0.5) * scale;
                textureCoordinateToUse = textureCoordinateToUse * percent;
                textureCoordinateToUse += center;
                
                gl_FragColor = texture2D(inputImageTexture, textureCoordinateToUse );
            }
            else
            {
                gl_FragColor = texture2D(inputImageTexture, textureCoordinate );
            }
        }
    );
}