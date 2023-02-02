#include "McpHeadingMasterControl.h"
#include "McpHeadingControl.h"

void McpHeadingMasterControl::prepareControls() {
	MasterControl::prepareControls();
	add(std::make_unique<McpHeadingControl>("McpHeadingControl"));
}

void McpHeadingMasterControl::setupControls() {
	MasterControl::setupControls();
	addOnValidate([](BaseControl& control) -> bool {
		return false;
		});
}

