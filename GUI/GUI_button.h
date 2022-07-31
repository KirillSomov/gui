
#ifndef GUI_BUTTON_H
#define GUI_BUTTON_H


#include "stm32f4xx.h"
#include "Font.h"


// ��������� ������� ������
typedef struct
{
	uint16_t	X0;															// ���������� ������
	uint16_t	X1;
	uint16_t	Y0;
	uint16_t	Y1;
	uint16_t	border;													// ������ ������
	uint16_t	mainColor;											// ���� ������
	uint16_t	borderColor;										// ���� ������
	char			*str;														// �����
	const struct fontInfo *fontInfoStruct;		// �����
	uint16_t	textColor;											// ���� ������
	uint16_t	textMarginX;										// ������ ������ �� X
	uint16_t	textMarginY;										// ������ ������ �� Y
	uint8_t		state;													//
	volatile	int32_t	msDelay;							  // �������� �� ���������� �������
	
	uint16_t	textLenght;											//
	uint8_t		flag_buttonWasClicked;					// 
	int32_t 	timerVal;												// 
	
	// �������� �� ������� ������
	void (*action)(void);		
}Object_Button;


void	GUI_drawButton(uint8_t page, uint8_t	buttonNum);
void	GUI_createButton(uint8_t page,
                      uint16_t	X0,	uint16_t	X1,			// X-���������� ������	// ������� ������
											uint16_t	Y0,	uint16_t	Y1,			// Y-���������� ������
											uint16_t	border,								// ������ ������
											uint16_t	mainColor,						// �������� ���� ������
											uint16_t	borderColor,					// ���� ������
											char			*str,									// �����
											uint16_t	textColor,						// ���� ������
					const struct fontInfo *fontInfoStruct,			// �����
											uint16_t	textMarginX,					// ������ ������ �� X
											uint16_t	textMarginY,					// ������ ������ �� Y											
											uint8_t		state,								//
											uint16_t	msDelay,							// �������� �� ���������� �������
											void			(*action)(void));			// ������� ���������� � ������
void	GUI_buttonChangeText(uint8_t page,
                            uint8_t	buttonNum,
															char	*str,
													uint16_t	textColor,
							const struct fontInfo *fontInfoStruct);	// ������� ����� ������
void	GUI_buttonChangeMainColor(uint8_t page,
                                uint8_t	buttonNum,
															uint16_t	mainColor);		// ������� ���� ������
 
 
#endif
