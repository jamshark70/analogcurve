AnalogCurve : UGen {
	*ar { arg in = 0.0, factor = 5, offset = -13, mul = 1.0, add = 0.0;
		^this.multiNew('audio', in, factor, offset).madd(mul, add)
	}
	*kr { arg in = 0.0, factor = 5, offset = -13, mul = 1.0, add = 0.0;
		^this.multiNew('control', in, factor, offset).madd(mul, add)
	}
	checkInputs {
		/* TODO */
		^this.checkSameRateAsFirstInput;
	}
}
