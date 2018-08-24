/**
*
* @file     TdrData.h
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
#ifndef __TDRDATA_H__
#define __TDRDATA_H__

#include <string>
#include "core/CommonFunction.h"
#include "GAPSLOGSVR/logsvrprotocol.h"
#include "GAPSLOGSVR/TdrTypeUtil.h"
#include "tdrnetpkgio.h"
#include "core/Sampler.h"

using std::string;
using tsf4g_tdr::TdrTypeUtil;
using namespace GAPSLOGSVR;

#define BUFFERSIZE 64

//����ip��port
#define DATASERVER "10.12.236.13"
#define PORT 8505

class platAgentConf
{
public:
	string m_idcFlag;
    string m_projectId;
	string m_userId;
	string m_testId;
	string m_agentId;
	string m_groupId;
	string m_ctrlCenterId;
	string m_idcSvr;
	string m_intranetSvr;
	string m_port;
	//string m_encryptFlag;
	string m_runningMode;

	platAgentConf() {}
	~platAgentConf() {}
};

class platAgentData
{
public:
	int m_idcFlag;
    string m_projectId;
	int m_userId;
	int m_testId;
	int m_agentId;
	int m_groupId;
	int m_ctrlCenterId;
	string m_reqSvr;   //wetest server
	string m_localSvr; //local server
	int m_port;
	//int m_encryptFlag;
	int m_runningMode;

	platAgentData() {}
	~platAgentData() {}
};

class TdrData
{
public:
	~TdrData();

	static TdrData* getInstance();
	void readAgentConf();
	void decrypt();//id��userid, testid����

	platAgentConf m_plagentconf;
	platAgentData m_plagentdata;


	void sendGapsReq(); //����Gaps����
	//��msg�е�����д�뵽�����m_tcpSendBuf
	bool sendPackPkg(string msg);
	bool sendPkg();
	bool sendPkg(DataProPkg* m_pstPkg);
	
	bool recvPackPkg();
	bool recvPkg(char *Pkg,int nLen,int nTimeout=500);

	void recvMust(char * buff,int len,string  packageInfo);
	void stopNetwork();
	void closeSocket();
	void startNetWork();

	int  getStartTime();
	void setStartTime(int time);

	int  getLastTime();
	void setLastTime(int time);

	DataProPkg* getpstPkg();

	
	void initPkgHead(DataProPkg* pstPkg, int cmdId);
	void initPkgHead(int cmdId);

	void initStartPkg();
	void initStaticPkg(DataProPkg* m_pstPkg, int robotTotalNum,int robotOnlineNum,int robotOfflineNum,int recvPkgTotalNum,int sndPkgTotalNum);
	void initTransPkg(Sampler& sampler,int transIndex);
	void initEndReqPkg();
	//void initEndReqPkg(DataProPkg* pstPkg);

	void initStartResPkg(); //��Ӧ������

	void doResponse();//����ذ�
	
	int netPackPkg(char buffer[], size_t &usedPackBufSize);
	int netUnpackPkg(char buffer[], size_t usedPackBufSize);
	int netPackUnpackPkg();
	void sendPackedPkg(const char* buffer, size_t size);
	void logBeforeSend();
	void processPackError(TdrError::ErrorType errorCode);
	void logAfterUnpack();
	void processUnpackError(const char* buffer, size_t size, TdrError::ErrorType errorCode);

private:
	TdrData();
	static TdrData* instance;
	static const char* s_FileName;
	static LPTDRMETALIB pstLib;
	static LPTDRMETA pstMeta;

	DataProPkg* m_pstPkg; //���濪ʼ���������Ժ��������ݰ���Ϣ��

	char *m_tcpSendBuf;
	char *m_tcpRecvBuf;
	CommonSocket *m_pCommonSocket;

	int testStartTime;
	int lastTime;

//---------------���������࣬���Գ��������ʱ���Զ������õ���----------- 
public:
	class DTdrData
	{
	public:
		~DTdrData();
	};
	static DTdrData dTdrData; // ����һ����̬��Ա���ڳ������ʱ��ϵͳ�����������������
};

#endif
