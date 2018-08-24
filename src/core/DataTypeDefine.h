/**
*
* @file     DataTypeDefine.h
* @brief
*
* @author honyliu jennachen
* @version 1.0
* @date 2017-11-08
*
*
* Copyright (c)  2016-2017, ��Ѷ�Ƽ����޹�˾���������з���
* All rights reserved.
*
*/

#ifndef __DATATYPEDEFINE_H__
#define __DATATYPEDEFINE_H__


//�����������Ͷ���
typedef signed char     Int8;
typedef short           Int16;
typedef int             Int32;
typedef long            LInt;

typedef unsigned char   UInt8;
typedef unsigned short  UInt16;
typedef unsigned int    UInt32;
typedef unsigned long   ULInt;

#ifdef _WIN32

typedef __int64              Int64;
typedef unsigned __int64     UInt64;

#else
typedef long long            Int64;
typedef unsigned long long   UInt64;

#endif



#endif


