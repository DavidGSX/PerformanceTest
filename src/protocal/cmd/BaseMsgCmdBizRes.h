/**
*
* @file     BaseMsgCmdBizRes.h
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

#ifndef __BASEMSGCMDBIZRES_H__
#define __BASEMSGCMDBIZRES_H__

#include <string>
#include "protocal/cmd/BaseMsgCmdBiz.h"
//#include "protocal/SprProtocal.h"
using namespace std;



class BaseMsgCmdBizRes : public BaseMsgCmdBiz
{
protected:
	string infor;
	string detail;
public:
	BaseMsgCmdBizRes(){}
	virtual ~BaseMsgCmdBizRes(void){}

	static string infor_error;
	static string infor_ok;

	bool checkRetOk();
 
	string getInfor() ;

	void setInfor(string infor); 

	string getDetail(); 
	
	void setDetail(string detail); 

	void generateOkMsg(string detail);
	
    void generateErrorMsg(string detail);
	
	virtual int parseCmdid()
	{
		return 0;
	}

	virtual void decode(string &jsonStr);
	string encode();
};

#endif