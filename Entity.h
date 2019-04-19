#pragma once
#include "CameraSystem.h"

class Entity{
public:
	int m_id;
	Entity();
	virtual ~Entity();
	virtual void draw();
	virtual void run();
	/**With the camera*/
	virtual void follow(CameraSystem& camSys);
private:
	int m_x,m_y,m_s;
};