/* This file is generated by tdr. */
/* No manual modification is permitted. */

/* creation time: Sat Sep 23 11:22:48 2017 */
/* tdr version: 2.7.22, build at 20170613 */

#ifndef TSF4G_TDR_TDR_BUF_H_
#define TSF4G_TDR_TDR_BUF_H_

#include <new>
#include <cstdarg>

#include "TdrPal.h"
#include "TdrError.h"

namespace tsf4g_tdr
{


union TdrFUI32
{
        float f;
        uint32_t i32;
};

union TdrDUI64
{
        double d;
        uint64_t i64;
};


class TdrWriteBuf
{
        private:
                char* beginPtr;
                size_t position;
                size_t length;

        private:
                bool needFree;

        private:
                void _free()
                {
                        delete [] beginPtr;
                        needFree = false;
                        beginPtr = NULL;
                }

                void _set(char* ptr, size_t size)
                {
                        beginPtr = ptr;
                        position = 0;
                        if (NULL == beginPtr)
                        {
                                length = 0;
                        } else
                        {
                                length = size;
                        }
                }

                void _reset()
                {
                        beginPtr = NULL;
                        length = 0;
                        position = 0;
                }

        public:
                TdrWriteBuf()
                {
                        needFree = false;
                        _reset();
                }

                TdrWriteBuf(size_t size)
                {
                        char* ptr = new(std::nothrow) char [size];
                        if (NULL != ptr)
                        {
                                needFree = true;
                        } else
                        {
                                needFree = false;
                        }
                        _set(ptr, size);
                }

                TdrWriteBuf(char* ptr, size_t size)
                {
                        needFree = false;
                        _set(ptr, size);
                }

                ~TdrWriteBuf()
                {
                        if (needFree)
                        {
                                _free();
                        }
                }

                void reset()
                {
                        if (needFree)
                        {
                                _free();
                        }
                        _reset();
                }

                void set(char* ptr, size_t size)
                {
                        if (needFree)
                        {
                                _free();
                        }
                        _set(ptr, size);
                }

                size_t getUsedSize() const
                {
                        return position;
                }

                size_t getTotalSize() const
                {
                        return length;
                }

                size_t getLeftSize() const
                {
                        assert(position <= length);

                        return length - position;
                }

                const char* getBeginPtr() const
                {
                        return beginPtr;
                }

                TdrError::ErrorType reserve(size_t gap)
                {
                        assert(position <= length);

                        if (position > length)
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_WRITE;
                        }

                        if (gap > (length - position))
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_WRITE;
                        }

                        position += gap;

                        return TdrError::TDR_NO_ERROR;
                }

        public: /* print data visually */
                TdrError::ErrorType vtextize(const char* format, va_list ap)
                {
                        int ret = tdr_cpp_vsnprintf(beginPtr + position, length - position, format, ap);
                        if (0 > ret || (size_t)ret >= (length - position))
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_WRITE;
                        }
                        position += ret;

                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType textize(const char* format, ...)
                {
                        va_list ap;

                        va_start(ap, format);
                        TdrError::ErrorType ret = vtextize(format, ap);
                        va_end(ap);

                        return ret;
                }

        public: /* write successively */
                TdrError::ErrorType writeChar(const char src)
                {
                        return writeUInt8(*(uint8_t*)&src);
                }

                /* this function is supposed to be called by visualize() directly or indiectly */
                TdrError::ErrorType writeCharWithNull(const char src)
                {
                        assert(position <= length);

                        if (sizeof(src) + 1 > (length - position))
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_WRITE;
                        }

                        *(char*)(beginPtr + position) = src;
                        position += sizeof(src);

                        /* a null character is writed, but keeps position untouched */
                        *(char*)(beginPtr + position) = '\0';

                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType writeUChar(const unsigned char src)
                {
                        return writeUInt8(*(uint8_t*)&src);
                }

                TdrError::ErrorType writeInt8(const int8_t src)
                {
                        return writeUInt8(*(uint8_t*)&src);
                }

                TdrError::ErrorType writeUInt8(const uint8_t src)
                {
                        assert(position <= length);

                        if (sizeof(src) > (length - position))
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_WRITE;
                        }

                        *(uint8_t*)(beginPtr + position) = src;
                        position += sizeof(src);

                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType writeInt16(const int16_t src)
                {
                        return writeUInt16(*(uint16_t*)&src);
                }

                TdrError::ErrorType writeUInt16(const uint16_t src)
                {
                        assert(position <= length);

                        if (sizeof(src) > (length - position))
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_WRITE;
                        }

                        tdr_cpp_cast_hton16(beginPtr + position, &src);
                        position += sizeof(src);

                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType writeInt32(const int32_t src)
                {
                        return writeUInt32(*(uint32_t*)&src);
                }

                TdrError::ErrorType writeUInt32(const uint32_t src)
                {
                        assert(position <= length);

                        if (sizeof(src) > (length - position))
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_WRITE;
                        }

                        tdr_cpp_cast_hton32(beginPtr + position, &src);
                        position += sizeof(src);

                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType writeInt64(const int64_t src)
                {
                        return writeUInt64(*(uint64_t*)&src);
                }

                TdrError::ErrorType writeUInt64(const uint64_t src)
                {
                        assert(position <= length);

                        if (sizeof(src) > (length - position))
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_WRITE;
                        }

                        tdr_cpp_cast_hton64(beginPtr + position, &src);
                        position += sizeof(src);

                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType writeFloat(const float src)
                {
                        TdrFUI32 f2i;
                        TDR_CPP_OS_CAST_32(&f2i.f, &src);
                        return writeUInt32(f2i.i32);
                }

                TdrError::ErrorType writeDouble(const double src)
                {
                        TdrDUI64 d2i;
                        TDR_CPP_OS_CAST_64(&d2i.d, &src);
                        return writeUInt64(d2i.i64);
                }

                TdrError::ErrorType writeBytes(const void* src, size_t count)
                {
                        if (NULL == src)
                        {
                                return TdrError::TDR_ERR_ARG_POINTER_IS_NULL;
                        }

                        assert(position <= length);

                        if (count > (length - position))
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_WRITE;
                        }

                        memmove(beginPtr + position, src, count);
                        position += count;

                        return TdrError::TDR_NO_ERROR;
                }

        public: /* write directly */
                TdrError::ErrorType writeChar(const char src, size_t pos)
                {
                        return writeUInt8((uint8_t)src, pos);
                }

                TdrError::ErrorType writeUChar(const unsigned char src, size_t pos)
                {
                        return writeUInt8((uint8_t)src, pos);
                }

                TdrError::ErrorType writeInt8(const int8_t src, size_t pos)
                {
                        return writeUInt8((uint8_t)src, pos);
                }

                TdrError::ErrorType writeUInt8(const uint8_t src, size_t pos)
                {
                        assert(position <= length);

                        if (pos > length)
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_WRITE;
                        }

                        if (sizeof(src) > (length - pos))
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_WRITE;
                        }

                        *(uint8_t*)(beginPtr + pos) = src;

                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType writeInt16(const int16_t src, size_t pos)
                {
                        return writeUInt16((uint16_t)src, pos);
                }

                TdrError::ErrorType writeUInt16(const uint16_t src, size_t pos)
                {
                        assert(position <= length);

                        if (pos > length)
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_WRITE;
                        }

                        if (sizeof(src) > (length - pos))
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_WRITE;
                        }

                        tdr_cpp_cast_hton16(beginPtr + pos, &src);

                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType writeInt32(const int32_t src, size_t pos)
                {
                        return writeUInt32((uint32_t)src, pos);
                }

                TdrError::ErrorType writeUInt32(const uint32_t src, size_t pos)
                {
                        assert(position <= length);

                        if (pos > length)
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_WRITE;
                        }

                        if (sizeof(src) > (length - pos))
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_WRITE;
                        }

                        tdr_cpp_cast_hton32(beginPtr + pos, &src);

                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType writeInt64(const int64_t src, size_t pos)
                {
                        return writeUInt64((uint64_t)src, pos);
                }

                TdrError::ErrorType writeUInt64(const uint64_t src, size_t pos)
                {
                        assert(position <= length);

                        if (pos > length)
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_WRITE;
                        }

                        if (sizeof(src) > (length - pos))
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_WRITE;
                        }

                        tdr_cpp_cast_hton64(beginPtr + pos, &src);

                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType writeFloat(const float src, size_t pos)
                {
                        TdrFUI32 f2i;
                        f2i.f = src;
                        return writeUInt32(f2i.i32, pos);
                }

                TdrError::ErrorType writeDouble(const double src, size_t pos)
                {
                        TdrDUI64 d2i;
                        d2i.d = src;
                        return writeUInt64(d2i.i64, pos);
                }

                TdrError::ErrorType writeBytes(const void* src, size_t count, size_t pos)
                {
                        if (NULL == src)
                        {
                                return TdrError::TDR_ERR_ARG_POINTER_IS_NULL;
                        }

                        assert(position <= length);

                        if (count > (length - pos))
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_WRITE;
                        }

                        memmove(beginPtr + pos, src, count);

                        return TdrError::TDR_NO_ERROR;
                }

                /* base 128 varints */
                TdrError::ErrorType writeVarInt16(int16_t src)
                {
                        assert(position <= length);

                        size_t used = 0;
                        int ret = 0;
                        tdr_cpp_zigzag_varint_hton16(src, beginPtr + position, length - position, used, ret);
                        if (ret != 0)
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_WRITE;
                        }

                        position += used;
                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType writeVarUInt16(uint16_t src)
                {
                        assert(position <= length);

                        size_t used = 0;
                        int ret = 0;
                        tdr_cpp_varint_hton16(src, beginPtr + position, length - position, used, ret);
                        if (ret != 0)
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_WRITE;
                        }

                        position += used;
                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType writeVarInt32(int32_t src)
                {
                        assert(position <= length);

                        size_t used = 0;
                        int ret = 0;
                        tdr_cpp_zigzag_varint_hton32(src, beginPtr + position, length - position, used, ret);
                        if (ret != 0)
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_WRITE;
                        }

                        position += used;
                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType writeVarUInt32(uint32_t src)
                {
                        assert(position <= length);

                        size_t used = 0;
                        int ret = 0;
                        tdr_cpp_varint_hton32(src, beginPtr + position, length - position, used, ret);
                        if (ret != 0)
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_WRITE;
                        }

                        position += used;
                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType writeVarInt64(int64_t src)
                {
                        assert(position <= length);

                        size_t used = 0;
                        int ret = 0;
                        tdr_cpp_zigzag_varint_hton64(src, beginPtr + position, length - position, used, ret);
                        if (ret != 0)
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_WRITE;
                        }

                        position += used;
                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType writeVarUInt64(uint64_t src)
                {
                        assert(position <= length);

                        size_t used = 0;
                        int ret = 0;
                        tdr_cpp_varint_hton64(src, beginPtr + position, length - position, used, ret);
                        if (ret != 0)
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_WRITE;
                        }

                        position += used;
                        return TdrError::TDR_NO_ERROR;
                }
};

class TdrReadBuf
{
        private:
                const char* beginPtr;
                size_t position;
                size_t length;

        public:
                TdrReadBuf()
                {
                        reset();
                }

                TdrReadBuf(const char* ptr, size_t size)
                {
                        set(ptr, size);
                }

                explicit TdrReadBuf(const TdrWriteBuf& writeBuf)
                {
                        set(writeBuf.getBeginPtr(), writeBuf.getUsedSize());
                }

                void reset()
                {
                        beginPtr = NULL;
                        length = 0;
                        position = 0;
                }

                void set(const char* ptr, size_t size)
                {
                        beginPtr = ptr;
                        position = 0;
                        if (NULL == beginPtr)
                        {
                                length = 0;
                        } else
                        {
                                length = size;
                        }
                }

                size_t getUsedSize() const
                {
                        return position;
                }

                size_t getTotalSize() const
                {
                        return length;
                }

                size_t getLeftSize() const
                {
                        assert(position <= length);

                        return length - position;
                }

                const char* getCurrentPtr() const
                {
                        return beginPtr + position;
                }

                TdrError::ErrorType toHexStr(char* destBuf, size_t len, size_t* usedLen = NULL) const;

                TdrError::ErrorType fromHexStr(const char* srcHexStr, size_t len, size_t* usedLen = NULL);

        public: /* read successively */
                TdrError::ErrorType readChar(char& dest)
                {
                        return readUInt8(*(uint8_t*)&dest);
                }

                TdrError::ErrorType readUChar(unsigned char& dest)
                {
                        return readUInt8(*(uint8_t*)&dest);
                }

                TdrError::ErrorType readInt8(int8_t& dest)
                {
                        return readUInt8(*(uint8_t*)&dest);
                }

                TdrError::ErrorType readUInt8(uint8_t& dest)
                {
                        assert(position <= length);

                        if (sizeof(dest) > (length - position))
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_READ;
                        }

                        dest = *(uint8_t*)(beginPtr + position);
                        position += sizeof(dest);

                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType readInt16(int16_t& dest)
                {
                        return readUInt16(*(uint16_t*)&dest);
                }

                TdrError::ErrorType readUInt16(uint16_t& dest)
                {
                        assert(position <= length);

                        if (sizeof(dest) > (length - position))
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_READ;
                        }

                        tdr_cpp_cast_ntoh16(&dest, beginPtr + position);
                        position += sizeof(dest);

                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType readInt32(int32_t& dest)
                {
                        return readUInt32(*(uint32_t*)&dest);
                }

                TdrError::ErrorType readUInt32(uint32_t& dest)
                {
                        assert(position <= length);

                        if (sizeof(dest) > (length - position))
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_READ;
                        }

                        tdr_cpp_cast_ntoh32(&dest, beginPtr + position);
                        position += sizeof(dest);

                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType readInt64(int64_t& dest)
                {
                        return readUInt64(*(uint64_t*)&dest);
                }

                TdrError::ErrorType readUInt64(uint64_t& dest)
                {
                        assert(position <= length);

                        if (sizeof(dest) > (length - position))
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_READ;
                        }

                        tdr_cpp_cast_ntoh64(&dest, beginPtr + position);
                        position += sizeof(dest);

                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType readFloat(float& dest)
                {
                        TdrFUI32 i2f;
                        TdrError::ErrorType ret = readUInt32(i2f.i32);
                        if (TdrError::TDR_NO_ERROR == ret)
                        {
                                TDR_CPP_OS_CAST_32(&dest, &i2f.f);
                        }

                        return ret;
                }

                TdrError::ErrorType readDouble(double& dest)
                {
                        TdrDUI64 i2d;
                        TdrError::ErrorType ret = readUInt64(i2d.i64);
                        if (TdrError::TDR_NO_ERROR == ret)
                        {
                                TDR_CPP_OS_CAST_64(&dest, &i2d.d);
                        }

                        return ret;
                }

                TdrError::ErrorType readBytes(void* dest, size_t count)
                {
                        if (NULL == dest)
                        {
                                return TdrError::TDR_ERR_ARG_POINTER_IS_NULL;
                        }

                        assert(position <= length);

                        if (count > (length - position))
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_READ;
                        }

                        memmove(dest, beginPtr + position, count);
                        position += count;

                        return TdrError::TDR_NO_ERROR;
                }

        public: /* read directly */
                TdrError::ErrorType readChar(char& dest, size_t pos)
                {
                        return readUInt8(*(uint8_t*)&dest, pos);
                }

                TdrError::ErrorType readUChar(unsigned char& dest, size_t pos)
                {
                        return readUInt8(*(uint8_t*)&dest, pos);
                }

                TdrError::ErrorType readInt8(int8_t& dest, size_t pos)
                {
                        return readUInt8(*(uint8_t*)&dest, pos);
                }

                TdrError::ErrorType readUInt8(uint8_t& dest, size_t pos)
                {
                        assert(position <= length);

                        if (pos > length)
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_READ;
                        }

                        if (sizeof(dest) > (length - pos))
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_READ;
                        }

                        dest = *(uint8_t*)(beginPtr + pos);

                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType readInt16(int16_t& dest, size_t pos)
                {
                        return readUInt16(*(uint16_t*)&dest, pos);
                }

                TdrError::ErrorType readUInt16(uint16_t& dest, size_t pos)
                {
                        assert(position <= length);

                        if (pos > length)
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_READ;
                        }

                        if (sizeof(dest) > (length - pos))
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_READ;
                        }

                        tdr_cpp_cast_ntoh16(&dest, beginPtr + pos);

                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType readInt32(int32_t& dest, size_t pos)
                {
                        return readUInt32(*(uint32_t*)&dest, pos);
                }

                TdrError::ErrorType readUInt32(uint32_t& dest, size_t pos)
                {
                        assert(position <= length);

                        if (pos > length)
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_READ;
                        }

                        if (sizeof(dest) > (length - pos))
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_READ;
                        }

                        tdr_cpp_cast_ntoh32(&dest, beginPtr + pos);

                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType readInt64(int64_t& dest, size_t pos)
                {
                        return readUInt64(*(uint64_t*)&dest, pos);
                }

                TdrError::ErrorType readUInt64(uint64_t& dest, size_t pos)
                {
                        assert(position <= length);

                        if (pos > length)
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_READ;
                        }

                        if (sizeof(dest) > (length - pos))
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_READ;
                        }

                        tdr_cpp_cast_ntoh64(&dest, beginPtr + pos);

                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType readFloat(float& dest, size_t pos)
                {
                        TdrFUI32 i2f;
                        TdrError::ErrorType ret = readUInt32(i2f.i32, pos);
                        if (TdrError::TDR_NO_ERROR == ret)
                        {
                                dest = i2f.f;
                        }

                        return ret;
                }

                TdrError::ErrorType readDouble(double& dest, size_t pos)
                {
                        TdrDUI64 i2d;
                        TdrError::ErrorType ret = readUInt64(i2d.i64, pos);
                        if (TdrError::TDR_NO_ERROR == ret)
                        {
                                dest = i2d.d;
                        }

                        return ret;
                }

                TdrError::ErrorType readBytes(void* dest, size_t count, size_t pos)
                {
                        if (NULL == dest)
                        {
                                return TdrError::TDR_ERR_ARG_POINTER_IS_NULL;
                        }

                        assert(position <= length);

                        if (count > (length - pos))
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_READ;
                        }

                        memmove(dest, beginPtr + pos, count);

                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType readVarInt16(int16_t& dest)
                {
                        assert(position <= length);

                        int ret = 0;
                        size_t used = 0;
                        tdr_cpp_zigzag_varint_ntoh16(beginPtr + position, length - position, used, dest, ret);
                        if (ret != 0)
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_READ;
                        }

                        position += used;
                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType readVarUInt16(uint16_t& dest)
                {
                        assert(position <= length);

                        int ret = 0;
                        size_t used = 0;
                        tdr_cpp_varint_ntoh16(beginPtr + position, length - position, used, dest, ret);
                        if (ret != 0)
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_READ;
                        }

                        position += used;
                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType readVarInt32(int32_t& dest)
                {
                        assert(position <= length);

                        int ret = 0;
                        size_t used = 0;
                        tdr_cpp_zigzag_varint_ntoh32(beginPtr + position, length - position, used, dest, ret);
                        if (ret != 0)
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_READ;
                        }

                        position += used;
                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType readVarUInt32(uint32_t& dest)
                {
                        assert(position <= length);

                        int ret = 0;
                        size_t used = 0;
                        tdr_cpp_varint_ntoh32(beginPtr + position, length - position, used, dest, ret);
                        if (ret != 0)
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_READ;
                        }

                        position += used;
                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType readVarInt64(int64_t& dest)
                {
                        assert(position <= length);

                        int ret = 0;
                        size_t used = 0;
                        tdr_cpp_zigzag_varint_ntoh64(beginPtr + position, length - position, used, dest, ret);
                        if (ret != 0)
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_READ;
                        }

                        position += used;
                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType readVarUInt64(uint64_t& dest)
                {
                        assert(position <= length);

                        int ret = 0;
                        size_t used = 0;
                        tdr_cpp_varint_ntoh64(beginPtr + position, length - position, used, dest, ret);
                        if (ret != 0)
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_READ;
                        }

                        position += used;
                        return TdrError::TDR_NO_ERROR;
                }

                TdrError::ErrorType skipForward(size_t step)
                {
                        assert(position <= length);

                        if (length - position < step)
                        {
                                return TdrError::TDR_ERR_SHORT_BUF_FOR_READ;
                        }

                        position += step;
                        return TdrError::TDR_NO_ERROR;
                }
};

template<typename TYPE>
TdrError::ErrorType
restoreFromHexStr(TYPE& data, const char* srcHexStr, size_t len, size_t* usedLen = NULL)
{
        if (NULL == srcHexStr)
        {
                return TdrError::TDR_ERR_NULL_POINTER_PARAMETER;
        }

        return TdrReadBuf((char*)&data, sizeof(data)).fromHexStr(srcHexStr, len, usedLen);
}

}
#endif
