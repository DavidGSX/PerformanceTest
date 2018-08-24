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
* Copyright (c)  2016-2017, 腾讯科技有限公司互动娱乐研发部
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
*   SprConfig类：读取和存储配置信息
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
	int main_loopTime;//主程序的循环休眠时间
	int main_interval ;//日志输出的周期，一般设置为5s
	int main_consoleOutput;//日志信息输出到控制台：1--->是 0--->否
	int main_logFileOutput;//日志信息输出到文件：1--->是 0--->否
	int main_logLevel;//日志级别设置
	int stat_timeMaxSection;//计算90%事务执行时间时的区间大小
	int stat_timePrecisionSection;//计算90%事务执行时间时的时间块大小
	int tps_timeSectionNum;//控制tps时 时间轮分块的数量

	string spr_projectCode;//上传数据时使用的项目编号
	string spr_dataProcessURL;//上传数据时使用的url
	string spr_dataServerIP;//服务器ip
	string spr_dataServerPort;//服务器端口
	string master_ip  ; //分布式控制器IP
	int	   master_port   ;//分布式控制器端口
	bool   spr_isStatDataUpload;//spr数据上传开关
	bool   spr_isGapsUpload; //gaps数据上传开关

	string localhost_machineNICName;//被监视服务器的网卡名

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

