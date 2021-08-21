// PluginAnalogCurve.hpp
// James Harkins (jamshark70@zoho.com)

#pragma once

#include "SC_PlugIn.hpp"

namespace AnalogCurve {

class AnalogCurve : public SCUnit {
public:
    AnalogCurve();

    // Destructor
    // ~AnalogCurve();

private:
    // Calc function
    void next(int nSamples);
    void next8(int nSamples);
  
    // Member variables
    // float mFactor = 5.;
    // float mOffset = -13.;
};

} // namespace AnalogCurve
