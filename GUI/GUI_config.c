
#include "stm32f4xx.h"
#include "GUI_config.h"
#include "GUI_system.h"
#include "GUI_page.h"
#include "GUI_label.h"
#include "GUI_button.h"


pageStorageCreate(0, 11, 5);
pageStorageCreate(1, 9, 4);
pageStorageCreate(2, 3, 6);

pagesStorageCreate(3);

guiStorageCreate();


void GUI_pagesStorageInit(void)
{
  GUI.pages[0] = &page_0;
  GUI.pages[1] = &page_1;
  GUI.pages[2] = &page_2;
}
