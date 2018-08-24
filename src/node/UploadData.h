/**
*
* @file     UploadData.h
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

#ifndef __UPLOADDATA_H__
#define __UPLOADDATA_H__

#include <list>
#include "node/StatDataAlltrans.h"
#include "node/StatDataTrans.h"

class UploadData
{
private:
	string msg; //字符串格式  综合事务+单事务数据
	StatDataAlltrans  allTrans; //对象格式的 综合事务数据
	list<StatDataTrans*>   transLst;//对象格式的 单事务数据
	
public:

	UploadData();
	~UploadData();
	StatDataAlltrans * getAllTrans() ;
	list<StatDataTrans*>  * getTransLst() ;
	string getMsg();
	void setMsg(string msg) ;
};

#endif