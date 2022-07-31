
#ifndef GUI_PAGE_H
#define GUI_PAGE_H


#include "stm32f4xx.h"
#include "GUI_label.h"
#include "GUI_button.h"


// ������ ��������
typedef struct
{
	uint8_t					ObjLabelNum;				// ���-�� �������
	uint8_t					ObjButtonNum;				// ���-�� ������
	Object_Label		*ObjLabelList;			// ������ �������
	Object_Button		*ObjButtonList;			// ������ ������
}Object_List_t;


typedef struct
{
  Object_List_t objList;
  void (*objActionFunc)(void);
}Page_t;


void GUI_setPage(uint8_t page);


#endif
