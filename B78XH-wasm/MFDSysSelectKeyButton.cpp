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

#include "MFDSysSelectKeyButton.h"

void MFDSysSelectKeyButton::draw() {
	if (this->context != nullptr) {
		if (this->event) {
			CDUButton::draw();
		}
		else {
			drawBackBorders(Tools::Colors::cyan);
		}
		this->drawPointers();
	}
	this->shouldTriggerEvent();
	if (this->isInFocus()) {
		MFDSysSelectKeyButton::drawBorder();
	}
}

void MFDSysSelectKeyButton::calculateBounds() {
		this->bounds[0] = this->x;
		this->bounds[1] = this->x + this->width + 200;
		this->bounds[2] = this->y;
		this->bounds[3] = this->y + this->height;

}

void MFDSysSelectKeyButton::drawBorder() {
	nvgStrokeColor(context, Tools::Colors::magenta);
	nvgStrokeWidth(this->context, 5.0f);
		nvgBeginPath(this->context);
		{
			nvgMoveTo(this->context, this->x + this->width, this->y);
			nvgLineTo(this->context, this->x - 200, this->y);
			nvgLineTo(this->context, this->x - 200, this->y + this->height);
			nvgLineTo(this->context, this->x + this->width, this->y + this->height);
		}
		nvgClosePath(this->context);
		nvgBeginPath(this->context);
		{
			nvgMoveTo(this->context, this->x, this->y);
			nvgLineTo(this->context, this->x + 200, this->y);
			nvgLineTo(this->context, this->x + 200, this->y + this->height);
			nvgLineTo(this->context, this->x, this->y + this->height);
		}
		nvgClosePath(this->context);
	nvgStroke(this->context);
}

void MFDSysSelectKeyButton::drawPointers() {

	nvgStrokeWidth(this->context, 1.5f);
	if (this->event) {
		nvgFillColor(this->context, Tools::Colors::white);
	}
	else {
		nvgFillColor(this->context, Tools::Colors::cyan);
	}
	nvgStrokeColor(this->context, Tools::Colors::black);

	nvgBeginPath(this->context);
	{
		nvgRoundedRect(this->context, this->x - 16 - 5, this->y + (this->height / 2) - 2, 16, 4, 2.0f);
	}
	nvgClosePath(this->context);
	nvgFill(this->context);
	nvgStroke(this->context);
}
