#pragma once

#include "Control.h"

class McpAltitudeControl : public Control {
public:
	explicit McpAltitudeControl(const string& name)
		: Control(name) {}


protected:
	auto setupControl() -> void override;
	auto prepareControls() -> void override;
	auto setupControls() -> void override;
};