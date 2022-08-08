#include "BaseGauge.h"
#include "CDUMouseClickResolver.h"
#include "CDUMouseCursor.h"
#include "CDUMouseMoveResolver.h"
#include "MFDMenuButton.h"

class ATCSubMenu : public BaseGauge {
private:
	FsContext fsContext = 0;
	NVGcontext* nvgContext = nullptr;
	CDUMouseMoveResolver mouseMoveResolver = CDUMouseMoveResolver();
	CDUMouseClickResolver mouseClickResolver = CDUMouseClickResolver();
	CDUMouseCursor mouseCursor = CDUMouseCursor(nvgContext, mouseMoveResolver);

	MFDSubMenuButton levelRequestButton = MFDSubMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 5, 173, "LEVEL", "REQUEST");
	MFDSubMenuButton whenCanWeExpectButton = MFDSubMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 217, 173, "WHEN CAN WE", "EXPECT");
	MFDSubMenuButton emergencyReportButton = MFDSubMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 429, 173, "EMERGENCY", "REPORT");
	MFDSubMenuButton routeRequestButton = MFDSubMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 5, 229, "ROUTE", "REQUEST");
	MFDSubMenuButton voiceContactRequestButton = MFDSubMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 217, 229, "VOICE CONTACT", "REQUEST");
	MFDSubMenuButton requestedReportsButton = MFDSubMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 429, 229, "REQUSTED", "REPORTS");
	MFDSubMenuButton speedRequestButton = MFDSubMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 5, 285, "SPEED", "REQUEST");
	MFDSubMenuButton freeTextMessageButton = MFDSubMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 217, 285, "FREE TEXT", "MESSAGE");
	MFDSubMenuButton conditionalClearancesButton = MFDSubMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 429, 285, "CONDITIONAL", "CLEARANCES");
	MFDSubMenuButton clearanceRequestButton = MFDSubMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 5, 341, "CLEARANCE", "REQUEST");
	MFDSubMenuButton logonStatusButton = MFDSubMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 217, 341, "LOGON/STATUS", nullptr);
	MFDSubMenuButton positionReportButton = MFDSubMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 429, 341, "POSITION", "REPORT"); MFDSubMenuButton monitoringReportButton = MFDSubMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 429, 397, "MONITORING", "REPORT"); #pragma once


public:
	bool preInstall() override;
	bool postInstall(FsContext context) override;
	bool preDraw(sGaugeDrawData* data) override;
	bool preKill() override;
	CDUMouseMoveResolver& getMouseMoveResolver();
	CDUMouseClickResolver& getMouseClickResolver();
};