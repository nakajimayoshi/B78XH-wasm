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


#pragma once
#include "CDULine.h"

class CDULeftTitleLine: public CDULine {
	public:
		CDULeftTitleLine(NVGcontext*& context,
			const CDULineNumber lineNumber,
			std::vector<std::vector<std::string>> content
		) : CDULine(context, lineNumber, content) {
			this->lineType = CDULineType::TITLE;
			this->fontSize = 18.0f;
			this->CDULeftTitleLine::calculateHorizontalOffset();
		}

		CDULeftTitleLine(NVGcontext*& context, const CDULineNumber lineNumber, const std::string content) : CDULine(
			context, lineNumber, content) {
			this->lineType = CDULineType::TITLE;
			this->fontSize = 18.0f;
			this->CDULeftTitleLine::calculateHorizontalOffset();
		}

		void calculateHorizontalOffset() override;
};
