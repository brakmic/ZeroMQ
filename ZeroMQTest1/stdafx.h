// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "targetver.h"

#include <stdio.h>
#include <string.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here
//#include <zmq.h>    
#include <zmq.h>
#include <zhelpers.h>
#include <Windows.h>

#define sleep(x) Sleep(x)
#define MESSAGE_INVALID -1