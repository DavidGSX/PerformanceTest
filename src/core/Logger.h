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
* Copyright (c)  2016-2017, 腾讯科技有限公司互动娱乐研发部
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
 * Description ：日志类
 * Details     ：对程序运行时的日志信息进行输出
 *               1、日志loglevel分为debug/infor/error三个等级，由1到3，初始化的时候设定
 *               2、日志输出函数分为debug/infor/error,根据设定的loglevel，能够输出大于等于loglevel的日志
 * @author     ：moosedong
 * @Aug 17, 2015
 */
class Logger
{
	private:
		bool m_isLogFileOutput;//控制是否输出到文件
		bool m_isConsoleOutput;//控制是否输出到控制台
		
		char *m_pLogfile;//指向输出文件路径
		
	public:
		const static int c_debugLevel = 1;
		const static int c_infoLevel = 2;
		const static int c_errorLevel = 3;
		
		//用户设定的log级别
		//设为1时输出debug info error 3种信息  
		//设为2时输出      info error 2种信息
		//设为3时输出           error 1种信息
		int m_logLevel;

		ofstream m_osfLogFile;//文件流

		void initLogger(int consoleOutput, int logFileOutput,int logLevel);
		void initLogFile();
		bool openLogFile();

		string getTimeInfo();
		void ssToString(stringstream &ssSrc, string &strDest);

		bool isLogFileOutput();
		bool isConsleOutPut();
		
		/**
		* 
		* Description ：输出debug信息  重载1：传入任意基础类型数据（int  double char string long等等）
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
		* Description ：输出debug信息  重载2：以stringstream的形式传入参数，不用管参数类型
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
		* Description ：输出info信息
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
		* Description ：输出info信息
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
		* Description ：输出error信息
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
		* Description ：输出error信息
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
		* Description ：输出error信息
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
		* Description ：执行具体的输出任务
		*/
		template<typename T>
		void doLog(const T &param,string logType = "")
		{
			//锁住日志输出模块（加锁）
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

		//锁住日志输出模块（解锁）
		UnLock(g_LoggerLock);
		}


		/**
		* 
		* Description ：执行具体的输出任务
		*/
		void doLog(stringstream & ss,string logType = "");
		
		~Logger();
};

#endif
