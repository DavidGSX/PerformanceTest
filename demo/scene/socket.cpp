/******************************************************************************
文件名: Socket.h
功能描述: 套接字功能封装类的实现。
******************************************************************************/
#include "socket.h"


/******************************************************************************
函数名称: CSocket
功能描述: 缺省构造函数
输入:
返回值:
******************************************************************************/
CSocket::CSocket()
{
	m_Socket = 0;
}

/******************************************************************************
函数名称: ~CSocket
功能描述: 析构函数
输入:
返回值:
******************************************************************************/
CSocket::~CSocket()
{
	if(m_Socket)
	{
		Close();
	}
}

/******************************************************************************
函数名称: CSocket
功能描述: 缺省构造函数
输入:
返回值:
******************************************************************************/
bool CSocket::Create()
{
	m_Socket = socket(AF_INET, SOCK_STREAM, 0);
	if(m_Socket == 0)
	{
		return false;
	}
	
	//设置非阻塞模式
#if (WIN32)
	unsigned long ul = 1;
	int nRet = ioctlsocket(m_Socket, FIONBIO, (unsigned long*)&ul);
	if (nRet == SOCKET_ERROR)
	{
		Close();
		//LOG_ERROR("设置非阻塞模式失败");
		return false;
	}
#else
    int nFlags = fcntl(m_Socket, F_GETFL, 0);
    int nRet = fcntl(m_Socket, F_SETFL, nFlags | O_NONBLOCK);
	if (nRet == SOCKET_ERROR)
	{
		Close();
		//LOG_ERROR("设置非阻塞模式失败");
		//CCLOG("设置非阻塞模式失败:1");
		return false;
	}
#endif
	//设置套接字无延时
	int nNoDelay = 1;
	if(setsockopt (m_Socket , IPPROTO_HOPOPTS , TCP_NODELAY , (char *)&nNoDelay , sizeof(nNoDelay)) == SOCKET_ERROR)
	{
		Close();
		//LOG_ERROR("设置套接字无延时失败");
		return false;
	}
	
	return true;
}

/******************************************************************************
函数名称: Connect
功能描述: 异步方式连接远程主机
输入: pIp - ip地址串
	  uPort - 端口
返回值: 成功返回true，否则返回false
******************************************************************************/
bool CSocket::Connect(const char* pIp, unsigned short uPort)
{
	if(pIp == NULL)
	{
		return false;
	}
	else
	{
		return Connect(inet_addr(pIp), uPort);
	}
}

/******************************************************************************
函数名称: Connect
功能描述: 同步方式连接远程主机
输入: uIp - ip地址，网络序
	  uPort - 端口
返回值: 成功返回true，否则返回false
******************************************************************************/
bool CSocket::Connect(unsigned int uIp, unsigned short uPort)
{
	if(m_Socket == 0)
	{
		return false;
	}

	//CInetAddress oAddr;
	//oAddr.SetIP(uIp);
	//oAddr.SetPorT(uPort);
    struct sockaddr_in serv_addr;
    memset((char*) &serv_addr, 0, sizeof(serv_addr));
 	serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = uIp;
    serv_addr.sin_port = htons(uPort);  

	int nRet = connect(m_Socket, (struct sockaddr *) &serv_addr, sizeof(serv_addr) );
	if(nRet == 0)
	{
		return true;
	}
	else
	{
#if defined(_WIN32) || defined(WIN32)
		int nError = WSAGetLastError();
		if(nError ==  WSAEWOULDBLOCK)
		{
			return true;
		}
		else
		{
			return false;
		}
#else
		if(nRet == -1 && errno == EINPROGRESS)
		{
			return true;
		}
		else
		{
			return false;

		}
#endif
	}
}

/******************************************************************************
函数名称: Bind
功能描述: 绑定指定的地址和端口
输入: pIp - ip地址串
	  uPort - 端口
返回值: 成功返回true，否则返回false
******************************************************************************/
bool CSocket::Bind(const char* pIp, unsigned short uPort)
{
	return Bind(inet_addr(pIp), uPort);
}

/******************************************************************************
函数名称: Bind
功能描述: 绑定指定的地址和端口
输入: uIp - ip地址，网络序
	  uPort - 端口
返回值: 成功返回true，否则返回false
******************************************************************************/
bool CSocket::Bind(unsigned int uIp, unsigned short uPort)
{
	//if(m_Socket == INVALID_SOCKET)
	//{
	//	return false;
	//}

	//CInetAddress oAddr;
	//oAddr.SetIP(uIp);
	//oAddr.SetPorT(uPort);

	//return ::bind(m_Socket, oAddr, oAddr.GetLength()) == 0;
	return false;
}

/******************************************************************************
函数名称: Listen
功能描述: 启动侦听
输入: 
返回值: 成功返回true，否则返回false
******************************************************************************/
bool CSocket::Listen()
{
	if(m_Socket == 0)
	{
		return false;
	}

	return listen(m_Socket, 5) == 0;
}

/******************************************************************************
函数名称: Read
功能描述: 读取数据
输入: pBuffer - 缓冲区
	  nLen - 读取长度
返回值: -1表示失败 0表示连接已关闭 其它表示成功读取的数据长度
******************************************************************************/
int CSocket::Read(const char* pBuffer, int nLen)
{
	if(m_Socket == 0)
	{
		return -1;
	}

	return recv(m_Socket, (char*)pBuffer, nLen, 0);
}

/******************************************************************************
函数名称: Write
功能描述: 写数据
输入: pBuffer - 缓冲区
	  nLen - 写入长度
返回值:  -1表示失败 其它表示成功拷贝的数据长度
******************************************************************************/
int CSocket::Write(const char* pBuffer, int nLen)
{
	if(m_Socket == 0)
	{
		return -1;
	}
//#if ( defined(_WIN32) || defined(WIN32) || defined(ANDROID)  )
#if ( defined(_WIN32) || defined(WIN32) )
	return send(m_Socket, pBuffer, nLen, 0);
#else //(UNIX)
    return send(m_Socket, pBuffer, nLen, MSG_NOSIGNAL);
#endif
}

/******************************************************************************
函数名称: Disconnect
功能描述: 断开连接
输入: 
返回值: 
******************************************************************************/
void CSocket::Disconnect()
{
//	if(m_Socket != INVALID_SOCKET)
//	{
//#if (WIN32)
//		shutdown(m_Socket, SD_BOTH);
//#else
//        shutdown(m_Socket, SHUT_RDWR);
//#endif
//	}
}

/******************************************************************************
函数名称: Close
功能描述: 关闭套接字
输入: 
返回值: 
******************************************************************************/
void CSocket::Close()
{
	if(m_Socket)
	{
#if defined(_WIN32) || defined(WIN32)
		closesocket(m_Socket);
#else
		close(m_Socket);        
#endif
	}
}

/******************************************************************************
函数名称: IsReadable
功能描述: 检查套接字是否可读
输入: 
返回值: 可读则返回true，否则返回false
******************************************************************************/
bool CSocket::IsReadable()
{
	fd_set	fd;
	struct timeval tv;

	FD_ZERO(&fd);
	FD_SET(m_Socket, &fd);

	tv.tv_sec = 0;
	tv.tv_usec = 0;

	if(select((int)(m_Socket + 1), &fd, NULL, NULL, &tv) > 0)
	{
		if(FD_ISSET(m_Socket, &fd))
		{
			return true;
		}
	}

	return false;
}

/******************************************************************************
函数名称: IsWritable
功能描述: 检查套接字是否可写
输入: 
返回值: 可写则返回true，否则返回false
******************************************************************************/
bool CSocket::IsWritable()
{
	fd_set	fd;
	struct timeval tv;

	FD_ZERO(&fd);
	FD_SET(m_Socket, &fd);

	tv.tv_sec = 0;
	tv.tv_usec = 0;
	int aaa = select((int)(m_Socket + 1), NULL, &fd, NULL, &tv);
	if(select((int)(m_Socket + 1), NULL, &fd, NULL, &tv) > 0)
	{
		if(FD_ISSET(m_Socket, &fd))
		{
			return true;
		}
	}

	return false;
}

/******************************************************************************
函数名称: IsConnected
功能描述: 检查套接字是否处于连接状态
输入: 
返回值: 连接则返回true，否则返回false
******************************************************************************/
bool CSocket::IsConnected()
{
	return IsWritable();
}

/******************************************************************************
函数名称: IsAcceptable
功能描述: 检查套接字是否有连接请求可接受
输入: 
返回值: 可接受则返回true，否则返回false
******************************************************************************/
bool CSocket::IsAcceptable()
{
	return IsReadable();
}
