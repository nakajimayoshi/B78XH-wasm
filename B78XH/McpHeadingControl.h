#pragma once
#include "Control.h"

class McpHeadingControl : public Control {
public:
	explicit McpHeadingControl(const string& name)
		: Control(name) {}

protected:
	auto prepareControls() -> void override;
	auto setupControls() -> void override;
	auto setupControl() -> void override;
};
