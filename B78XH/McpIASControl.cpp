#include "McpIASControl.h"

#include <string>

#include "LineControl.h"
#include "Tools/Console.h"
#include "Tools/Tools.h"
#include "Simplane.h"
#include "Lvars.h"

void McpIASControl::setupControl() {
	Control::setupControl();
	add(std::make_unique<LineControl>("McpIASControl"));
	add(std::make_unique<LineControl>("McpModeControl"));
}

void McpIASControl::setupControls() {
	Control::setupControls();
	auto& ias = getControl("McpIASControl");
	auto& mode = getControl("McpModeControl");

	ias->getContentHolder().setAlign(ContentHolder::ALIGN::LEFT);
	ias->getContentHolder().setDefaultFontSize(120);
	ias->getContentHolder().setDefaultFontColor(Tools::Colors::white);
	ias->position.setPosition(305, 70, 0, 0);
	ias->getContentHolder().setFontFace("787mcp");

	mode->getContentHolder().setAlign(ContentHolder::ALIGN::LEFT);
	mode->getContentHolder().setDefaultFontSize(90);
	mode->getContentHolder().setDefaultFontColor(Tools::Colors::white);
	mode->position.setPosition(20, 30, 0, 0);
	mode->getContentHolder().setFontFace("jost");

	LVars lvars;
	
	mode->addOnBeforeRender([lvars](BaseControl& control) -> bool {
		auto machMode = lvars.get(LVars::XMLVAR_AirSpeedIsInMach).isValue();
		auto modeHandler = [machMode]() -> std::string {
			if (!machMode) {
				return "I,A,S";
			}
		return "MACH";
			};
		// Console::log("{}", lvars.get(LVars::XMLVAR_AirSpeedIsInMach).isValue());
		

		control.getContentHolder().setContent({ {modeHandler()}});

	return true;
		});

	ias->addOnBeforeRender([lvars](BaseControl& control) -> bool {
		// Console::log("{}", lvars.get(LVars::XMLVAR_AirSpeedIsInMach).isValue());

	
		control.getContentHolder().setContent({ {std::to_string(static_cast<int>(Simplane::autopilot::airspeed::airspeedHoldVar()))}});
		return true;
		});
	
	ias->addOnValidate([](BaseControl& control) -> bool {
		return false;
	});

}

void McpIASControl::prepareControls() {
	Control::prepareControls();
}


