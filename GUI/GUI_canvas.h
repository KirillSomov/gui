
#ifndef GUI_CANVAS_H
#define GUI_CANVAS_H


#include "stm32f4xx.h"


// толщина пера
typedef enum
{
	Pen_fine	=	0,
	Pen_small,
	Pen_medium,
	Pen_broad,
	Pen_extraBroad
}Pen_Weight;
 

// структура объекта холст
typedef struct
{
	uint16_t		X0;						// координаты холста
	uint16_t		X1;
	uint16_t		Y0;
	uint16_t		Y1;
	uint16_t		border;				// ширина границ
	uint16_t		mainColor;		// цвет холста
	uint16_t		borderColor;	// цвет границ
	uint16_t		penColor;			// цвет пера
	Pen_Weight	penWeight;		// толщина пера
	
	// действие по нажатию на поле холста
	void (*action)(void);
}Object_Canvas;
 
 
void	GUI_createCanvas(uint8_t page,
                      uint16_t		X0,	uint16_t	X1,			// X-координаты кнопки	// создать холст
											uint16_t		Y0,	uint16_t	Y1,			// Y-координаты кнопки
											uint16_t		border,								// ширина границ
											uint16_t		mainColor,						// основной цвет холста
											uint16_t		borderColor,					// цвет границ
											Pen_Weight	penWeight,						// толщина пера
											uint16_t		penColor,							// цвет пера
											void				(*action)(void));			// функция привязаная к холсту
void	GUI_canvasClear(uint8_t page, uint8_t canvasNum);								// очистить холст
void	GUI_canvasChangePenColor(uint8_t page,
                                uint8_t	canvasNum,
															uint16_t	newPenColor);		// сменить цвет пера холста
void	GUI_canvasSetPenEraser(uint8_t page, uint8_t	canvasNum);				//
void	GUI_canvasDrawPoint(uint8_t page,
                            Pen_Weight	penWeight,
														uint16_t	pointColor);			// поставить точку на холсте


#endif
