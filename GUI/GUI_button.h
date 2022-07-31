
#ifndef GUI_BUTTON_H
#define GUI_BUTTON_H


#include "stm32f4xx.h"
#include "Font.h"


// структура объекта кнопка
typedef struct
{
	uint16_t	X0;															// координаты кнопки
	uint16_t	X1;
	uint16_t	Y0;
	uint16_t	Y1;
	uint16_t	border;													// ширина границ
	uint16_t	mainColor;											// цвет кнопки
	uint16_t	borderColor;										// цвет границ
	char			*str;														// текст
	const struct fontInfo *fontInfoStruct;		// шрифт
	uint16_t	textColor;											// цвет текста
	uint16_t	textMarginX;										// отступ текста по X
	uint16_t	textMarginY;										// отступ текста по Y
	uint8_t		state;													//
	volatile	int32_t	msDelay;							  // задержка до следующего нажатия
	
	uint16_t	textLenght;											//
	uint8_t		flag_buttonWasClicked;					// 
	int32_t 	timerVal;												// 
	
	// действие по нажатию кнопки
	void (*action)(void);		
}Object_Button;


void	GUI_drawButton(uint8_t page, uint8_t	buttonNum);
void	GUI_createButton(uint8_t page,
                      uint16_t	X0,	uint16_t	X1,			// X-координаты кнопки	// создать кнопку
											uint16_t	Y0,	uint16_t	Y1,			// Y-координаты кнопки
											uint16_t	border,								// ширина границ
											uint16_t	mainColor,						// основной цвет кнопки
											uint16_t	borderColor,					// цвет границ
											char			*str,									// текст
											uint16_t	textColor,						// цвет текста
					const struct fontInfo *fontInfoStruct,			// шрифт
											uint16_t	textMarginX,					// отступ текста по X
											uint16_t	textMarginY,					// отступ текста по Y											
											uint8_t		state,								//
											uint16_t	msDelay,							// задержка до следующего нажатия
											void			(*action)(void));			// функция привязаная к кнопке
void	GUI_buttonChangeText(uint8_t page,
                            uint8_t	buttonNum,
															char	*str,
													uint16_t	textColor,
							const struct fontInfo *fontInfoStruct);	// сменить текст кнопки
void	GUI_buttonChangeMainColor(uint8_t page,
                                uint8_t	buttonNum,
															uint16_t	mainColor);		// сменить цвет кнопки
 
 
#endif
