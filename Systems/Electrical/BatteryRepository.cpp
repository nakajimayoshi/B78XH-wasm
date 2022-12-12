//    B78XH-wasm
//    Copyright (C) 2022  Heavy Division
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <https://www.gnu.org/licenses/>.


#include "BatteryRepository.h"

using namespace units::voltage;
using namespace units::current;
using namespace units::power;

auto BatteryRepository::isDischarging() -> bool {
    return false;
}

auto BatteryRepository::getCapacity() -> double {
    return 0.;
}

auto BatteryRepository::getCurrent() -> units::current::ampere_t {
    return static_cast<ampere_t>(0.);
}

auto BatteryRepository::getOutputPotential() -> units::voltage::volt_t {
    return static_cast<volt_t>(0.);
}

auto BatteryRepository::getInputPotential() -> units::voltage::volt_t {
    return static_cast<volt_t>(0.);
}

auto BatteryRepository::getPower() -> units::power::watt_t {
    return static_cast<watt_t>(getCurrent() * getOutputPotential());
};

