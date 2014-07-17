//
//  ColorInvertFilter.cpp
//  filterSandbox
//
//  Created by Kenta Watashima on 7/17/14.
//
//

#include "ColorInvertFilter.h"

ColorInvertFilter::ColorInvertFilter() : AbstractFilter(0, 0) {
    _name = "Color Invert";
    _setupShader();
}
ColorInvertFilter::~ColorInvertFilter() {}

string ColorInvertFilter::_getFragSrc() {
    return GLSL_STRING(120,
        uniform sampler2D inputImageTexture;

        void main()
        {
			vec2 textureCoordinate = gl_TexCoord[0].xy;
            vec4 textureColor = texture2D(inputImageTexture, textureCoordinate);

            gl_FragColor = vec4((1.0 - textureColor.rgb), textureColor.w);
        }
    );
}
