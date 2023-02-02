#pragma once

#include "MasterControl.h"

class McpAltitudeMasterControl : public MasterControl {
public:
	explicit McpAltitudeMasterControl(const string& name)
		: MasterControl(name) {}

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;
};