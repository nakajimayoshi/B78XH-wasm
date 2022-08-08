﻿//    B78XH-wasm
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


#pragma once
#include <MSFS/MSFS_Render.h>
#include <MSFS/Legacy/gauges.h>
#include "fmt/core.h"
#include "MSFS/Render/nanovg.h"
#include "GaugesInvalidateFlags.h"

class BaseGauge {
	public:
		virtual ~BaseGauge() = default;
		virtual bool preInstall() = 0;
		virtual bool postInstall(FsContext context) = 0;
		virtual bool preDraw(sGaugeDrawData* data) = 0;
		virtual bool preDraw(FsContext context, sGaugeDrawData* data) {
			return true;
		};
		virtual bool preKill() = 0;
};

class Test {
public: 
	Test(double arg1, double arg2) : p1(arg1), p2(arg1 + arg2 + 25) {
		this->p2 = arg1 + arg2 + 25;
	}

	private: 
		double p1;
		double p2;

};

class TestX : public Test
{
public:
	TestX(double arg1, double arg2);
private:
	double x;
	double y;
};

