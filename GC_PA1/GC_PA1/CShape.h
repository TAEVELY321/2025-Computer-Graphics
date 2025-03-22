#pragma once
#include <Windows.h>

class CShape
{
public:
	float m_x;
	float m_y;

	CShape(float x = 0, float y = 0) : m_x(x), m_y(y) {}

	virtual void Draw(HDC hdc) = 0;

	virtual ~CShape() {}
};