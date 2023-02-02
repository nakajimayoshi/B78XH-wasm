#include "McpIASMasterControl.h"
#include "McpIASControl.h"
#include "Tools/Console.h"
#include "Simplane.h"

void McpIASMasterControl::prepareControls() {
	MasterControl::prepareControls();
	add(std::make_unique<McpIASControl>("McpIASControl"));
}

void McpIASMasterControl::setupControls() {
	MasterControl::setupControls();
	addOnValidate([](BaseControl& control) -> bool {
		return false;
		});
}
