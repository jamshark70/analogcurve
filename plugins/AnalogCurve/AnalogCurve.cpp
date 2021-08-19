// PluginAnalogCurve.cpp
// James Harkins (jamshark70@zoho.com)

#include "SC_PlugIn.hpp"
#include "AnalogCurve.hpp"

static InterfaceTable* ft;

namespace AnalogCurve {

AnalogCurve::AnalogCurve() {
    mCalcFunc = make_calc_function<AnalogCurve, &AnalogCurve::next>();
    next(1);
}

// TODO: De-zipper the factor and offset inputs
void AnalogCurve::next(int nSamples) {
    const float* input = in(0);
    float factor = *in(1);
    float offset = *in(2);
    
    float* outbuf = out(0);

    // Distortion formula stolen from
    // https://github.com/VCVRack/Fundamental/blob/v1/src/VCO.cpp#L23
    for (int i = 0; i < nSamples; ++i) {
        float x = input[i];
        float x01 = x * 0.5f + 0.5f;
        // *(outbuf++) = (((x * factor + offset) * x + 3) / (x * 2 + 3));
        // denominator: 0-1 * 2 --> 0-2, then +3 --> 3-5 == x+4
        *(outbuf++) = (((x01 * factor + offset) * x01 + 3.f) / (x + 4.f));
    }
}

} // namespace AnalogCurve

PluginLoad(AnalogCurveUGens) {
    // Plugin magic
    ft = inTable;
    registerUnit<AnalogCurve::AnalogCurve>(ft, "AnalogCurve", false);
}
