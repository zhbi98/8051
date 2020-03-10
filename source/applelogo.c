
#include "applelogo.h"

unsigned char code page2[32] = {
	0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,
	0xf0,0x7c,0x3e,0x3f,0x9f,0x87,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00};

unsigned char code page3[32] = {
	0x00,0x00,0xf8,0xfe,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xfc,
	0xfe,0xfe,0xfe,0xff,0xff,0xff,0xff,0xff,0xff,0x1f,0x0f,0x07,0x07,0x00,0x00,0x00};

unsigned char code page4[32] = {
	0x00,0x00,0x07,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0xe0,0xc0,0xc0,0x80,0x00,0x00};

unsigned char code page5[32] = {
	0x00,0x00,0x00,0x00,0x01,0x07,0x1f,0x3f,0x7f,0x7f,0x7f,0x7f,0x3f,0x3f,0x1f,0x1f,
	0x1f,0x3f,0x03f,0x7f,0x7f,0x7f,0x7f,0x7f,0x3f,0x1f,0x0f,0x07,0x03,0x00,0x00,0x00};

void display_logo()
{
	unsigned char x;

	write_command(0xb0 + 2);
	write_command(((48 & 0xf0) >> 4) | 0x10);
	write_command((48 & 0x0f) | 0x01);
	for (x = 0; x < 32; x++)
		write_data(page2[x]);

	write_command(0xb0 + 3);
	write_command(((48 & 0xf0) >> 4) | 0x10);
	write_command((48 & 0x0f) | 0x01);
	for (x = 0; x < 32; x++)
		write_data(page3[x]);

	write_command(0xb0 + 4);
	write_command(((48 & 0xf0) >> 4) | 0x10);
	write_command((48 & 0x0f) | 0x01);
	for (x = 0; x < 32; x++)
		write_data(page4[x]);

	write_command(0xb0 + 5);
	write_command(((48 & 0xf0) >> 4) | 0x10);
	write_command((48 & 0x0f) | 0x01);
	for (x = 0; x < 32; x++)
		write_data(page5[x]);
	sleep_ms(30000);
	clean(0x00);
}