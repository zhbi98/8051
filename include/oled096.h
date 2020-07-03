
#ifndef __OLED096_H__
#define __OLED096_H__

#include <reg52.h>
#include <stdio.h>
#include <stdarg.h>

#include "fontlib.h"
#include "time.h"

#define white 0
#define black 1

sbit d0 = P2^0;  //sclk
sbit d1 = P2^1;  //mosi
sbit rs = P2^2;
sbit dc = P2^3;
sbit cs = P2^4;

// oled 0.96 display video memory
extern unsigned char oled_vm[];

extern void oled096_send_bit(bit a_bit);
extern void oled096_send_byte(unsigned char a_byte);
extern void write_command(unsigned char command);
extern void write_data(unsigned char dat_a);
extern void clean(unsigned char dat_a);
extern void oled096_init();
extern void display_on();
extern void display_off();
extern void display_pixel(unsigned char y, unsigned char x, unsigned char color, unsigned char vm[]);
extern void send_display_memory(unsigned char vm[]);
extern void display_position(unsigned char y, unsigned char x);
extern void display_character(unsigned char y, unsigned char x, unsigned char character);
extern void display_string(unsigned char y, unsigned char x, const unsigned char * string);
extern void display_value(unsigned char y, unsigned char x, unsigned char *format, ...);
extern void display_bevel_rectangle(unsigned char y, unsigned char x, unsigned char width, unsigned char height, unsigned char radian, unsigned char vm[]);

#endif
