//
//  FalseColorFilter.cpp
//  filterSandbox
//
//  Created by Kenta Watashima on 7/17/14.
//
//

#include "FalseColorFilter.h"

FalseColorFilter::FalseColorFilter(ofVec3f firstColor, ofVec3f secondColor) : AbstractFilter(0, 0) {
    _name = "False Color";
    _addParameter(new Parameter3f("firstColor", firstColor));
    _addParameter(new Parameter3f("secondColor", secondColor));
    _setupShader();
}
FalseColorFilter::~FalseColorFilter() {}

string FalseColorFilter::_getFragSrc() {
    return GLSL_STRING(120,
        uniform sampler2D inputImageTexture;
        uniform float intensity;
        uniform vec3 firstColor;
        uniform vec3 secondColor;

        const vec3 luminanceWeighting = vec3(0.2125, 0.7154, 0.0721);

        void main()
        {
		    vec2 textureCoordinate = gl_TexCoord[0].xy;
            vec4 textureColor = texture2D(inputImageTexture, textureCoordinate);
            float luminance = dot(textureColor.rgb, luminanceWeighting);

            gl_FragColor = vec4( mix(firstColor.rgb, secondColor.rgb, luminance), textureColor.a);
        }
    );
}