#include "CRectangle.h"
#include <windows.h>
#include <iostream>


void CRectangle::Draw(HDC hdc)
{
	Rectangle(hdc, m_x, m_y, m_w, m_h);
}