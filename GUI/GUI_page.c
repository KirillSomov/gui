
#include "GUI_page.h"
#include "GUI_system.h"
#include "LCD_ILI9341.h"


extern GUI_t GUI;


static void clearPage(void);
static void drawPage(void);


void clearPage(void)
{
  LCD_fill(0xBDD7);
}


void drawPage(void)
{
  clearPage();
  
  for (uint8_t label = 0; label < GUI.pages[GUI.currentPage]->objList.ObjLabelNum; label++)
  {
    GUI_drawLabel(GUI.currentPage, label);
  }
  for (uint8_t btn = 0; btn < GUI.pages[GUI.currentPage]->objList.ObjButtonNum; btn++)
  {
    GUI_drawButton(GUI.currentPage, btn);
  }
}


void GUI_setPage(uint8_t page)
{
  GUI.currentPage = page;
  drawPage();
}
