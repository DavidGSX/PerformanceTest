/*
 * adr.h
 *
 *  Created on: 2009-09-29
 *  Author: borisliu
 */

#ifndef __NARUTO_DR_H__
#define __NARUTO_DR_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <iomanip>
#include <string>
#include <iostream>
#include <exception>
#include <stddef.h>

#ifdef _WIN32

#include <WINSOCK2.H>

#else
#include <arpa/inet.h>
#endif

typedef unsigned int           uint32_t;

class ADR
{
public:
    ADR(): read_pos_(0), write_pos_(0), buffer_(NULL), len_(0) {}
    ADR(char * buffer, size_t len): read_pos_(0), write_pos_(0),
        buffer_(buffer), len_(len) {}

    ~ADR() {}

    inline void Reset(char * buffer, size_t len) { read_pos_ = write_pos_ = 0; buffer_ = buffer; len_ = len; }

    inline size_t Len() const { return len_; }

    inline const char * InnerBuffer() const { return buffer_; }

    inline size_t ReadPos() const { return read_pos_; }
    inline void ReadPos(size_t pos) { read_pos_ = pos; }

    inline size_t WritePos() const { return write_pos_; }
    inline void WritePos(size_t pos) { write_pos_ = pos; }

   /*
	bool Read(int8_t & value)
    {
        if (read_pos_ + sizeof(value) > len_) return false;
        memcpy(&value, buffer_ + read_pos_, sizeof(value));
        read_pos_ += sizeof(value);
        return true;
    }
    bool Write(int8_t value)
    {
        if (write_pos_ + sizeof(value) > len_) return false;
        memcpy(buffer_ + write_pos_, &value, sizeof(value));
        write_pos_ += sizeof(value);
        return true;
    }
    bool Read(uint8_t & value)
    {
        if (read_pos_ + sizeof(value) > len_) return false;
        memcpy(&value, buffer_ + read_pos_, sizeof(value));
        read_pos_ += sizeof(value);
        return true;
    }
    bool Write(uint8_t value)
    {
        if (write_pos_ + sizeof(value) > len_) return false;
        memcpy(buffer_ + write_pos_, &value, sizeof(value));
        write_pos_ += sizeof(value);
        return true;
    }

    bool Read(int16_t & value, char ntoh = 1)
    {
        if (read_pos_ + sizeof(value) > len_) return false;
        memcpy(&value, buffer_ + read_pos_, sizeof(value));
        if (ntoh) value = ntohs(value);
        read_pos_ += sizeof(value);
        return true;
    }
    bool Write(int16_t value, char hton = 1)
    {
        if (write_pos_ + sizeof(value) > len_) return false;
        if (hton) value = htons(value);
        memcpy(buffer_ + write_pos_, &value, sizeof(value));
        write_pos_ += sizeof(value);
        return true;
    }
    bool Read(uint16_t & value, char ntoh = 1)
    {
        if (read_pos_ + sizeof(value) > len_) return false;
        memcpy(&value, buffer_ + read_pos_, sizeof(value));
        if (ntoh) value = ntohs(value);
        read_pos_ += sizeof(value);
        return true;
    }
    bool Write(uint16_t value, char hton = 1)
    {
        if (write_pos_ + sizeof(value) > len_) return false;
        if (hton) value = htons(value);
        memcpy(buffer_ + write_pos_, &value, sizeof(value));
        write_pos_ += sizeof(value);
        return true;
    }

    bool Read(int32_t & value, char ntoh = 1)
    {
        if (read_pos_ + sizeof(value) > len_) return false;
        memcpy(&value, buffer_ + read_pos_, sizeof(value));
        if (ntoh) value = ntohl(value);
        read_pos_ += sizeof(value);
        return true;
    }
    bool Write(int32_t value, char hton = 1)
    {
        if (write_pos_ + sizeof(value) > len_) return false;
        if (hton) value = htonl(value);
        memcpy(buffer_ + write_pos_, &value, sizeof(value));
        write_pos_ += sizeof(value);
        return true;
    }
	*/
    bool Read(uint32_t & value, char ntoh = 1)
    {
        if (read_pos_ + sizeof(value) > len_) return false;
        memcpy(&value, buffer_ + read_pos_, sizeof(value));
        if (ntoh) value = ntohl(value);
        read_pos_ += sizeof(value);
        return true;
    }
    bool Write(uint32_t value, char hton = 1)
    {
        if (write_pos_ + sizeof(value) > len_) return false;
        if (hton) value = htonl(value);
        memcpy(buffer_ + write_pos_, &value, sizeof(value));
        write_pos_ += sizeof(value);
        return true;
    }
		
	/*
    inline uint64_t htonll(uint64_t host)
    {
        uint64_t net = (uint64_t)ntohl((int)host) << 32;
        net += ntohl((int)(host >> 32));

        return net;
    }
    inline uint64_t ntohll(uint64_t net)
    {
        uint64_t host = (uint64_t)ntohl((int)net) << 32;
        host += ntohl((int)(net >> 32));

        return host;
    }

    bool Read(int64_t & value, char ntoh = 1)
    {
        if (read_pos_ + sizeof(value) > len_) return false;
        memcpy(&value, buffer_ + read_pos_, sizeof(value));
        if (ntoh) value = ntohll(value);
        read_pos_ += sizeof(value);
        return true;
    }
    bool Write(int64_t value, char hton = 1)
    {
        if (write_pos_ + sizeof(value) > len_) return false;
        if (hton) value = htonll(value);
        memcpy(buffer_ + write_pos_, &value, sizeof(value));
        write_pos_ += sizeof(value);
        return true;
    }
    bool Read(uint64_t & value, char ntoh = 1)
    {
        if (read_pos_ + sizeof(value) > len_) return false;
        memcpy(&value, buffer_ + read_pos_, sizeof(value));
        if (ntoh) value = ntohll(value);
        read_pos_ += sizeof(value);
        return true;
    }
    bool Write(uint64_t value, char hton = 1)
    {
        if (write_pos_ + sizeof(value) > len_) return false;
        if (hton) value = htonll(value);
        memcpy(buffer_ + write_pos_, &value, sizeof(value));
        write_pos_ += sizeof(value);
        return true;
    }
	*/

    bool Read(void * value, size_t len)
    {
        if (read_pos_ + len > len_) return false;
        memcpy(value, buffer_ + read_pos_, len);
        read_pos_ += len;
        return true;
    }
    bool Write(const void * value, size_t len)
    {
        if (write_pos_ + len > len_) return false;
        memcpy(buffer_ + write_pos_, value, len);
        write_pos_ += len;
        return true;
    }

    bool Read(void ** value, size_t len)
    {
        if (read_pos_ + len > len_) return false;
        *value = buffer_ + read_pos_;
        read_pos_ += len;
        return true;
    }
private:
    size_t read_pos_;
    size_t write_pos_;
    char * buffer_;
    size_t len_;
};
#endif /* __NARUTO_DR_H__ */

