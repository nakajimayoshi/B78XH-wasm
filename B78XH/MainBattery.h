#pragma once

#include "Systems/BatteryRepository.h"
#include "units.h"
#include "BatteryType.h"
#include "LVars.h"
#include "LVar.h"

class MainBattery : public BatteryRepository {
    BatteryRepository* main_battery = new BatteryRepository();
private:

    double rated_capacity = 65.;
    
public:
    BatteryType battery_type = MAIN_BATT;
    auto getOutputPotential() -> units::voltage::volt_t override;
    auto getInputPotential() -> units::voltage::volt_t override;
    auto isDischarging() -> bool override;
    auto getCurrent() -> units::current::ampere_t override;
};