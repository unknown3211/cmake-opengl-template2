#include "spdlog/spdlog.h"
#include "logs.h"

void Log(logtype type, const char* msg)
{
    switch (type) {
    case info:
        spdlog::info(msg);
        break;
    case error:
        spdlog::error(msg);
        break;
    case warn:
        spdlog::warn(msg);
        break;
    case critical:
        spdlog::critical(msg);
        break;
    case debug:
        spdlog::debug(msg);
        break;
    default:
        spdlog::info("Unknown log type: {}", msg);
        break;
    }
}