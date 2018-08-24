/**
*
* @file     SprConfig.h
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

#pragma once
#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

/**
*   SprConfig�ࣺ��ȡ�ʹ洢������Ϣ
*/
class SprConfig
{
private:
	static SprConfig *pSprConfig;
	void readParamFromFile();
	map<string,string> m_infoMap;
	SprConfig()
	{
	}

	template<typename T>
	bool isParamInConfigFile(string key,T *pParam)
	{
		map<string,string>::iterator iter;
		iter  = m_infoMap.find(key);
		if(iter==m_infoMap.end())
		{
			return false;
		}
		else
		{
			stringstream tmpSS;
			tmpSS<<iter->second;
			tmpSS>>*pParam;
			return true;
		}
	}

	void setValueToParam();

public:
	int main_loopTime;//�������ѭ������ʱ��
	int main_interval ;//��־��������ڣ�һ������Ϊ5s
	int main_consoleOutput;//��־��Ϣ���������̨��1--->�� 0--->��
	int main_logFileOutput;//��־��Ϣ������ļ���1--->�� 0--->��
	int main_logLevel;//��־��������
	int stat_timeMaxSection;//����90%����ִ��ʱ��ʱ�������С
	int stat_timePrecisionSection;//����90%����ִ��ʱ��ʱ��ʱ����С
	int tps_timeSectionNum;//����tpsʱ ʱ���ַֿ������

	string spr_projectCode;//�ϴ�����ʱʹ�õ���Ŀ���
	string spr_dataProcessURL;//�ϴ�����ʱʹ�õ�url
	string spr_dataServerIP;//������ip
	string spr_dataServerPort;//�������˿�
	string master_ip  ; //�ֲ�ʽ������IP
	int	   master_port   ;//�ֲ�ʽ�������˿�
	bool   spr_isStatDataUpload;//spr�����ϴ�����
	bool   spr_isGapsUpload; //gaps�����ϴ�����

	string localhost_machineNICName;//�����ӷ�������������

	static SprConfig* getInstance()
	{
		if(pSprConfig==NULL)
		{
			pSprConfig = new SprConfig();
			pSprConfig->readParamFromFile();
			pSprConfig->setValueToParam();
		}
		return pSprConfig;
	}

};

