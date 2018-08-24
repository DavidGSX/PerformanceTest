/**
*
* @file     StringTools.h
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

#ifndef __STRINGTOOLS_H__
#define __STRINGTOOLS_H__

#include <string.h>
#include <vector>
#include <sstream>
#include <string>/*string*/
#include <time.h>/*time_t, struct tm, localtime*/
#include <sstream>/*stringstream*/
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <iostream>
#ifndef _WIN32
#include <sys/socket.h>
#include <ifaddrs.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#endif

using namespace std;

class StringTools
{
public:
	static vector<string> splitStringToVector(string src, char splitter)
	{
		vector<string> result;
		stringstream ss(src);
		string item;

		while(getline(ss,item,splitter))
		{
			result.push_back(item);
		}
		return result;
	}

	template<typename T>
	static string param2string(const T &param)
	{
		string result = "";
		stringstream ss;
		ss<<param;
		ss>>result;
		return result;
	}

	static string int2string(int intNum)
	{
		return param2string(intNum);
	}

	static string double2string(double dbNum)
	{
		return param2string(dbNum);
	}

	static string float2string(float floatNum)
	{
		return param2string(floatNum);
	}

	static string chars2string(char* pChars,int len)
	{
		string result = "";
		for(int i=0;i<len;i++)
		{
			result += pChars[i];
		}
		return result;
	}

	static int string2int(string src)
	{
		int result;
		stringstream ss(src);
		ss>>result;
		return result;
	}

	static unsigned int string2uint(string src)
	{
		unsigned int result;
		stringstream ss(src);
		ss>>result;
		return result;
	}
	
	static void string2chars(string src,char *b)
	{
		char *p = b;
		for (int i = 0; i < src.size();i++)
		{
			*p = src[i];
			p++;
		}
	}

	static vector<string> mySplit(const string& str, string sp_string)  // split(), str 是要分割的string
	{ 
		vector<string> vecString; 
		int sp_stringLen = int(sp_string.size()); 
		int lastPosition = 0; 
		int index = -1; 
		while(-1 != (index = int(str.find(sp_string , lastPosition))))
		{ 
			vecString.push_back(str.substr(lastPosition, index - lastPosition)); 
			lastPosition = index +sp_stringLen; 
		} 
		string lastStr = str.substr(lastPosition); 
		if ( !lastStr.empty() ) 
		{ 
			vecString.push_back(lastStr); 
		} 
		return vecString; 
	} 

	static string myReplaceAll(const string& str, string org_str, string rep_str) // 把org_str 替换为rep_str; 
	{ 
		vector<string>  delimVec = mySplit(str, org_str); 
		if (delimVec.size() <= 0) 
		{ 
		//	cout<<"can not find"<<endl; 
			return str; 
		} 
		string target(""); 
		vector<string>::iterator it = delimVec.begin(); 
		for (; it != delimVec.end(); ++it) 
		{ 
			target = target + (*it)+ rep_str; 
		} 
		return target; 
	}
	#ifndef _WIN32
	static string getHostIP(const char* pInterface)
	{
		char szHostIp[32];
		memset(szHostIp,0,sizeof(szHostIp));
		struct ifaddrs * pAddr0, *pAddr1;
		char* pChar = NULL ;
		memset(szHostIp,0,sizeof(szHostIp));
		if(getifaddrs(&pAddr0))
		{
			return "" ;
		}

		for(pAddr1 = pAddr0 ; pAddr1 != NULL; pAddr1 = pAddr1->ifa_next)
		{
			if(0 == strcmp(pInterface,pAddr1->ifa_name))
			{
				if(pAddr1->ifa_addr == NULL)
				{
					continue;
				}
				if(AF_INET == pAddr1->ifa_addr->sa_family)
				{
					struct sockaddr_in * addr4 = (struct sockaddr_in *)pAddr1->ifa_addr;
					pChar = inet_ntoa(addr4->sin_addr);
					if(NULL != pChar)
					{
						if(strncpy(szHostIp,pChar,sizeof(szHostIp)-1))
						{
							break ;
						}
					}
				}
			}
			else
			{
				continue;
			}
		}
		string tempStr = "";
		if(szHostIp[0] != '\0')
		{
			tempStr = StringTools::chars2string(szHostIp,strlen(szHostIp));		
		}
    
		freeifaddrs(pAddr0);
 		
		return tempStr;
	}
	#endif
};

#endif


