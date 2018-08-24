/**
*
* @file     Logger.h
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

#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "core/CommonFunction.h"
#include "core/SPR_ERROR.h"

using namespace std;





#ifdef _WIN32
extern CRITICAL_SECTION g_LoggerLock;
void Lock(CRITICAL_SECTION &lock);
void UnLock(CRITICAL_SECTION &lock);
#else
extern pthread_mutex_t g_LoggerLock;
void Lock(pthread_mutex_t &lock);
void UnLock(pthread_mutex_t &lock);
#endif



/**
 * 
 * Description ����־��
 * Details     ���Գ�������ʱ����־��Ϣ�������
 *               1����־loglevel��Ϊdebug/infor/error�����ȼ�����1��3����ʼ����ʱ���趨
 *               2����־���������Ϊdebug/infor/error,�����趨��loglevel���ܹ�������ڵ���loglevel����־
 * @author     ��moosedong
 * @Aug 17, 2015
 */
class Logger
{
	private:
		bool m_isLogFileOutput;//�����Ƿ�������ļ�
		bool m_isConsoleOutput;//�����Ƿ����������̨
		
		char *m_pLogfile;//ָ������ļ�·��
		
	public:
		const static int c_debugLevel = 1;
		const static int c_infoLevel = 2;
		const static int c_errorLevel = 3;
		
		//�û��趨��log����
		//��Ϊ1ʱ���debug info error 3����Ϣ  
		//��Ϊ2ʱ���      info error 2����Ϣ
		//��Ϊ3ʱ���           error 1����Ϣ
		int m_logLevel;

		ofstream m_osfLogFile;//�ļ���

		void initLogger(int consoleOutput, int logFileOutput,int logLevel);
		void initLogFile();
		bool openLogFile();

		string getTimeInfo();
		void ssToString(stringstream &ssSrc, string &strDest);

		bool isLogFileOutput();
		bool isConsleOutPut();
		
		/**
		* 
		* Description �����debug��Ϣ  ����1��������������������ݣ�int  double char string long�ȵȣ�
		*/
		template<typename T>
		void debug(const T &param)
		{
			if(this->m_logLevel <1 ||this->m_logLevel >3)
				return;
			if(this->m_logLevel <= this->c_debugLevel){
				this->doLog(param,"debug");
			}
		}

		/**
		* 
		* Description �����debug��Ϣ  ����2����stringstream����ʽ������������ùܲ�������
		*/
		void debug(stringstream &ss)
		{
			if(this->m_logLevel <1 ||this->m_logLevel >3)
				return;
			if(this->m_logLevel <= this->c_debugLevel){
				this->doLog(ss,"debug");
			}
		}

		/**
		* 
		* Description �����info��Ϣ
		*/
		template<typename T>
		void info(const T &param)
		{
			if(this->m_logLevel <1 ||this->m_logLevel >3)
				return;
			if(this->m_logLevel  <= this->c_infoLevel){
				this->doLog(param,"info ");
			}
			
		}

		/**
		* 
		* Description �����info��Ϣ
		*/
		void info(stringstream &ss)
		{
			if(this->m_logLevel <1 ||this->m_logLevel >3)
				return;
			if(this->m_logLevel  <= this->c_infoLevel){
				this->doLog(ss,"info ");
			}
		}
		

		/**
		* 
		* Description �����error��Ϣ
		*/
		template<typename T>
		void error(const T &param)
		{
			if(this->m_logLevel <1 ||this->m_logLevel >3)
				return;
			if(this->m_logLevel <= this->c_errorLevel){
				this->doLog(param,"error");
			}
		}
		/**
		* 
		* Description �����error��Ϣ
		*/
		void error(string &ss,string file,string function,int line)
		{
			ss.append("|");
			ss.append(file);
			ss.append(" ");
			ss.append(function);
			ss.append(" ");
			ss.append(StringTools::int2string(line));
			error(ss);
		}
		/**
		* 
		* Description �����error��Ϣ
		*/
		void error(stringstream &ss)
		{
			if(this->m_logLevel <1 ||this->m_logLevel >3)
				return;
			if(this->m_logLevel <= this->c_errorLevel){
				this->doLog(ss,"error");
			}
		}

		/**
		* 
		* Description ��ִ�о�����������
		*/
		template<typename T>
		void doLog(const T &param,string logType = "")
		{
			//��ס��־���ģ�飨������
			Lock(g_LoggerLock);
			string strTime = this->getTimeInfo();
			if(m_isConsoleOutput == true){
				cout <<strTime<<" "<<logType<<" - "<<param<<endl;
			}

			if(m_isLogFileOutput){
				if(this->m_osfLogFile.is_open()){
					m_osfLogFile<<strTime<<" "<<logType<<" - "<<param<<endl;
					m_osfLogFile.flush();
				}
				else{
					this->openLogFile();
					if(this->m_osfLogFile.is_open()){
						m_osfLogFile<<strTime<<" "<<logType<<" - "<<param<<endl;
						m_osfLogFile.flush();
					}
					else{
						cout<<"Log File Open FAILED!"<<endl;
						cout<<"error number = "<<SPR_ERR_LOGFILE_OPEN_FAIL<<endl;
					}	
				}
			}

		//��ס��־���ģ�飨������
		UnLock(g_LoggerLock);
		}


		/**
		* 
		* Description ��ִ�о�����������
		*/
		void doLog(stringstream & ss,string logType = "");
		
		~Logger();
};

#endif
