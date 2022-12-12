#include "B78XBattery.h"
#include "Tools/Console.h"



auto B78XBattery::print()-> void {
	B78XBattery battery;
	this->RATED_CAPACITY_AMPERE_HOURS = 45.;
	Console::log("{}", this->empty());
	Console::log("{}", this->half());
	Console::log("{}", this->full());
};
