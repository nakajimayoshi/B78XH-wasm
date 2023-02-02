#pragma once

#include "MasterControl.h"

class McpIASMasterControl : public MasterControl {
public:
	explicit McpIASMasterControl(const string& name)
		: MasterControl(name) {}

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;
};