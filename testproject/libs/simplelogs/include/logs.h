#pragma once

enum logtype {
	info,
	error,
	warn,
	critical,
	debug
};

void Log(logtype type, const char* msg);