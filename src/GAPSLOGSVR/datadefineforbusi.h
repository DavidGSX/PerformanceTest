/* This file is generated by tdr. */
/* No manual modification is permitted. */

/* metalib version: 1 */
/* metalib md5sum: fe08469aaccd2d1ac639b14e9dcdfeb7 */

/* creation time: Sat Sep 23 11:22:48 2017 */
/* tdr version: 2.7.22, build at 20170613 */

#ifndef datadefineforbusi_h_
#define datadefineforbusi_h_

#include "TdrBuf.h"
#include "TdrError.h"
#include "TdrBufUtil.h"


namespace GAPSLOGSVR
{

using tsf4g_tdr::TdrError;
using tsf4g_tdr::TdrReadBuf;
using tsf4g_tdr::TdrWriteBuf;


enum
{
        AWARD_NAME_LEN = 64,
};


enum ESTAT_TYPE_FOR_BUSI // 定义业务统计类型
{
        ESTAT_TYPE_NULL = 0,
        ESTAT_TYPE_AWARD = 1,
        ESTAT_TYPE_ERRORCODE = 2,
        ESTAT_TYPE_MAX = 3,
};


#pragma pack(1)


class STErrorCodeData
{
        public: /* members */
                int32_t iCmdId; //错误消息ID, 如果是全局错误码通常没有此ID
                int32_t iErrorCode; //错误码

        public: /* methods */
                TdrError::ErrorType construct();

                TdrError::ErrorType pack(TdrWriteBuf& destBuf, unsigned cutVer = 0) const;
                TdrError::ErrorType pack(char* buffer, size_t size, size_t* usedSize = NULL, unsigned cutVer = 0) const;

                TdrError::ErrorType unpack(TdrReadBuf& srcBuf, unsigned cutVer = 0);
                TdrError::ErrorType unpack(const char* buffer, size_t size, size_t* usedSize = NULL, unsigned cutVer = 0);

                /* set indent = -1 to disable indent */
                TdrError::ErrorType visualize(TdrWriteBuf& destBuf, int indent = 0, char separator = '\n') const;
                TdrError::ErrorType visualize(char* buffer, size_t size, size_t* usedSize = NULL, int indent = 0, char separator = '\n') const;
                const char* visualize_ex(TdrWriteBuf& destBuf, int indent = 0, char separator = '\n') const;
                const char* visualize_ex(char* buffer, size_t size, size_t* usedSize = NULL, int indent = 0, char separator = '\n') const;


        public:
                /* version infomation */
                enum
                {
                        BASEVERSION = 1,
                        CURRVERSION = 1,
                };
};

typedef       STErrorCodeData          tagSTErrorCodeData;
typedef       STErrorCodeData             STERRORCODEDATA;
typedef       STErrorCodeData*          LPSTERRORCODEDATA;
typedef const STErrorCodeData*         LCPSTERRORCODEDATA;


class STAwardBaseData
{
        public: /* members */
                int32_t iAwardType; //奖励类型(比如道具、装备、现金等等)
                int32_t iAwardValue; //奖励内容(比如道具ID、装备ID、现金数目等等)
                char szAwardName[AWARD_NAME_LEN]; //奖品名称,与type，value对应

        public: /* methods */
                TdrError::ErrorType construct();

                TdrError::ErrorType pack(TdrWriteBuf& destBuf, unsigned cutVer = 0) const;
                TdrError::ErrorType pack(char* buffer, size_t size, size_t* usedSize = NULL, unsigned cutVer = 0) const;

                TdrError::ErrorType unpack(TdrReadBuf& srcBuf, unsigned cutVer = 0);
                TdrError::ErrorType unpack(const char* buffer, size_t size, size_t* usedSize = NULL, unsigned cutVer = 0);

                /* set indent = -1 to disable indent */
                TdrError::ErrorType visualize(TdrWriteBuf& destBuf, int indent = 0, char separator = '\n') const;
                TdrError::ErrorType visualize(char* buffer, size_t size, size_t* usedSize = NULL, int indent = 0, char separator = '\n') const;
                const char* visualize_ex(TdrWriteBuf& destBuf, int indent = 0, char separator = '\n') const;
                const char* visualize_ex(char* buffer, size_t size, size_t* usedSize = NULL, int indent = 0, char separator = '\n') const;


        public:
                /* version infomation */
                enum
                {
                        BASEVERSION = 1,
                        CURRVERSION = 1,
                };
};

typedef       STAwardBaseData          tagSTAwardBaseData;
typedef       STAwardBaseData             STAWARDBASEDATA;
typedef       STAwardBaseData*          LPSTAWARDBASEDATA;
typedef const STAwardBaseData*         LCPSTAWARDBASEDATA;


class STBaseData
{
        public: /* members */
                union
                {
                        char chReserve; /**id:<all other values>*/
                        STAwardBaseData stAwardData; /**id:ESTAT_TYPE_AWARD*/
                        STErrorCodeData stErrorCodeData; /**id:ESTAT_TYPE_ERRORCODE*/
                };

        public: /* methods */
                TdrError::ErrorType construct(int64_t selector);

                TdrError::ErrorType construct();

                TdrError::ErrorType pack(int64_t selector, TdrWriteBuf& destBuf, unsigned cutVer = 0) const;
                TdrError::ErrorType pack(int64_t selector, char* buffer, size_t size,
                                         size_t* usedSize = NULL, unsigned cutVer = 0) const;

                TdrError::ErrorType unpack(int64_t selector, TdrReadBuf& srcBuf, unsigned cutVer = 0);
                TdrError::ErrorType unpack(int64_t selector, const char* buffer, size_t size,
                                           size_t* usedSize = NULL, unsigned cutVer = 0);

                TdrError::ErrorType visualize(int64_t selector, TdrWriteBuf& destBuf,
                                              int indent = 0, char separator = '\n') const;
                TdrError::ErrorType visualize(int64_t selector, char* buffer, size_t size,
                                              size_t* usedSize = NULL, int indent = 0, char separator = '\n') const;


        public:
                /* version infomation */
                enum
                {
                        BASEVERSION = 1,
                        CURRVERSION = 1,
                };
};

typedef       STBaseData          tagSTBaseData;
typedef       STBaseData             STBASEDATA;
typedef       STBaseData*          LPSTBASEDATA;
typedef const STBaseData*         LCPSTBASEDATA;


class STStatBaseData
{
        public: /* members */
                unsigned char bStatType; //统计数据类型
                STBaseData stBaseData; //具体的统计基础数据描述

        public: /* methods */
                TdrError::ErrorType construct();

                TdrError::ErrorType pack(TdrWriteBuf& destBuf, unsigned cutVer = 0) const;
                TdrError::ErrorType pack(char* buffer, size_t size, size_t* usedSize = NULL, unsigned cutVer = 0) const;

                TdrError::ErrorType unpack(TdrReadBuf& srcBuf, unsigned cutVer = 0);
                TdrError::ErrorType unpack(const char* buffer, size_t size, size_t* usedSize = NULL, unsigned cutVer = 0);

                /* set indent = -1 to disable indent */
                TdrError::ErrorType visualize(TdrWriteBuf& destBuf, int indent = 0, char separator = '\n') const;
                TdrError::ErrorType visualize(char* buffer, size_t size, size_t* usedSize = NULL, int indent = 0, char separator = '\n') const;
                const char* visualize_ex(TdrWriteBuf& destBuf, int indent = 0, char separator = '\n') const;
                const char* visualize_ex(char* buffer, size_t size, size_t* usedSize = NULL, int indent = 0, char separator = '\n') const;


        public:
                /* version infomation */
                enum
                {
                        BASEVERSION = 1,
                        CURRVERSION = 1,
                };
};

typedef       STStatBaseData          tagSTStatBaseData;
typedef       STStatBaseData             STSTATBASEDATA;
typedef       STStatBaseData*          LPSTSTATBASEDATA;
typedef const STStatBaseData*         LCPSTSTATBASEDATA;


#pragma pack()

}
#endif
