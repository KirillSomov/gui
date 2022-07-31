
#ifndef GUI_PRINT_H
#define GUI_PRINT_H


#include "stm32f4xx.h"
#include "pixel_map.h"


void	GUI_intToStr(int32_t num, char *strBuf);					//
void	GUI_floatToStr(float num, char *strBuf);					//

void	GUI_drawFrame(uint16_t	X0,	uint16_t	X1,					// X-���������� �������	// ��������� ������ �������
										uint16_t	Y0,	uint16_t	Y1,					// Y-���������� �������
										uint16_t	border,										// ������ ������
										uint16_t	borderColor);							// ���� �������
void	GUI_drawFilledFrame(uint16_t	X0,	uint16_t	X1,		// X-���������� �������	// ��������� ������ �������
													uint16_t	Y0,	uint16_t	Y1,		// Y-���������� �������
													uint16_t	border,							// ������ ������
													uint16_t	mainColor,					// �������� ����
													uint16_t	borderColor);				// ���� �������
void	GUI_drawPicture(uint16_t	X0,											// X-���������� �������	// ��������� ��������
											uint16_t	Y0,											// Y-���������� �������
											uint16_t	border,									// ������ ������
											uint16_t	pictureColor,						// �������� ����
											uint16_t	borderColor,						// ���� ������
											uint16_t	*picture);							// ��������� �� ��������
 
uint16_t PixelMap_getPixel(PixelMap_t *pixelMap, uint16_t x, uint16_t y);


#endif
