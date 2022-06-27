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
#include <MSFS/Legacy/gauges.h>
#include <string>

namespace Tools {
	class Frequencies {
		public:
			enum type {
				VHF
			};

			enum state {
				ACTIVE,
				STANDBY
			};

			enum vhf_index {
				ONE = 1,
				TWO = 2,
				THREE = 3
			};

			static void setVHFFrequency(vhf_index index, state state, FLOAT64 value);
			static void setVHFActiveFrequency(vhf_index index, FLOAT64 value);
			static void setVHFStandbyFrequency(vhf_index index, FLOAT64 value);
			static void swapVHFFrequencies(vhf_index index);
			static bool isVHFFrequencyValid(FLOAT64 MHz);
			static bool isHz833Compliant(FLOAT64 MHz);
			static bool isHz25Compliant(FLOAT64 MHz);
			static bool isHz50Compliant(FLOAT64 MHz);
	};

	class Transponder {
		public:
			static bool isXPDRCompliant(std::string value);
			static void setCode(std::string value);
			static void ident();
	};
}