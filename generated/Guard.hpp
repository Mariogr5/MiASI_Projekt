#include "Context.hpp"

namespace Guard {
	bool checkConfigurationGuard(Context& ctx) { return ctx.missingConfiguration == false; }
	bool missingConfigurationGuard(Context& ctx) { return ctx.missingConfiguration == true; }
	bool firmwareUpdateAvailableGuard(Context& ctx) { return ctx.firmwareUpdateAvailable == true; }
};

