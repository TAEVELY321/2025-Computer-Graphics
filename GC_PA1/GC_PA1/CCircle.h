#pragma once
#include "CShape.h"
class CCircle :
    public CShape
{
public:
	float m_radius;

	CCircle(float x = 0, float y = 0, float radius = 0) : CShape(x, y), m_radius(radius) {}
	void Draw(HDC hdc) override;

	~CCircle() {}
};

