#include "MFDMenuButton.h"

void MFDMenuButton::draw() {
	if (this->context != nullptr) {
		if (this->event) {
			CDUButton::draw();
			if (this->isInFocus()) {
				MFDMenuButton::drawBorder();
			}
		}
		else {
			drawBackBorders(Tools::Colors::cyan);
			CDUButton::drawTitle(Tools::Colors::cyan);
		}
	}
	this->shouldTriggerEvent();
		
}

void MFDMenuButton::drawBorder() {
	nvgStrokeColor(context, Tools::Colors::magenta);
	nvgStrokeWidth(this->context, 5.0f);
	nvgBeginPath(this->context);
	{
		nvgMoveTo(this->context, this->x, this->y);
		nvgLineTo(this->context, this->x + 208, this->y);
		nvgLineTo(this->context, this->x + 208, this->y + this->height);
		nvgLineTo(this->context, this->x, this->y + this->height);
	}
	nvgClosePath(this->context);
	nvgStroke(this->context);
}


void MFDMenuButton::shouldTriggerEvent() {
	this->calculateBounds();
	if (this->mouseClickResolver.getX() >= this->bounds[0] && this->mouseClickResolver.getX() <= this->bounds[1] &&
		this->mouseClickResolver.getY() >= this->bounds[2] && this->mouseClickResolver.getY() <= this->bounds[
			3]) {
		if (this->event) {
			this->mouseClickResolver.reset();
			this->event();
		}
	}
}