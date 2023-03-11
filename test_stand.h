#ifndef TEST_STAND_H
#define TEST_STAND_H

#include "engines.h"
#include "define.h"

namespace stand_area {
	template <typename T> class test_stand {
		int vector_position;
		double engine_temperature;
		double outside_temperature;
		T* engine;

	public:
		int start_engine();
		test_stand(T& engine, const double outside_temperature);
	};

	template<typename T> test_stand<T>::test_stand(T & engine, const double outside_temperature) {
		vector_position = 0;
		this->engine = &engine;
		this->engine->M = engine.start_M[vector_position];
		this->engine->V = engine.start_V[vector_position];
		engine_temperature = outside_temperature;
		this->outside_temperature = outside_temperature;
	}


	template<typename T> int test_stand<T>::start_engine() {
		double a = engine->M * engine->I;
		double eps = engine->overheat_temperature - engine_temperature;
		int time = 0;
		while (eps > ABSOLUTE_ERROR && time < MAX_TIME) {
			time++;
			engine->V += a;
			int start_m_size = engine->start_M.size();
			if (vector_position < (start_m_size - 2))
				vector_position += engine->V < engine->start_V[vector_position + 1] ? 0 : 1;
			double up = (engine->V - engine->start_V[vector_position]);
			double down = (engine->start_V[vector_position + 1] - engine->start_V[vector_position]);
			double factor = (engine->start_M[vector_position + 1] - engine->start_M[vector_position]);
			engine->M = up / down * factor + engine->start_M[vector_position];

			engine_temperature += engine->Vc(outside_temperature, engine_temperature) + engine->Vh();

			a = engine->M * engine->I;

			eps = engine->overheat_temperature - engine_temperature;
		}
		return time;
	}

}

#endif // TEST_STAND_H