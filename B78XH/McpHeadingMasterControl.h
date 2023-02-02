#pragma once
#include "MasterControl.h"

class McpHeadingMasterControl : public MasterControl {
public:
	explicit McpHeadingMasterControl(const string& name)
		: MasterControl(name) {}

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;
};
