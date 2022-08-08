#include "MFDSysPage.h"

auto MFDSysPage::foo(double factor) -> bool {
	
	if (factor < 1) {
		return true;
	}
	return false ;
}

auto MFDSysPage::foo(int factor) -> bool {

	if (factor < 1) {
		return true;
	}
	return false;
}

auto MFDSysPage::foo(float factor) -> bool {

	if (factor < 1) {
		return true;
	}
	return false;
}




