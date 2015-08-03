// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once
#define _ITERATOR_DEBUG_LEVEL 1
#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS

#include "targetver.h"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <tchar.h>
#include <boost\format.hpp>


// TODO: reference additional headers your program requires here  
#include <zhelpers.hpp>
#include <Windows.h>

#define sleep(x) Sleep(x)
#define MESSAGE_INVALID -1
#define TASK_SUCCEEDED 1
#define TASK_FAILED -1
