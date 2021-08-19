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

    // Member variables
};

} // namespace AnalogCurve
