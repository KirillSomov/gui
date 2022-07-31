
#include "GUI_label.h"
#include "GUI_system.h"
#include "GUI_page.h"
#include "GUI_print.h"
#include "LCD_ILI9341.h"


extern GUI_t GUI;


void	GUI_drawLabel(uint8_t page, uint8_t	labelNum)
{
  Object_Label *label = &GUI.pages[page]->objList.ObjLabelList[labelNum];  
  
	GUI_drawFilledFrame(label->X0, label->X1, label->Y0, label->Y1, label->border, label->mainColor, label->borderColor);		// ��������� ������
	
	if(label->str != 0)
		label->textLenght = LCD_printString(label->X0+label->textMarginX, label->Y0+label->textMarginY, label->str, label->textColor, label->fontInfoStruct);
	else
		label->textLenght = 0;
}


// ������� �����
void	GUI_createLabel(uint8_t page,
                      uint16_t	X0,	uint16_t	X1,			// X-����������	// ������� �����
											uint16_t	Y0,	uint16_t	Y1,			// Y-����������
											uint16_t	border,								// ������ ������
											uint16_t	mainColor,						// �������� ����
											uint16_t	borderColor,					// ���� ������
											char			*str,									// �����
											uint16_t	textColor,						// ���� ������
					const struct fontInfo *fontInfoStruct,			// �����
											uint16_t	textMarginX,					// ������ ������ �� X
											uint16_t	textMarginY,					// ������ ������ �� Y
											void			(*action)(void))			// ������� ���������� � ������
{
  Object_Label *label = &GUI.pages[page]->objList.ObjLabelList[GUI.pages[page]->objList.ObjLabelNum];
  
	label->X0	=	X0;
	label->X1	=	X1;
	label->Y0	=	Y0;
	label->Y1	=	Y1;
	label->border					=	border;
	label->mainColor				=	mainColor;
	label->borderColor			=	borderColor;
	label->str							=	str;
	label->textColor				=	textColor;
	label->fontInfoStruct	=	fontInfoStruct;
	label->textMarginX			=	textMarginX;
	label->textMarginY			=	textMarginY;
	label->action					=	action;
	
	GUI.pages[page]->objList.ObjLabelNum++;	// ����������������� ������� ��� ���������� �������
}


// ������� ����� ������
void	GUI_labelChangeText(uint8_t page, uint8_t labelNum, char *str, uint16_t	textColor, const struct fontInfo *fontInfoStruct)
{
  Object_Label *label = &GUI.pages[page]->objList.ObjLabelList[GUI.pages[page]->objList.ObjLabelNum];
  
	label->str 						= str;
	label->textColor			=	textColor;
	label->fontInfoStruct	=	fontInfoStruct;
	
	PixelMap_t pixelMap;
	pixelMap.W = 100;
	pixelMap.H = 25;
	static uint16_t colors[25 * 100];
	pixelMap.colors = colors;
	
	PixelMap_drawFilledFrame(&pixelMap,
	                    0,
											pixelMap.W - 1,
											0,
											pixelMap.H - 1,
											0,
											label->mainColor,
											0);																						// ���������� ������ ����
	
	uint16_t prev_textLength = label->textLenght;
	if(str != 0)
	{
		label->textLenght = PixelMap_printString(&pixelMap, 0, 0, str, textColor, fontInfoStruct);
		label->textLenght += label->X0
                       + label->textMarginX;
	}
	
	LCD_drawPixelMap(&pixelMap,
	                 label->X0+label->textMarginX,
	                (label->textLenght > prev_textLength) ? label->textLenght : prev_textLength,
	                 label->Y0+label->textMarginY,
	                 label->Y0+label->textMarginY+24);   //Draw pixel map to display
	
																						// ���������� ������ ����
	
//	GUI_drawFilledFrame(GUI.objList.ObjLabelList[labelNum].X0+GUI.objList.ObjLabelList[labelNum].textMarginX,
//											GUI.objList.ObjLabelList[labelNum].textLenght,
//											GUI.objList.ObjLabelList[labelNum].Y0+GUI.objList.ObjLabelList[labelNum].textMarginY,
//											GUI.objList.ObjLabelList[labelNum].Y0+GUI.objList.ObjLabelList[labelNum].textMarginY+24,
//											0,
//											GUI.objList.ObjLabelList[labelNum].mainColor,
//											0);	
	
//	if(str != 0)
//		GUI.objList.ObjLabelList[labelNum].textLenght = LCD_printString(GUI.objList.ObjLabelList[labelNum].X0+GUI.objList.ObjLabelList[labelNum].textMarginX,
//																																GUI.objList.ObjLabelList[labelNum].Y0+GUI.objList.ObjLabelList[labelNum].textMarginY,
//																																str, textColor, fontInfoStruct);
}

// ������� ���� ������
void	GUI_labelChangeMainColor(uint8_t page, uint8_t labelNum, uint16_t	mainColor)
{
  Object_Label *label = &GUI.pages[page]->objList.ObjLabelList[GUI.pages[page]->objList.ObjLabelNum];
  
	label->mainColor = mainColor;
	
	GUI_drawFilledFrame(label->X0,
											label->X1,
											label->Y0,
											label->Y1,
											label->border,
											label->mainColor,
											label->borderColor);					// ���������� ������ ����
	
	if(label->str != 0)
		GUI_labelChangeText(page, labelNum, label->str,
                        label->textColor,
                        label->fontInfoStruct);
}
