#include "PFDTargetAltitude.h"
#include <cmath>
#include "fmt/core.h"
#include "Simplane.h"

void PFDTargetAltitude::draw(NVGcontext* context, float windowWidth, float windowHeight) {
	nvgSave(context);
	drawBackground(context, windowWidth, windowHeight);
	drawValue(context, windowWidth, windowHeight);
	nvgRestore(context);
}

void PFDTargetAltitude::drawBackground(NVGcontext* context, float windowWidth, float windowHeight) {
	nvgFillColor(context, nvgRGB(0, 0, 0));
	nvgBeginPath(context);
	{
		//nvgRect(context, 635, 30, 80, 38);
		nvgRect(context, 0, 0, 80, 38);
	}
	nvgClosePath(context);
	nvgFill(context);
}

void PFDTargetAltitude::drawValue(NVGcontext* context, float windowWidth, float windowHeight) {
	namespace Autopilot = Simplane::autopilot;

	const double selectedAltitude = Autopilot::altitude::altitudeLockVar();
	const int integral = floor(selectedAltitude / 1000);
	const int modulo = floor(selectedAltitude - (integral * 1000));
	const auto cstrModulo = fmt::format("{:03}", modulo).c_str();
	float moduloBounds[4];

	nvgFontFace(context, "roboto");
	nvgFontSize(context, 30.0f);
	nvgFillColor(context, nvgRGB(213, 112, 255));
	nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_BOTTOM);


	nvgTextBounds(context, 77, 37, cstrModulo, nullptr, moduloBounds);
	nvgBeginPath(context);
	{
		nvgText(context, 77, 37, cstrModulo, nullptr);
		nvgFontSize(context, 40.0f);
		nvgText(context, moduloBounds[0], moduloBounds[3] + 2, std::to_string(integral).c_str(), nullptr);
	}
	nvgClosePath(context);
	nvgFill(context);
}
