#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__

//cmd
#define PCS_TLoginGame 1

struct TLoginDataReq
{
	int userId;
	char account[20];
	char pwd[20];
};


struct TLoginDataResp
{
	int ret_code;
};


#endif /* __PROTOCOL_H__ */