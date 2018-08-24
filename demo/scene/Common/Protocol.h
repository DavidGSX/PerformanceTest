#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__

#define PCS_TLoginGame 1

#include<cstring>

struct TLoginDataReq
{
	char userId[20];
	char account[20];
	char pwd[20];

	TLoginDataReq()
	{
		memset(userId, 0, sizeof(userId));
		memset(account, 0, sizeof(account));
		memset(pwd, 0, sizeof(pwd));
	}
};


struct TLoginDataResp
{
	int ret_code;
};


#endif /* __PROTOCOL_H__ */
