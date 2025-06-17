#include "Context.hpp"

namespace Guard {
	bool checkConfigurationGuard(Context& ctx) { return ctx.missingConfiguration == false; }
	bool firmwareUpdateAvailableGuard(Context& ctx) { return ctx.firmwareUpdateAvailable == true; }
	bool missingConfigurationGuard(Context& ctx) { return ctx.missingConfiguration == true; }
};
