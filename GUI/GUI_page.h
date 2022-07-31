
#ifndef GUI_PAGE_H
#define GUI_PAGE_H


#include "stm32f4xx.h"
#include "GUI_label.h"
#include "GUI_button.h"


// список объектов
typedef struct
{
	uint8_t					ObjLabelNum;				// кол-во лейблов
	uint8_t					ObjButtonNum;				// кол-во кнопок
	Object_Label		*ObjLabelList;			// список лейблов
	Object_Button		*ObjButtonList;			// список кнопок
}Object_List_t;


typedef struct
{
  Object_List_t objList;
  void (*objActionFunc)(void);
}Page_t;


void GUI_setPage(uint8_t page);


#endif
