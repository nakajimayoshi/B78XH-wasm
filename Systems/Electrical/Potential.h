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


#include "../../Libraries/units.h"
#include <unordered_set>

/// Within an electrical system, electric potential is made available by an origin.
/// These origins are contained in this type. By knowing the origin of potential
/// for all power consumers one can determine the amount of electric current provided
/// by the origin to the whole aircraft.
///
/// Note that this type shouldn't be confused with uom's `ElectricPotential`, which provides
/// the base unit (including volt) for defining the amount of potential.
/// The raw `ElectricPotential` is included in this type.
///
/// The raw `ElectricPotential` is ignored when determining if the potential
/// is powered or not. If we wouldn't ignore it, passing electric potential across the
/// circuit would take multiple simulation ticks, as _V_ for origins (ENG GEN, TR, etc)
/// can only be calculated when electrical consumption is known, which is the case at
/// the end of a simulation tick.
///
/// For the reasons outlined above when creating e.g. an engine generator, ensure you
/// return `Potential::none()` when the generator isn't supplying potential, and
/// `Potential::new(PotentialOrigin::EngineGenerator(1), ElectricPotential::new::<volt>(115.))`
/// when it is.

class Potential {
    public:
    //placeholder classes
        struct PotentialOrigin {};
        struct ElectricalElementIdentifier {};

        std::unordered_set<PotentialOrigin> origins;
        std::unordered_set<ElectricalElementIdentifier> elements;
        units::voltage::volt_t raw;
};
