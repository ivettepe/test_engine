#ifndef ENGINES_H
#define ENGINES_H

#include <vector>
#include "define.h"

namespace engines {
	struct internal_combustion_engine {
		double I = I_DEF;
		double overheat_temperature = OVERHEAT_TEMPERATURE_DEF;
		double Hm = Hm_DEF;
		double Hv = Hv_DEF;
		double C = C_DEF;
		std::vector<int> start_M = START_M_DEF;
		std::vector<int> start_V = START_V_DEF;

		double M;
		double V;

		double Vc(double outside_temperature, double engine_temperature);
		double Vh();
	};

}

#endif // ENGINES_H