#include "engines.h"

namespace engines {
	double internal_combustion_engine::Vc(double outside_temperature, double engine_temperature) {
		return C * (outside_temperature - engine_temperature);
	}

	double internal_combustion_engine::Vh() {
		return M * Hm + V * V * Hv;
	}
}