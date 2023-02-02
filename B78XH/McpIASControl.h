#pragma once

#include "Control.h"

class McpIASControl : public Control {
public:
	explicit McpIASControl(const string& name)
		: Control(name) {}


protected:
	auto setupControl() -> void override;
	auto prepareControls() -> void override;
	auto setupControls() -> void override;
};