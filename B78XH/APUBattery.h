// #pragma once
//
// #include "BatteryRepository.h"
//
// class APUBattery {
// private:
// 	BatteryRepository* apu_battery = new BatteryRepository;
// 	double rated_capacity = 65.;
//
// public:
//
// 	auto getInputPotential() -> units::voltage::volt_t;
// 	auto getOutputPotential() -> units::voltage::volt_t;
// 	auto getCurrent() -> units::current::ampere_t;
// 	bool isDischarging();
//
// 	bool isStarterActive();
// 	bool isOn();
// };