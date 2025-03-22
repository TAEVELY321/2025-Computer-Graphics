#pragma once
#include "CShape.h"

class CRectangle : public CShape
{
public:
	float m_w;
	float m_h;

	CRectangle(float x = 0, float y = 0, float w = 0, float h = 0) : CShape(x, y), m_w(w), m_h(h) {}

	void Draw(HDC hdc) override;

	~CRectangle() {}
};

