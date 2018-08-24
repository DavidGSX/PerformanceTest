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
* Copyright (c)  2016-2017, ��Ѷ�Ƽ����޹�˾���������з���
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
	string msg; //�ַ�����ʽ  �ۺ�����+����������
	StatDataAlltrans  allTrans; //�����ʽ�� �ۺ���������
	list<StatDataTrans*>   transLst;//�����ʽ�� ����������
	
public:

	UploadData();
	~UploadData();
	StatDataAlltrans * getAllTrans() ;
	list<StatDataTrans*>  * getTransLst() ;
	string getMsg();
	void setMsg(string msg) ;
};

#endif