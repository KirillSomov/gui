
#include "GUI_button.h"
#include "GUI_system.h"
#include "GUI_page.h"
#include "GUI_print.h"
#include "LCD_ILI9341.h"


extern GUI_t GUI;


void GUI_drawButton(uint8_t page, uint8_t buttonNum)
{
  Object_Button *btn = &GUI.pages[page]->objList.ObjButtonList[buttonNum];
  
 	GUI_drawFilledFrame(btn->X0, btn->X1, btn->Y0, btn->Y1, btn->border, btn->mainColor, btn->borderColor);		// ��������� ������
	
	if(btn->str != 0)
		btn->textLenght = LCD_printString(btn->X0+btn->textMarginX, btn->Y0+btn->textMarginY, btn->str, btn->textColor, btn->fontInfoStruct);
	else
		btn->textLenght = 0;
}


// ������� ������
void	GUI_createButton(uint8_t page,
                      uint16_t	X0,	uint16_t	X1,			// X-���������� ������
											uint16_t	Y0,	uint16_t	Y1,			// Y-���������� ������
											uint16_t	border,								// ������ ������
											uint16_t	mainColor,						// �������� ���� ������
											uint16_t	borderColor,					// ���� ������
											char			*str,									// �����
											uint16_t	textColor,						// ���� ������
					const struct fontInfo *fontInfoStruct,			// �����
											uint16_t	textMarginX,					// ������ ������ �� X
											uint16_t	textMarginY,					// ������ ������ �� Y											
											uint8_t		state,
											uint16_t	msDelay,							// �������� �� ���������� �������
											void			(*action)(void))			// ������� ���������� � ������
{
  Object_Button *btn = &GUI.pages[page]->objList.ObjButtonList[GUI.pages[page]->objList.ObjButtonNum];
  
	btn->X0	=	X0;
	btn->X1	=	X1;
	btn->Y0	=	Y0;
	btn->Y1	=	Y1;
	btn->border							=	border;
	btn->mainColor						=	mainColor;
	btn->borderColor					=	borderColor;
	btn->str									=	str;
	btn->textColor						=	textColor;
	btn->fontInfoStruct			=	fontInfoStruct;
	btn->textMarginX					=	textMarginX;
	btn->textMarginY					=	textMarginY;
	btn->state								=	state;
	btn->msDelay							=	msDelay;
	btn->flag_buttonWasClicked	= 0;
	btn->timerVal 						= 0;
	btn->action							=	action;
	
	GUI.pages[page]->objList.ObjButtonNum++;	// ����������������� ������� ��� ���������� �������
}

// ������� ����� ������
void	GUI_buttonChangeText(uint8_t page, uint8_t buttonNum, char *str, uint16_t	textColor, const struct fontInfo *fontInfoStruct)
{
  Object_Button *btn = &GUI.pages[page]->objList.ObjButtonList[GUI.pages[page]->objList.ObjButtonNum];
  
	btn->str 					  = str;
	btn->textColor			=	textColor;
	btn->fontInfoStruct	=	fontInfoStruct;
	
	GUI_drawFilledFrame(btn->X0+btn->textMarginX,
											btn->textLenght,
											btn->Y0+btn->textMarginY,
											btn->Y0+btn->textMarginY+24,
											0,
											btn->mainColor,
											0);																							// ���������� ������ ����
	
	if(str != 0)
		btn->textLenght = LCD_printString(btn->X0+btn->textMarginX,
																			btn->Y0+btn->textMarginY,
																			str, textColor, fontInfoStruct);
}

// ������� ���� ������
void	GUI_buttonChangeMainColor(uint8_t page, uint8_t buttonNum, uint16_t	mainColor)
{
  Object_Button *btn = &GUI.pages[page]->objList.ObjButtonList[GUI.pages[page]->objList.ObjButtonNum];
  
	btn->mainColor = mainColor;
	
	GUI_drawFilledFrame(btn->X0,
											btn->X1,
											btn->Y0,
											btn->Y1,
											btn->border,
											btn->mainColor,
											btn->borderColor);					// ���������� ������ ����
	
	if(btn->str != 0)
		GUI_buttonChangeText(page, buttonNum, btn->str, btn->textColor, btn->fontInfoStruct);
}
