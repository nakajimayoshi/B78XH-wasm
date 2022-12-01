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


#include "PFDTargetAltitudeApplication.h"

#include <cmath>
#include "Simplane.h"
#include "Tools/Tools.h"

using Colors = Tools::Colors;


void PFDTargetAltitudeApplication::render(sGaugeDrawData* data) {
	drawBackground();
	drawValue();
}

void PFDTargetAltitudeApplication::drawBackground() const {
	nvgFillColor(this->nvgContext, Colors::black);
	nvgBeginPath(this->nvgContext);
	{
		//nvgRect(this->nvgContext, 635, 30, 80, 38);
		nvgRect(this->nvgContext, 0, 0, 80, 38);
	}
	nvgClosePath(this->nvgContext);
	nvgFill(this->nvgContext);
}

void PFDTargetAltitudeApplication::drawValue() const {
	namespace Autopilot = Simplane::autopilot;

	const double selectedAltitude = Autopilot::altitude::altitudeLockVar();
	const int integral = floor(selectedAltitude / 1000);
	const int modulo = floor(selectedAltitude - (integral * 1000));
	const auto cstrModulo = fmt::format("{:03}", modulo).c_str();
	float moduloBounds[4];

	nvgFontFace(this->nvgContext, "roboto");
	nvgFontSize(this->nvgContext, 30.0f);
	nvgFillColor(this->nvgContext, Colors::magenta);
	nvgTextAlign(this->nvgContext, NVG_ALIGN_RIGHT | NVG_ALIGN_BOTTOM);


	nvgTextBounds(this->nvgContext, 77, 37, cstrModulo, nullptr, moduloBounds);
	nvgBeginPath(this->nvgContext);
	{
		nvgText(this->nvgContext, 77, 37, cstrModulo, nullptr);
		nvgFontSize(this->nvgContext, 40.0f);
		nvgText(this->nvgContext, moduloBounds[0], moduloBounds[3] + 2, std::to_string(integral).c_str(), nullptr);
	}
	nvgClosePath(this->nvgContext);
	nvgFill(this->nvgContext);
}
