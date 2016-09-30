#ifndef NIXIETUBE_H_
#define NIXIETUBE_H_

#include "Arduino.h"

enum Color
{
	White, Yellow, Cyan, Green,
	Magenta, Red, Blue, Black,
};

enum Colon
{
	None, Upper, Lower, Both
};

class NixieTube
{

public:
	NixieTube(uint8_t pin_din, uint8_t pin_st, uint8_t pin_sh, uint8_t pin_oe,
			byte section_count = 1);
	// set section_count to how many the sections plugged in the chain, default value is 1

	virtual ~NixieTube();

	void clear(word value = 0x7000);

	void putWord(byte index, word value = 0x7000);
	// Test function

	void setBrightness(byte brightness = 0x40);
	void display();

	void setBackgroundColor(Color color);
	void setBackgroundColor(byte index, Color color);

	void setNumber(byte num);
	void setNumber(byte index, byte num);

	void setColon(byte index, Colon colon);
	void setColon(Colon colon);

	void printf(const char *__fmt, ...);


private:

	word *_buff;
	char * _cache;

	const uint8_t _pin_dt; // DIN, #1
	const uint8_t _pin_st; // STCP, #2
	const uint8_t _pin_sh; // SHCP, #3
	const uint8_t _pin_oe; // OE,	 #4, PWM strongly recommended
	const byte _section_count;

	byte _cache_length;

	void send(byte data) const;
	bool isNumber(char c);
	bool isColon(char);
	void putCache();

	Colon getColon(char c);
};

#endif /* NIXIETUBE_H_ */
