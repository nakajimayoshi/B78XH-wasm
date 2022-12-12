#pragma once

#include "Systems/Electrical/BatteryRepository.h"

class Battery : public BatteryRepository {
public:
	auto print() -> void;
};