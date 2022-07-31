#ifndef PIXEL_MAP_H
#define PIXEL_MAP_H

#include "stdint.h"
#include "font.h"

typedef struct
{
	uint16_t W;
	uint16_t H;
	
	uint16_t *colors;
} PixelMap_t;

uint16_t PixelMap_getPixel(PixelMap_t *pixelMap, uint16_t x, uint16_t y);
void PixelMap_drawPixel(PixelMap_t *pixelMap, uint16_t x, uint16_t y, uint16_t color);
void PixelMap_drawFilledRectangle(PixelMap_t *pixelMap, uint16_t x0, uint16_t x1, uint16_t y0, uint16_t y1, uint16_t color);
void	PixelMap_drawFilledFrame(PixelMap_t *pixelMap,      // Pixel map
	                        uint16_t	X0,	uint16_t	X1,			// X-координаты
													uint16_t	Y0,	uint16_t	Y1,			// Y-координаты
													uint16_t	border,								// ширина рамки
													uint16_t	mainColor,						// основной цвет
													uint16_t	borderColor);					// цвет рамки

uint16_t	PixelMap_printChar(PixelMap_t *pixelMap, uint32_t x, uint32_t y, uint16_t symbol, uint16_t fontColor, const struct fontInfo *fontInfoStruct);
uint16_t	PixelMap_printString(PixelMap_t *pixelMap, uint32_t x, uint32_t y, char* str, uint16_t fontColor, const struct fontInfo *fontInfoStruct);

#endif //#ifndef PIXEL_MAP_H
