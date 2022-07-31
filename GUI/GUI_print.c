
#include "GUI_print.h"
#include "LCD_ILI9341.h"


// 
void	GUI_intToStr(int32_t num, char *strBuf)
{
	uint8_t	charCounter	=	0;
	char		bufChar			=	0;
	
	if(num == 0)
	{
		*strBuf = '0';
		strBuf++;
		*strBuf = '\0';
		return;
	}
	
	if(num < 0)
	{
		*strBuf = '-';
		strBuf++;
	}
	
	while(num)
	{
		*strBuf = '0' + num % 10;
		if(num / 10)
		{
			strBuf++;
			charCounter++;
		}
		num = num / 10;
	}
	
	strBuf = strBuf - charCounter;
	
	for(uint8_t i = 0; i < charCounter/2+1; i++)
	{
		bufChar			=	*(strBuf+i);
		*(strBuf+i)	=	*(strBuf+charCounter-i);
		*(strBuf+charCounter-i) = bufChar;
	}
	
	*(strBuf+charCounter+1) = '\0';
}

// 
void	GUI_floatToStr(float num, char *strBuf)
{
	int32_t	numInt				=	(int32_t)(num*10);
	uint8_t	charCounter		=	0;
	char		bufChar				=	0;
	
	
	if(num < 0)
	{
		*strBuf = '-';
		strBuf++;
	}
	
	if(numInt < 10  && numInt >= 0)
	{
		*strBuf = '0';
		strBuf++;
		*strBuf = '.';
		strBuf++;
		*strBuf = '0' + numInt % 10;
		strBuf++;
		*strBuf = '\0';
		return;
	}
	
	while(numInt)
	{
		if(charCounter == 1)
		{
			*strBuf = '.';
			strBuf++;
			charCounter++;
		}
		*strBuf = '0' + numInt % 10;
		if(numInt / 10)
		{
			strBuf++;
			charCounter++;
		}
		numInt = numInt / 10;
	}
	
	strBuf = strBuf - charCounter;
	
	for(uint8_t i = 0; i < charCounter/2+1; i++)
	{
		bufChar			=	*(strBuf+i);
		*(strBuf+i)	=	*(strBuf+charCounter-i);
		*(strBuf+charCounter-i) = bufChar;
	}
	
	*(strBuf+charCounter+1) = '\0';
}


// отрисовка рамки
void    GUI_drawFrame(uint16_t	X0,	uint16_t	X1,			// X-координаты
										uint16_t	Y0,	uint16_t	Y1,			// Y-координаты
										uint16_t	border,								// ширина рамки
										uint16_t	borderColor)					// цвет рамки
{
	// отрисовка рамки
	LCD_drawFilledRectangle(X0, X0+(border-1), Y0, Y1, borderColor);
	LCD_drawFilledRectangle(X0, X1, Y1-(border-1), Y1, borderColor);
	LCD_drawFilledRectangle(X1-(border-1), X1, Y0, Y1, borderColor);
	LCD_drawFilledRectangle(X0, X1, Y0, Y0+(border-1), borderColor);
}

// отрисовка заполненной рамки
void	GUI_drawFilledFrame(uint16_t	X0,	uint16_t	X1,			// X-координаты
													uint16_t	Y0,	uint16_t	Y1,			// Y-координаты
													uint16_t	border,								// ширина рамки
													uint16_t	mainColor,						// основной цвет
													uint16_t	borderColor)					// цвет рамки
{
	LCD_drawFilledRectangle(X0, X1, Y0, Y1, mainColor);
	// отрисовка рамки
	if(border > 0)
	{
		LCD_drawFilledRectangle(X0, X0+(border-1), Y0, Y1, borderColor);
		LCD_drawFilledRectangle(X0, X1, Y1-(border-1), Y1, borderColor);
		LCD_drawFilledRectangle(X1-(border-1), X1, Y0, Y1, borderColor);
		LCD_drawFilledRectangle(X0, X1, Y0, Y0+(border-1), borderColor);
	}
}

// отрисовка картинки
void	GUI_drawPicture(uint16_t	X0,											// X-координаты объекта
											uint16_t	Y0,											// Y-координаты объекта
											uint16_t	border,									// ширина границ
											uint16_t	pictureColor,						// основной цвет
											uint16_t	borderColor,						// цвет границ
											uint16_t	*picture)								// указатель на картинку
{
	;
}
