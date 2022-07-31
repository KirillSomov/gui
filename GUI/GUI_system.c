
#include "GUI_system.h"
#include "Touch_FT6236.h"


// очистка списка объектов
void	GUI_objectListReset(void)
{
	/*GUI.objList.ObjLabelNum 		= 0;
	GUI.objList.ObjButtonNum 		= 0;
	GUI.objList.ObjCanvasNum		= 0;*/
}

// получить координаты нажатия
void	GUI_getTouchPoint(void)
{
	//GUI.flag_touch = FT6236_checkInt();
	
	//GUI.flag_touch = 1;
	
	if(GUI.flag_touch)
	{
		FT6236_get_Tpoint(&FT6236_Tpoint);
		
		GUI.touchPoint.X = FT6236_Tpoint.Xt;
		GUI.touchPoint.Y = FT6236_Tpoint.Yt;
	}
}

// установить действия для объектов
void	GUI_objSetHandlerFunc(uint8_t page, void (*objActionFunc)(void))
{
  GUI.pages[page]->objActionFunc = objActionFunc;
}

// обработчик объетов
void	GUI_objHandler(void)
{
  GUI.pages[GUI.currentPage]->objActionFunc();
}

// обработчик нажатия на дисплей
void	GUI_Handler(int32_t dT)
{		
	//GUI_objHandler();
	
  uint8_t page = GUI.currentPage;
  Object_Button *button = &GUI.pages[page]->objList.ObjButtonList[0];
  uint8_t objButAmount = GUI.pages[page]->objList.ObjButtonNum;
  
	// Buttons press delay handling
	for(uint8_t objButNum = 0; objButNum < objButAmount; objButNum++)
	{	
		if (button[objButNum].timerVal > 0)
		{
			button[objButNum].timerVal -= dT;
		}
	}	
	
	if(GUI.flag_touch)
	{			
		GUI_getTouchPoint();
		GUI.flag_touch				=	0;
		for(uint8_t objButNum = 0; objButNum < objButAmount; objButNum++)
		{		
			if((GUI.touchPoint.X < button[objButNum].X0) || (GUI.touchPoint.X > button[objButNum].X1))
				continue;
			else if((GUI.touchPoint.Y < button[objButNum].Y0) || (GUI.touchPoint.Y > button[objButNum].Y1))
				continue;
			else
			{
				//if(GUI.objList.ObjButtonList[objButNum].flag_buttonWasClicked == 0)
				if(button[objButNum].timerVal <= 0)
				{
					button[objButNum].action();
					
					if(button[objButNum].msDelay != 0)
					{
						//GUI.objList.ObjButtonList[objButNum].flag_buttonWasClicked = 1;
						button[objButNum].timerVal = button[objButNum].msDelay;
					}
				}
				//GUI.flag_touch				=	0;
				return;
			}
		}
	}
  
	
	#ifdef OBJ_CANVAS_EN
		if(GUI.flag_touch)
		{
			for(uint8_t objCanvasNum = 0; objCanvasNum < OBJ_CANVAS_AMOUNT; objCanvasNum++)
			{
				if((GUI.touchPoint.X < GUI.objList.ObjCanvasList[objCanvasNum].X0) || (GUI.touchPoint.X > GUI.objList.ObjCanvasList[objCanvasNum].X1))
					continue;
				else if((GUI.touchPoint.Y < GUI.objList.ObjCanvasList[objCanvasNum].Y0) || (GUI.touchPoint.Y > GUI.objList.ObjCanvasList[objCanvasNum].Y1))
					continue;
				else
				{
					GUI_drawPoint(GUI.objList.ObjCanvasList[objCanvasNum].penWeight, GUI.objList.ObjCanvasList[objCanvasNum].penColor);
					
					if(GUI.objList.ObjCanvasList[objCanvasNum].action != 0)
						GUI.objList.ObjCanvasList[objCanvasNum].action();
					GUI.flag_touch				=	0;
					return;
				}
			}
		}
	#endif
}
