#ifndef CTEXT
#define CTEXT
#include "CTexture.h"

/*
�����̕`��
*/
class CText {
public:
	//�e�N�X�`���̎w��
	static CTexture mFont;
	CText() {
		if (mFont.mId == 0) {
			mFont.Load("font.tga");
		}
	}
	//�����̕`��
	static void DrawChar(char ch, int x, int y, int w, int h);
	//
	static void DrawString(char *s, int x, int y, int w, int h);
};
#endif