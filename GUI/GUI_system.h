
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


// ��������� �������
void	GUI_objectListReset(void);													// ������� ������ ��������
void	GUI_getTouchPoint(void);														// �������� ���������� �������
void	GUI_objSetHandlerFunc(uint8_t page, void (*objActionFunc)(void));	// ���������� �������� ��� ��������
void	GUI_objHandler(void);																// ���������� �������
void	GUI_Handler(int32_t dT);															// ���������� ������� �� �������


#endif
