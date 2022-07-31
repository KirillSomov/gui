
#ifndef GUI_LABEL_H
#define GUI_LABEL_H


#include "stm32f4xx.h"
#include "Font.h"


// структура объекта лейбл
typedef struct
{
	uint16_t	X0;															// координаты кнопки
	uint16_t	X1;
	uint16_t	Y0;
	uint16_t	Y1;
	uint16_t	border;													// ширина границ
	uint16_t	mainColor;											// цвет фона
	uint16_t	borderColor;										// цвет границ
	char			*str;														// текст
	const struct fontInfo *fontInfoStruct;		// шрифт
	uint16_t	textColor;											// цвет текста
	uint16_t	textMarginX;										// отступ текста по X
	uint16_t	textMarginY;										// отступ текста по Y
	void 			(*action)(void);								// действие
	
	uint16_t	textLenght;
}Object_Label;


void	GUI_drawLabel(uint8_t page, uint8_t	labelNum);
void	GUI_createLabel(uint8_t page,
                      uint16_t	X0,	uint16_t	X1,			// X-координаты	// создать лейбл
											uint16_t	Y0,	uint16_t	Y1,			// Y-координаты
											uint16_t	border,								// ширина границ
											uint16_t	mainColor,						// основной цвет
											uint16_t	borderColor,					// цвет границ
											char			*str,									// текст
											uint16_t	textColor,						// цвет текста
					const struct fontInfo *fontInfoStruct,			// шрифт
											uint16_t	textMarginX,					// отступ текста по X
											uint16_t	textMarginY,					// отступ текста по Y
											void			(*action)(void));			// функция привязаная к лейблу
void	GUI_labelChangeText(uint8_t page,
                          uint8_t	labelNum,
														char	*str,
												uint16_t	textColor,
						const struct fontInfo *fontInfoStruct);					// сменить текст лейбла
void	GUI_labelChangeMainColor(uint8_t page,
                              uint8_t	labelNum,
															uint16_t	mainColor);		// сменить цвет лейбла


#endif
