#include "Client.h"

CClient::CClient(void)
{
	
}


CClient::~CClient(void)
{
	
}


string CClient::DomainToIP(const char* pDomain)
{
#if defined(_WIN32) || defined(WIN32)
	if(!isalpha(pDomain[0]))
	{
		return pDomain;
	}
	struct hostent* h = gethostbyname(pDomain);
	if(h != NULL) 
	{
		unsigned char* p = (unsigned char *)(h->h_addr_list)[0];
		if(p != NULL)
		{
			char ip[16] = {0};
			sprintf(ip, "%u.%u.%u.%u", p[0], p[1], p[2], p[3]);
			return ip;
		}
	}
#endif
	return "";
}


bool CClient::Start(const char* ip, unsigned short port)
{

	if(!m_Socket.Create(/*AF_INET,SOCK_STREAM,0*/))
		return false;
#if defined(_WIN32) || defined(WIN32)
	if(!m_Socket.Connect(DomainToIP(ip).c_str(),port))
#else
	if(!m_Socket.Connect(ip,port))
#endif
		{
			cout<<"CClient::Start : fail! port = " <<port<<endl;
			return false;
		}
		

	//	CCTime::gettimeofdayCocos2d(&m_ConnectTime, NULL);
	//m_nStatus = EConnecting;
	return true;
}

void CClient::Close()
{
	m_Socket.Close();
}

/*
	return:	-1	send error
			>=0 send bytes size
*/
int CClient::Send(char* pBuffer, int nLenght)
{
	int send_pos = 0;
	int result = 0;
	int try_times = 0;
	
	do{
		try_times++;

		if( try_times > 5){
			break;
		}

		result = m_Socket.Write(pBuffer + send_pos, nLenght - send_pos);

		if(result == -1){
			//cout<<"CClient::Send : fial...,result = "<< result << endl;
			usleep(1*1000);
			continue;
		}

		if(result == 0){
			return result;
		}

		if(result > 0){
			send_pos += result;
		}
		
	}while(send_pos < nLenght);

	return result;
}

/*
	return:	-2	no data to read
			-1  read error 
			0	socket has been closed
			>0 	read bytes size  
*/
int CClient::Read(char* pBuffer, int nLenght)
{
	int buf_len = m_Socket.Read(pBuffer,nLenght);
	if(buf_len < 0)
	{
		//no block mode: errno is EAGAIN means no data to read in recv buf 
		if(errno == EAGAIN)
		{
			//do something
			return -2;
		}
		else
			return buf_len;
	}

	if(buf_len == 0){
		//socket has been closed
		return buf_len;
	}

	return buf_len;

}

CClient* CClient::getCClient()
{
	CClient *pClient = new CClient;
	return pClient;
}

