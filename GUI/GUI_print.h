
#ifndef GUI_PRINT_H
#define GUI_PRINT_H


#include "stm32f4xx.h"
#include "pixel_map.h"


void	GUI_intToStr(int32_t num, char *strBuf);					//
void	GUI_floatToStr(float num, char *strBuf);					//

void	GUI_drawFrame(uint16_t	X0,	uint16_t	X1,					// X-координаты объекта	// отрисовка границ объекта
										uint16_t	Y0,	uint16_t	Y1,					// Y-координаты объекта
										uint16_t	border,										// ширина границ
										uint16_t	borderColor);							// цвет гнраниц
void	GUI_drawFilledFrame(uint16_t	X0,	uint16_t	X1,		// X-координаты объекта	// отрисовка границ объекта
													uint16_t	Y0,	uint16_t	Y1,		// Y-координаты объекта
													uint16_t	border,							// ширина границ
													uint16_t	mainColor,					// основной цвет
													uint16_t	borderColor);				// цвет гнраниц
void	GUI_drawPicture(uint16_t	X0,											// X-координаты объекта	// отрисовка картинки
											uint16_t	Y0,											// Y-координаты объекта
											uint16_t	border,									// ширина границ
											uint16_t	pictureColor,						// основной цвет
											uint16_t	borderColor,						// цвет границ
											uint16_t	*picture);							// указатель на картинку
 
uint16_t PixelMap_getPixel(PixelMap_t *pixelMap, uint16_t x, uint16_t y);


#endif
