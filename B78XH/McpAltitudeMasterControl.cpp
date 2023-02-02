#include "McpAltitudeMasterControl.h"
#include "McpAltitudeControl.h"

void ::McpAltitudeMasterControl::prepareControls() {
	MasterControl::prepareControls();
	add(std::make_unique<McpAltitudeControl>("McpAltitudeControl"));
}

void ::McpAltitudeMasterControl::setupControls() {
	MasterControl::setupControls();
}
