#include "test_stand.h"
#include "data_io.h"

int main() {
	double outside_temperature;
	data_io::intput_temperature(&outside_temperature);
	engines::internal_combustion_engine engine;
	stand_area::test_stand<engines::internal_combustion_engine> stand(engine, outside_temperature);
	data_io::output_time(stand.start_engine());
	return 0;
}
