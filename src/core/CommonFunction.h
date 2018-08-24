/**
*
* @file     CommonFunction.h
* @brief
*
* @author honyliu jennachen
* @version 1.0
* @date 2017-11-08
*
*
* Copyright (c)  2016-2017, 腾讯科技有限公司互动娱乐研发部
* All rights reserved.
*
*/

#ifndef __COMMONFUNCTION_H__
#define __COMMONFUNCTION_H__


#ifdef _WIN32
#include "core/WindowsFunction.h"
#include "core/SPR_ERROR.h"
#include "core/SprConfig.h"
#include <windows.h>
#include <time.h>
#include <WInSock.h>

#define snprintf _snprintf
#pragma comment( lib,"winmm.lib" )

#else
#include "LinuxFunction.h"

#endif

#endif


