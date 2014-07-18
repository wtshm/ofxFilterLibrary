//
//  SwirlFilter.cpp
//  filterSandbox
//
//  Created by Kenta Watashima on 7/17/14.
//
//

#include "SwirlFilter.h"

SwirlFilter::SwirlFilter(float width, float height, float radius, float angle, ofVec2f center) : AbstractFilter(width, height) {
    _name = "Swirl";
	_radius = radius;
	_angle = angle;
	_center = center;
    _addParameter(new ParameterF("radius", radius));
    _addParameter(new ParameterF("angle", angle));
	_addParameter(new Parameter2f("center", center));
    _setupShader();
}
SwirlFilter::~SwirlFilter() {}

void SwirlFilter::onKeyPressed(int key) {
    if (key==OF_KEY_LEFT) _angle -= 0.1;
    else if (key==OF_KEY_RIGHT) _angle += 0.1;
    else if (key==OF_KEY_UP) _radius += 0.1;
    else if (key==OF_KEY_DOWN) _radius -= 0.1;
    if (_angle<0) _angle = 0;
    if (_radius<0) _radius = 0;
    if (_radius>1.0) _radius = 1.0;
    updateParameter("angle", _angle);
    updateParameter("radius", _radius);
}

void SwirlFilter::setRadius(float radius) {
	_radius = radius;
	updateParameter("radius", radius);
}

void SwirlFilter::setAngle(float angle) {
	_angle = angle;
	updateParameter("angle", angle);
}

string SwirlFilter::_getFragSrc() {
    return GLSL_STRING(120,
        uniform sampler2D inputImageTexture;
        
        uniform vec2 center;
        uniform float radius;
        uniform float angle;
        
        void main()
        {
			vec2 textureCoordinate = gl_TexCoord[0].xy;
			
            vec2 textureCoordinateToUse = textureCoordinate;
            float dist = distance(center, textureCoordinate);
            if (dist < radius)
            {
                textureCoordinateToUse -= center;
                float percent = (radius - dist) / radius;
                float theta = percent * percent * angle * 8.0;
                float s = sin(theta);
                float c = cos(theta);
                textureCoordinateToUse = vec2(dot(textureCoordinateToUse, vec2(c, -s)), dot(textureCoordinateToUse, vec2(s, c)));
                textureCoordinateToUse += center;
            }
            
            gl_FragColor = texture2D(inputImageTexture, textureCoordinateToUse );
        }
    );
}