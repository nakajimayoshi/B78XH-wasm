#include "MFDCommBasePage.h"

void MFDCommBasePage::draw() {
	if (this->context != nullptr) {
		drawBackground();
		drawTitle();
	}
}

void MFDCommBasePage::drawBackground() const {

	nvgFillColor(this->context, this->backgroundColor);
	nvgBeginPath(this->context);
	{
		nvgRect(this->context, this->x, this->y, this->width, this->height);
	}
	nvgClosePath(this->context);
	nvgFill(this->context);
}