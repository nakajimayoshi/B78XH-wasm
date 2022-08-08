#pragma once
#include "BaseGauge.h"
#include "CDUMouseClickResolver.h"
#include "CDUMouseCursor.h"
#include "CDUMouseMoveResolver.h"
#include "MFDMenuButton.h"

enum class MFDCommGaugePages
{
	ATC,
	FLIGHT_INFO,
	COMPANY,
	REVIEW,
	MANAGER,
	NEW_MESSAGE,
	LEVEL_REQUEST,
	WHEN_CAN_WE_EXPECT,
	EMERGENCY_REPORT,
	ROUTE_REQUEST,
	VOICE_CONTACT_REQUEST,
	REQUESTED_REPORTS,
	SPEED_REQUEST,
	FREE_TEXT_MESSAGE,
	CONDITIONAL_CLEARANCES,
	CLEARANCE_REQUEST,
	LOGON_STATUS,
	POSITION_REPORT,
	MONITORING_REPORT
};




class MFDCommGauge: public BaseGauge {
	private:
		MFDCommGaugePages activePage = MFDCommGaugePages::ATC;
		FsContext fsContext = 0;
		NVGcontext* nvgContext = nullptr;
		CDUMouseMoveResolver mouseMoveResolver = CDUMouseMoveResolver();
		CDUMouseClickResolver mouseClickResolver = CDUMouseClickResolver();
		CDUMouseCursor mouseCursor = CDUMouseCursor(nvgContext, mouseMoveResolver);
		
		// Base Menu
		MFDMenuButton atcButton = MFDMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 5, 5, "ATC", nullptr);
		MFDMenuButton flightInfoButton = MFDMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 217, 5, "FLIGHT", "INFORMATION");
		MFDMenuButton companyButton = MFDMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 429, 5, "COMPANY", nullptr);
		MFDMenuButton reviewButton = MFDMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 5, 61, "REVIEW", nullptr);
		MFDMenuButton managerButton = MFDMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 217, 61, "MANAGER", nullptr);
		MFDMenuButton newMessagesButton = MFDMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 429, 61, "NEW MESSAGES", nullptr);
		MFDMenuButton backButton = MFDMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 5, 500, "<- BACK", nullptr);


		// ATC Menu
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
		MFDSubMenuButton positionReportButton = MFDSubMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 429, 341, "POSITION", "REPORT");
		MFDSubMenuButton monitoringReportButton = MFDSubMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 429, 397, "MONITORING", "REPORT");

		// Flight Info Menu
		MFDSubMenuButton departureClearanceButton = MFDSubMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 5, 173, "DEPARTURE", "CLEARANCE REQ");
		MFDSubMenuButton ATISReuqestButton = MFDSubMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 217, 173, "ATIS REQUEST", nullptr);
		MFDSubMenuButton oceanicClearanceRequestButton = MFDSubMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 429, 173, "OCEANIC", "CLEARANCE REQ");
		MFDSubMenuButton pushBackRequestButton = MFDSubMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 5, 229, "PUSHBACK", "REQUEST");
		MFDSubMenuButton TWIPRequestButton = MFDSubMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 217, 229, "TWIP REQUEST", nullptr);
		MFDSubMenuButton expectedTaxiRquestButton = MFDSubMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 5, 285, "EXPECTED TAXI", "REQUEST");


		// Company Menu
		MFDMenuButton weatherRequestButton = MFDMenuButton(nvgContext, mouseMoveResolver, mouseClickResolver, 5, 173, "WEATHER", "REQ");

		auto resetButtons() -> void;
		double inicatedAirSpeed = 0;

	public: 
		bool preInstall() override;
		bool postInstall(FsContext context) override;
		bool preDraw(sGaugeDrawData* data) override;
		bool preKill() override;
		CDUMouseMoveResolver& getMouseMoveResolver();
		CDUMouseClickResolver& getMouseClickResolver();

};

