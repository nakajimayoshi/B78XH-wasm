#include "MFDCommGauge.h"
#include "MFDMenuButton.h"
#include  "fmt/core.h"
#include "SimConnectData.h"

auto MFDCommGauge::resetButtons() -> void {
	this->atcButton.setBackgroundColor(Tools::Colors::cduButtonGray);
	this->flightInfoButton.setBackgroundColor(Tools::Colors::cduButtonGray);
	this->managerButton.setBackgroundColor(Tools::Colors::cduButtonGray);
	this->reviewButton.setBackgroundColor(Tools::Colors::cduButtonGray);
	this->companyButton.setBackgroundColor(Tools::Colors::cduButtonGray);
	this->newMessagesButton.setBackgroundColor(Tools::Colors::cduButtonGray);
}

auto MFDCommGauge::preInstall() -> bool {
	return true;
}

auto MFDCommGauge::postInstall(FsContext context) -> bool {
	this->fsContext = context;
	NVGparams params;
	params.userPtr = context;
	params.edgeAntiAlias = true;
	this->nvgContext = nvgCreateInternal(&params);

	nvgCreateFont(this->nvgContext, "heavy-fmc", "./data/Roboto-Regular.ttf");

	return true;
}

auto MFDCommGauge::preDraw(sGaugeDrawData* data) -> bool {
	float devicePixelRatio = static_cast<float>(data->fbWidth) / static_cast<float>(data->winWidth);
	float windowWidth = static_cast<float>(data->winWidth);
	float windowHeight = static_cast<float>(data->winHeight);

	atcButton.event = [this]() -> void
	{
		this->activePage = MFDCommGaugePages::ATC;
		this->resetButtons();
		fmt::print(stderr, "TEST ATC");
		atcButton.setBackgroundColor(Tools::Colors::greenButton);
	};

	flightInfoButton.event = [this]() -> void
	{
		this->activePage = MFDCommGaugePages::FLIGHT_INFO;
		this->resetButtons();
		fmt::print(stderr, "TEST FLIGHT INFO");
		flightInfoButton.setBackgroundColor(Tools::Colors::greenButton);
	};

	companyButton.event = [this]() -> void
	{
		this->activePage = MFDCommGaugePages::COMPANY;
		this->resetButtons();
		fmt::print(stderr, "TEST COMPANY");
		companyButton.setBackgroundColor(Tools::Colors::greenButton);
	};

	reviewButton.event = [this]() -> void
	{
		this->activePage = MFDCommGaugePages::REVIEW;
		this->resetButtons();
		fmt::print(stderr, "TEST REVIEW");
		reviewButton.setBackgroundColor(Tools::Colors::greenButton);
	};

	managerButton.event = [this]() -> void
	{
		this->activePage = MFDCommGaugePages::MANAGER;
		this->resetButtons();
		fmt::print(stderr, "TEST MANAGER");
		managerButton.setBackgroundColor(Tools::Colors::greenButton);
	};

	newMessagesButton.event = [this]() -> void
	{
		this->activePage = MFDCommGaugePages::NEW_MESSAGE;
		this->resetButtons();
		fmt::print(stderr, "TEST NEW MESSAGES");
		newMessagesButton.setBackgroundColor(Tools::Colors::greenButton);
	};

	levelRequestButton.event = [this]() -> void
	{
		this->activePage = MFDCommGaugePages::LEVEL_REQUEST;
		this->resetButtons();
		fmt::print(stderr, "TEST LEVEL REQUEST");
		atcButton.setBackgroundColor(Tools::Colors::greenButton);
	};

	whenCanWeExpectButton.event = [this]() -> void
	{
		this->activePage = MFDCommGaugePages::WHEN_CAN_WE_EXPECT;
		this->resetButtons();
		fmt::print(stderr, "TEST WHEN CAN WE EXPECT");
		flightInfoButton.setBackgroundColor(Tools::Colors::greenButton);
	};

	emergencyReportButton.event = [this]() -> void
	{
		this->activePage = MFDCommGaugePages::EMERGENCY_REPORT;
		this->resetButtons();
		fmt::print(stderr, "TEST EMERGENCY REPORT");
		companyButton.setBackgroundColor(Tools::Colors::greenButton);
	};

	routeRequestButton.event = [this]() -> void
	{
		this->activePage = MFDCommGaugePages::ROUTE_REQUEST;
		this->resetButtons();
		fmt::print(stderr, "TEST ROUTE REQUEST");
		reviewButton.setBackgroundColor(Tools::Colors::greenButton);
	};

	voiceContactRequestButton.event = [this]() -> void
	{
		this->activePage = MFDCommGaugePages::VOICE_CONTACT_REQUEST;
		this->resetButtons();
		fmt::print(stderr, "TEST VOICE CONTACT REQUEST");
		managerButton.setBackgroundColor(Tools::Colors::greenButton);
	};

	requestedReportsButton.event = [this]() -> void
	{
		this->activePage = MFDCommGaugePages::REQUESTED_REPORTS;
		this->resetButtons();
		fmt::print(stderr, "TEST REQUESTED REPORTS");
		newMessagesButton.setBackgroundColor(Tools::Colors::greenButton);
	};

	speedRequestButton.event = [this]() -> void
	{
		this->activePage = MFDCommGaugePages::SPEED_REQUEST;
		this->resetButtons();
		fmt::print(stderr, "TEST SPEED REQUEST");
		atcButton.setBackgroundColor(Tools::Colors::greenButton);
	};

	freeTextMessageButton.event = [this]() -> void
	{
		this->activePage = MFDCommGaugePages::FREE_TEXT_MESSAGE;
		this->resetButtons();
		fmt::print(stderr, "TEST FREE TEXT MESSAGE");
		flightInfoButton.setBackgroundColor(Tools::Colors::greenButton);
	};

	conditionalClearancesButton.event = [this]() -> void
	{
		this->activePage = MFDCommGaugePages::CONDITIONAL_CLEARANCES;
		this->resetButtons();
		fmt::print(stderr, "TEST CONDITIONAL CLEARANCES");
		companyButton.setBackgroundColor(Tools::Colors::greenButton);
	};

	clearanceRequestButton.event = [this]() -> void
	{
		this->activePage = MFDCommGaugePages::CLEARANCE_REQUEST;
		this->resetButtons();
		fmt::print(stderr, "TEST CLEARANCE REQUEST");
		reviewButton.setBackgroundColor(Tools::Colors::greenButton);
	};

	logonStatusButton.event = [this]() -> void
	{
		this->activePage = MFDCommGaugePages::LOGON_STATUS;
		this->resetButtons();
		fmt::print(stderr, "TEST LOGON STATUS");
		managerButton.setBackgroundColor(Tools::Colors::greenButton);
	};

	// positionReportButton.event = [this]() -> void
	// {
	// 	this->activePage = MFDCommGaugePages::POSITION_REPORT;
	// 	this->resetButtons();
	// 	fmt::print(stderr, "TEST POSITION REPORT");
	// 	newMessagesButton.setBackgroundColor(Tools::Colors::greenButton);
	// };
	//
	// monitoringReportButton.event = [this]() -> void
	// {
	// 	this->activePage = MFDCommGaugePages::MONITORING_REPORT;
	// 	this->resetButtons();
	// 	fmt::print(stderr, "TEST NEW MONITORING REPORT");
	// 	newMessagesButton.setBackgroundColor(Tools::Colors::greenButton);
	// };
	//
	// backButton.event = [this]() -> void
	// {
	// 	this->activePage = MFDCommGaugePages::ATC;
	// 	this->resetButtons();
	// 	fmt::print(stderr, "TEST BACK");
	// 	newMessagesButton.setBackgroundColor(Tools::Colors::greenButton);
	// };



	double speed = SimConnectData::Aircraft::state.indicatedAirspeed;

	nvgBeginFrame(this->nvgContext, windowWidth, windowHeight, devicePixelRatio);
	{
		nvgFillColor(this->nvgContext, nvgRGB(0, 0, 0));
		nvgBeginPath(this->nvgContext); {
			nvgRect(this->nvgContext, 0, 0, windowWidth, windowHeight);
		}
		nvgFill(this->nvgContext);
		nvgFontFace(this->nvgContext, "heavy-fmc");
		nvgFontSize(this->nvgContext, 25.0f);
		atcButton.draw();
		flightInfoButton.draw();
		companyButton.draw();
		reviewButton.draw();
		managerButton.draw();
		newMessagesButton.draw();
		backButton.draw();
		switch (this->activePage) {
		case MFDCommGaugePages::ATC:
		{
			nvgFillColor(this->nvgContext, (Tools::Colors::white));
			nvgText(this->nvgContext, windowWidth / 2, 140, "ATC", nullptr);
		
			levelRequestButton.draw();
			whenCanWeExpectButton.draw();
			emergencyReportButton.draw();
			routeRequestButton.draw();
			voiceContactRequestButton.draw();
			requestedReportsButton.draw();
			speedRequestButton.draw();
			freeTextMessageButton.draw();
			conditionalClearancesButton.draw();
			clearanceRequestButton.draw();
			logonStatusButton.draw();
			positionReportButton.draw();
			monitoringReportButton.draw();
		} break;
		case MFDCommGaugePages::FLIGHT_INFO:
		{
			nvgFillColor(this->nvgContext, (Tools::Colors::white));
			nvgText(this->nvgContext, windowWidth / 2, 140, "FLIGHT INFORMATION", nullptr);
			departureClearanceButton.draw();
			ATISReuqestButton.draw();
			oceanicClearanceRequestButton.draw();
			pushBackRequestButton.draw();
			TWIPRequestButton.draw();
			expectedTaxiRquestButton.draw();
			
		} break;
		case MFDCommGaugePages::COMPANY: {
			nvgText(this->nvgContext, 500, 400, fmt::format("IAS: {}", speed).c_str(), nullptr);
			nvgText(this->nvgContext, 500, 500, "COMPANY", nullptr);
		} break;
		case MFDCommGaugePages::REVIEW: {
			nvgText(this->nvgContext, 500, 500, "REVIEW", nullptr);
		} break;
		case MFDCommGaugePages::MANAGER: {
			nvgText(this->nvgContext, 500, 500, "MANAGER", nullptr);
		} break;
		case MFDCommGaugePages::NEW_MESSAGE: {
			nvgText(this->nvgContext, 500, 500, "NEW MESSAGE", nullptr);
			} break;
		default: ;
		}
			nvgBeginPath(this->nvgContext); {
				nvgRect(this->nvgContext, 0, 0, windowWidth, windowHeight);
				nvgStrokeColor(this->nvgContext, nvgRGB(255, 255, 255));
				nvgStrokeWidth(this->nvgContext, 3.0f);
				nvgMoveTo(this->nvgContext, windowWidth, 0);
				nvgLineTo(this->nvgContext, windowWidth, windowHeight);
			}

			nvgClosePath(this->nvgContext);
			nvgStroke(this->nvgContext);
			this->mouseCursor.draw();
		}

		nvgEndFrame(this->nvgContext);
	return true;
}



auto MFDCommGauge::preKill() -> bool {
	return true;
}

CDUMouseMoveResolver& MFDCommGauge::getMouseMoveResolver()
{
	return this->mouseMoveResolver;
}

CDUMouseClickResolver& MFDCommGauge::getMouseClickResolver()
{
	return this->mouseClickResolver;
}
