
#ifndef GUI_SYSTEM_H
#define GUI_SYSTEM_H


#include "stm32f4xx.h"
#include "GUI_page.h"


typedef	struct
{
	uint16_t	X;
	uint16_t	Y;
}tPoint_t;


typedef	struct
{
	uint8_t flag_touch;
	tPoint_t touchPoint;
  uint8_t currentPage;
  Page_t **pages;
}GUI_t;


extern GUI_t GUI;


// прототипы функций
void	GUI_objectListReset(void);													// очистка списка объектов
void	GUI_getTouchPoint(void);														// получить координаты нажатия
void	GUI_objSetHandlerFunc(uint8_t page, void (*objActionFunc)(void));	// установить действия для объектов
void	GUI_objHandler(void);																// обработчик объетов
void	GUI_Handler(int32_t dT);															// обработчик нажатия на дисплей


#endif
