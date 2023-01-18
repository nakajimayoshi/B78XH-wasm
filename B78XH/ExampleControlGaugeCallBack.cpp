//    B78XH-wasm
//    Copyright (C) 2022  Heavy Division
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <https://www.gnu.org/licenses/>.


//#include <MSFS\MSFS.h>
#include <MSFS/MSFS_Render.h>
#include <MSFS/Legacy/gauges.h>

#include "Displays.h"

#ifdef _MSC_VER
#define snprintf _snprintf_s
#elif !defined(__MINGW32__)
#include <iconv.h>
#endif
// ------------------------
// Callbacks
extern "C" {
	__attribute__((visibility("default"))) bool example_control_gauge_callback(FsContext ctx, int service_id, void* pData) {
		switch (service_id) {
		case PANEL_SERVICE_PRE_INSTALL: {
			//Console::log("PRE_INSTALL");
			Displays::mfdControl->preInstall(static_cast<BaseControl::GaugeInstallData*>(pData));
			return true;
		}
									  break;
		case PANEL_SERVICE_POST_INSTALL: {
			//Console::log("POST_INSTALL");

			NVGparams params;
			params.userPtr = ctx;
			params.edgeAntiAlias = true;
			Displays::mfdControl->postInstall(nvgCreateInternal(&params));

			return true;
		}
									   break;
		case PANEL_SERVICE_PRE_UPDATE: {
			//Console::log("PRE_UPDATE");
			Displays::mfdControl->preUpdate();
			return true;
		}
									 break;
		case PANEL_SERVICE_POST_UPDATE: {
			Displays::mfdControl->postUpdate();
			return true;
		}
									  break;
		case PANEL_SERVICE_PRE_DRAW: {
			//Console::log("RENDER");
			Displays::mfdControl->preDraw(static_cast<BaseControl::GaugeDrawData*>(pData));
			return true;
		}
								   break;
		case PANEL_SERVICE_PRE_KILL: {
			Displays::mfdControl->preKill();
			return true;
		}
		case PANEL_SERVICE_POST_KILL: {
			Displays::mfdControl->postKill();
		}
									break;
		}
		return false;
	}
}
