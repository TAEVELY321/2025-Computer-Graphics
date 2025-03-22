#include "CCircle.h"
#include <iostream>
#include <windows.h>

void CCircle::Draw(HDC hdc)
{
	Ellipse(hdc, m_x - m_radius, m_y - m_radius, m_x + m_radius, m_y +m_radius);
}