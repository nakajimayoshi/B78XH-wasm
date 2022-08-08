#include "BaseGauge.h"
#include "MSFS/Render/nanovg.h"

class MFDSysPage {
private:
		double privateProperty1 = 0;

	public: 
		double publicProperty1 = 0;
		static auto foo(double factor) -> bool;
		static auto foo(int factor) -> bool;
		static auto foo(float factor) -> bool;
		auto getReadOnly() -> double {
			return this->readOnly;
		};

		auto setSetOnly(double value) -> void {
			this->setOnly = value;
		}

		auto setTestValue(double value) -> void {
			if (value < -10) {
				this->testValue = -10;
				return;
			}
			if (value > 10) {
				this->testValue = 10;
				return;
			}

			this->testValue = value;
		};

	protected:
		double protectedProperty1 = 0;
		double readOnly = 0;
		double setOnly = 0;
		double testValue = 0;

};


