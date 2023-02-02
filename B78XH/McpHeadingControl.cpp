#include "McpHeadingControl.h"
#include "LineControl.h"
#include "Simplane.h"

void McpHeadingControl::prepareControls() {
	Control::prepareControls();
	add(std::make_unique<LineControl>("McpHeadingControl"));
}

void McpHeadingControl::setupControls() {
	Control::setupControls();
	auto& hdg = getControl("McpHeadingControl");

	hdg->getContentHolder().setAlign(ContentHolder::ALIGN::RIGHT);
	hdg->getContentHolder().setFontFace("787mcp");
	hdg->getContentHolder().setDefaultFontSize(120.0f);
	hdg->position.setPosition(250, 50, 0, 0);

	hdg->addOnBeforeRender([](BaseControl& control) -> bool {

		control.getContentHolder().setContent({ {std::to_string(Simplane::autopilot::heading::headingLockVar1())}});
		return true;
	});

	hdg->addOnValidate([](BaseControl& control) -> bool {
		return false;
		});
}

void McpHeadingControl::setupControl() {
	Control::setupControl();
}
