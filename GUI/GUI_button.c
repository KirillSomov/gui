
#include "GUI_button.h"
#include "GUI_system.h"
#include "GUI_page.h"
#include "GUI_print.h"
#include "LCD_ILI9341.h"


extern GUI_t GUI;


void GUI_drawButton(uint8_t page, uint8_t buttonNum)
{
  Object_Button *btn = &GUI.pages[page]->objList.ObjButtonList[buttonNum];
  
 	GUI_drawFilledFrame(btn->X0, btn->X1, btn->Y0, btn->Y1, btn->border, btn->mainColor, btn->borderColor);		// отрисовка кнопки
	
	if(btn->str != 0)
		btn->textLenght = LCD_printString(btn->X0+btn->textMarginX, btn->Y0+btn->textMarginY, btn->str, btn->textColor, btn->fontInfoStruct);
	else
		btn->textLenght = 0;
}


// создать кнопку
void	GUI_createButton(uint8_t page,
                      uint16_t	X0,	uint16_t	X1,			// X-координаты кнопки
											uint16_t	Y0,	uint16_t	Y1,			// Y-координаты кнопки
											uint16_t	border,								// ширина границ
											uint16_t	mainColor,						// основной цвет кнопки
											uint16_t	borderColor,					// цвет границ
											char			*str,									// текст
											uint16_t	textColor,						// цвет текста
					const struct fontInfo *fontInfoStruct,			// шрифт
											uint16_t	textMarginX,					// отступ текста по X
											uint16_t	textMarginY,					// отступ текста по Y											
											uint8_t		state,
											uint16_t	msDelay,							// задержка до следующего нажатия
											void			(*action)(void))			// функция привязаная к кнопке
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
	
	GUI.pages[page]->objList.ObjButtonNum++;	// инкрементирование индекса для следующего объекта
}

// сменить текст кнопки
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
											0);																							// закркасить старый цвет
	
	if(str != 0)
		btn->textLenght = LCD_printString(btn->X0+btn->textMarginX,
																			btn->Y0+btn->textMarginY,
																			str, textColor, fontInfoStruct);
}

// сменить цвет кнопки
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
											btn->borderColor);					// закркасить старый цвет
	
	if(btn->str != 0)
		GUI_buttonChangeText(page, buttonNum, btn->str, btn->textColor, btn->fontInfoStruct);
}
