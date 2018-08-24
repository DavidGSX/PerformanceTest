#ifndef __aes_ecb_H__
#define __aes_ecb_H__
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <string>
#include <stdlib.h>

#pragma once
class aes_ecb
{
public:
	aes_ecb();
	~aes_ecb();
	static aes_ecb * Instance();
    std::string Encrypt(uint32_t id);
	uint32_t Decrypt(std::string sid);
private:
	void phex(uint8_t* str);
	void bin2hex(uint8_t* bin, char* hex);
	void hex2bin(const char* hex, uint8_t* bin);
	void Pad2Length(char* str, int pad_len);
	
};
#endif