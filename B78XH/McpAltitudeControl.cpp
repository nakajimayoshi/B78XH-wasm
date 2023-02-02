#include "McpAltitudeControl.h"
#include "Simplane.h"
#include "LineControl.h"
#include "Tools/Console.h"

void McpAltitudeControl::setupControl() {
	Control::setupControl();
	add(std::make_unique<LineControl>("McpAltitudeControl"));
	add(std::make_unique<LineControl>("McpAltLabelControl"));
}

void McpAltitudeControl::prepareControls() {
	Control::prepareControls();
}

void McpAltitudeControl::setupControls() {
	Control::setupControls();
	auto& altitude = getControl("McpAltitudeControl");

	altitude->getContentHolder().setFontFace("787mcp");
	altitude->getContentHolder().setDefaultFontSize(120.0f);
	altitude->position.setPosition(450, 75, 0, 0);
	altitude->getContentHolder().setAlign(ContentHolder::ALIGN::RIGHT);
	altitude->addOnBeforeRender([](BaseControl& control) -> bool {

		control.getContentHolder().setContent({ {std::to_string(static_cast<int>(Simplane::autopilot::altitude::altitudeLockVar3()))}});
		return true;
	});

	altitude->addOnValidate([](BaseControl& control) -> bool {
		return false;
		});
}
