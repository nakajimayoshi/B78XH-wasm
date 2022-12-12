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


#pragma once

#include "Systems/units.h"

Class BatteryRepository {
protected:

    auto getPower() -> units::power::watt_t;

public:
    virtual ~BatteryRepository() = default;
    // placeholder classes:
    struct ElectricalStateWriter {};
    struct ElectricalElementIdentifier {};

    virtual auto getCapacity() -> double;
    virtual auto getOutputPotential() -> units::voltage::volt_t;
    virtual auto getInputPotential() -> units::voltage::volt_t;
    virtual auto isDischarging() -> bool;
    virtual auto getCurrent() -> units::current::ampere_t;


    units::voltage::volt_t input_potential;
    units::voltage::volt_t output_potential;
    units::current::ampere_t current;
};