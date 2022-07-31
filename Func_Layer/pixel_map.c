#include "pixel_map.h"

uint16_t PixelMap_getPixel(PixelMap_t *pixelMap, uint16_t x, uint16_t y)
{
	if ( x >= (pixelMap->W) )
		return 0;
	else if ( y >= (pixelMap->H) )
		return 0;
	else
		return pixelMap->colors[y * (pixelMap->W) + x];
}

// отрисовка пикселя
void PixelMap_drawPixel(PixelMap_t *pixelMap, uint16_t x, uint16_t y, uint16_t color)
{
	if ( x < (pixelMap->W) )
		if ( y < (pixelMap->H) )
			pixelMap->colors[y * (pixelMap->W) + x] = color;
}

// закрасить область
void PixelMap_drawFilledRectangle(PixelMap_t *pixelMap, uint16_t x0, uint16_t x1, uint16_t y0, uint16_t y1, uint16_t color)
{
//	x0--;
//	x1--;
//	y0--;
//	y1--;
//	
//	uint16_t tempCoor = y0;
//	
//	y0 = (pixelMap->H-1) - y1;
//	y1 = (pixelMap->H-1) - tempCoor;

	for(uint16_t i=0; i<=(y1-y0); i++)
	{
		for(uint16_t j=0; j<=(x1-x0); j++)
		{
			PixelMap_drawPixel(pixelMap, j, i, color);
		}
	}
}

// отрисовка заполненной рамки
void	PixelMap_drawFilledFrame(PixelMap_t *pixelMap,      // Pixel map
	                        uint16_t	X0,	uint16_t	X1,			// X-координаты
													uint16_t	Y0,	uint16_t	Y1,			// Y-координаты
													uint16_t	border,								// ширина рамки
													uint16_t	mainColor,						// основной цвет
													uint16_t	borderColor)					// цвет рамки
{
	PixelMap_drawFilledRectangle(pixelMap, X0, X1, Y0, Y1, mainColor);
	// отрисовка рамки
	if(border > 0)
	{
		PixelMap_drawFilledRectangle(pixelMap, X0, X0+(border-1), Y0, Y1, borderColor);
		PixelMap_drawFilledRectangle(pixelMap, X0, X1, Y1-(border-1), Y1, borderColor);
		PixelMap_drawFilledRectangle(pixelMap, X1-(border-1), X1, Y0, Y1, borderColor);
		PixelMap_drawFilledRectangle(pixelMap, X0, X1, Y0, Y0+(border-1), borderColor);
	}
}

uint16_t	PixelMap_printChar(PixelMap_t *pixelMap, uint32_t x, uint32_t y, uint16_t symbol, uint16_t fontColor, const struct fontInfo *fontInfoStruct)
{	
	uint8_t		i							=	0;
	uint16_t	symbolWidth		=	0;
	uint16_t	symbolHeight	=	0;
	uint16_t	symbolOffset	=	0;
	uint8_t		symbolByte		=	0;
	
	if(symbol >= fontInfoStruct->startChar && symbol <= fontInfoStruct->endChar)
	{
		for(uint16_t fontDescptrBlockNum = 0; fontDescptrBlockNum < fontInfoStruct->charBlockArrayAmount; fontDescptrBlockNum++)
		{
			if(symbol >= fontInfoStruct->fontCharInfoLookupArray[fontDescptrBlockNum].startChar && symbol <= fontInfoStruct->fontCharInfoLookupArray[fontDescptrBlockNum].endChar)
			{
				symbolOffset	=	fontInfoStruct->fontCharInfoLookupArray[fontDescptrBlockNum].startChar;
				symbolWidth		=	fontInfoStruct->fontCharInfoLookupArray[fontDescptrBlockNum].descriptorsBlockArray[symbol - symbolOffset][0];
				symbolHeight	=	fontInfoStruct->fontCharInfoLookupArray[fontDescptrBlockNum].descriptorsBlockArray[symbol - symbolOffset][1];
				
				for(uint8_t width = 0; width < symbolWidth; width++)
				{
					i = 0;
					for(uint8_t height = symbolHeight; height > 0; height--)
					{
						symbolByte = fontInfoStruct->charBitmapArray[fontInfoStruct->fontCharInfoLookupArray[fontDescptrBlockNum].descriptorsBlockArray[symbol - symbolOffset][2] + width + i*symbolWidth];
						for(uint8_t byte = 0; byte < 8; byte++)
						{
							if(symbolByte & (1 << byte))
								PixelMap_drawPixel(pixelMap, x, (y + height*8 - byte), fontColor);
						}
						i++;
					}
					x++;
				}
				
				return x;
			}
		}
	}
	
	return x;
}

uint16_t	PixelMap_printString(PixelMap_t *pixelMap, uint32_t x, uint32_t y, char* str, uint16_t fontColor, const struct fontInfo *fontInfoStruct)
{
//	x--;
//	y--;
	
	uint16_t symbol = 0;	// код ascii символа
	
	//y = (LCD_HEIGHT-1) - y;
	while(*str)
	{
		symbol = *str++;
		
		// пробел
		if(symbol == ' ')
		{
			x = x + 6;
		}
		
		x = PixelMap_printChar(pixelMap, x, y, symbol, fontColor, fontInfoStruct);		
		
		if(str && symbol != ' ')
			x = x + 1;
	}
	
	return x;
}
