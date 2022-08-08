#pragma once
#include "CDUMouseClickResolver.h"
#include "CDUMouseMoveResolver.h"
#include "Drawable.h"
#include "MSFS/Render/nanovg.h"
#include "Tools.h"


class MFDCommBasePage : public Drawable {
public:
	MFDCommBasePage(NVGcontext*& context,
		CDUMouseMoveResolver& mouseMoveResolver,
		CDUMouseClickResolver& mouseClickResolver,
		const double x,
		const double y,
		const double width,
		const double height,
		char* const title = nullptr,
		char* const title2 = nullptr) : context(context),
		mouseMoveResolver(mouseMoveResolver),
		mouseClickResolver(mouseClickResolver),
		x(x),
		y(y),
		width(width),
		height(height),
		title(title),
		title2(title2) {
	}

	std::function<void()> event;
	void setBackgroundColor(NVGcolor color);
	void draw() override;
protected:
	NVGcontext*& context;
	NVGcolor backgroundColor = Tools::Colors::cduButtonGray;
	CDUMouseMoveResolver& mouseMoveResolver;
	CDUMouseClickResolver& mouseClickResolver;
	double x;
	double y;
	double width;
	double height;
	double borderWidth = 5;
	char* title;
	char* title2;
	float bounds[4] = { 0, 0, 0, 0 };
	bool isSelected = false;

	void drawTitle();
	void drawButtonBorders();
	void drawBackBorders(NVGcolor color = Tools::Colors::black);
	void drawBackground() const;
	bool isInFocus();
	void shouldTriggerEvent();
	virtual void calculateBounds();
};