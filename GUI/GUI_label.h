
#ifndef GUI_LABEL_H
#define GUI_LABEL_H


#include "stm32f4xx.h"
#include "Font.h"


// ��������� ������� �����
typedef struct
{
	uint16_t	X0;															// ���������� ������
	uint16_t	X1;
	uint16_t	Y0;
	uint16_t	Y1;
	uint16_t	border;													// ������ ������
	uint16_t	mainColor;											// ���� ����
	uint16_t	borderColor;										// ���� ������
	char			*str;														// �����
	const struct fontInfo *fontInfoStruct;		// �����
	uint16_t	textColor;											// ���� ������
	uint16_t	textMarginX;										// ������ ������ �� X
	uint16_t	textMarginY;										// ������ ������ �� Y
	void 			(*action)(void);								// ��������
	
	uint16_t	textLenght;
}Object_Label;


void	GUI_drawLabel(uint8_t page, uint8_t	labelNum);
void	GUI_createLabel(uint8_t page,
                      uint16_t	X0,	uint16_t	X1,			// X-����������	// ������� �����
											uint16_t	Y0,	uint16_t	Y1,			// Y-����������
											uint16_t	border,								// ������ ������
											uint16_t	mainColor,						// �������� ����
											uint16_t	borderColor,					// ���� ������
											char			*str,									// �����
											uint16_t	textColor,						// ���� ������
					const struct fontInfo *fontInfoStruct,			// �����
											uint16_t	textMarginX,					// ������ ������ �� X
											uint16_t	textMarginY,					// ������ ������ �� Y
											void			(*action)(void));			// ������� ���������� � ������
void	GUI_labelChangeText(uint8_t page,
                          uint8_t	labelNum,
														char	*str,
												uint16_t	textColor,
						const struct fontInfo *fontInfoStruct);					// ������� ����� ������
void	GUI_labelChangeMainColor(uint8_t page,
                              uint8_t	labelNum,
															uint16_t	mainColor);		// ������� ���� ������


#endif
