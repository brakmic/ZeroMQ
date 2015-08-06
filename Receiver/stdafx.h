// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "targetver.h"

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <tchar.h>
#include <boost\format.hpp>
#include <boost\spirit\include\qi.hpp>
#include <boost\spirit\include\qi_match.hpp>


// TODO: reference additional headers your program requires here
#include <zmq.hpp>
#include <zhelpers.hpp>
#include <Windows.h>

#define sleep(x) Sleep(x)
#define MESSAGE_INVALID -1
#define TASK_SUCCEEDED 1
#define TASK_FAILED -1
