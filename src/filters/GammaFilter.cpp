//
//  GammaFilter.cpp
//  filterSandbox
//
//  Created by Kenta Watashima on 7/18/14.
//
//

#include "GammaFilter.h"

GammaFilter::GammaFilter(float width, float height, float gamma) : AbstractFilter(width, height) {
    _name = "Gamma";
	_gamma = gamma;
    _addParameter(new ParameterF("gamma", gamma));
    _setupShader();
}
GammaFilter::~GammaFilter() {}

void GammaFilter::onKeyPressed(int key) {
    if (key==OF_KEY_UP) _gamma+=0.2f;
    else if (key==OF_KEY_DOWN) _gamma-=0.2f;
    if (_gamma<0) _gamma = 0;
    setGamma(_gamma);
}

string GammaFilter::_getFragSrc() {
    return GLSL_STRING(120,
        uniform sampler2D inputImageTexture;
        uniform float gamma;

        void main()
        {
			vec2 textureCoordinate = gl_TexCoord[0].xy;
            vec4 textureColor = texture2D(inputImageTexture, textureCoordinate);

            gl_FragColor = vec4(pow(textureColor.rgb, vec3(gamma)), textureColor.w);
        }
    );
}

void GammaFilter::setGamma(float gamma) {
	_gamma = gamma;
	updateParameter("gamma", gamma);
}
