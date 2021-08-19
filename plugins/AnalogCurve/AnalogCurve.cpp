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

void AnalogCurve::next(int nSamples) {
    const float* input = in(0);
    const float* gain = in(1);
    float* outbuf = out(0);

    // simple gain function
    for (int i = 0; i < nSamples; ++i) {
        outbuf[i] = input[i] * gain[i];
    }
}

} // namespace AnalogCurve

PluginLoad(AnalogCurveUGens) {
    // Plugin magic
    ft = inTable;
    registerUnit<AnalogCurve::AnalogCurve>(ft, "AnalogCurve", false);
}
