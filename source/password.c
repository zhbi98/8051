
#include "password.h"

unsigned char password(unsigned char password[8])
{
	unsigned char passwd[8];
	unsigned char input = 0, compare = 0;

	display_string(1, 4, "���");
	display_string(4, 1, "����Ļ��ť�Խ���");
	
	while (read_keyboard() != '*');
	delete_content();
	sleep_ms(50);

	display_string(1, 3, "��������");
	display_string(3, 3, "--------");
	display_position(3, 3);
	while (input < 8) {
		if (read_keyboard() != 0) {
			sleep_ms(20);
			passwd[input] = read_keyboard();
			write_data(0x07);
			sleep_ms(100);
			input++;
		}
	}
	for (compare = 0; compare < 8; compare++) {
		if (passwd[compare] != password[compare]) {
			delete_content();
			display_string(1, 3, "�������");
			display_string(3, 3, "�Ժ�����");
			passwd[8] = 0;
			sleep_ms(1000);
			delete_content();	
			return 1;	
		}
	}
	passwd[8] = 0;
	sleep_ms(10);
	return 0;
}
