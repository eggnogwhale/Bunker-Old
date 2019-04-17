#pragma once

class Entity{
public:
	int m_id;
	Entity();
	Entity(int id);
	~Entity();
	void draw();
	void run();
private:
	int m_x,m_y,m_s;
};