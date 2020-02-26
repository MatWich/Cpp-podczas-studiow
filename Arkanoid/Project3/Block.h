#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

class Block :public Drawable 
{
public:
	Block(float X, float Y, float t_Width, float t_Height);
	Block() = delete;
	~Block() = default;


	void update();
	Vector2f getPosition();

	float left();
	float right();
	float top();
	float bottom();

	bool  isDestroyed();
	void destroy();
	Vector2f getSize();


private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;		//nadpisanie metody draw
	RectangleShape shape;
	bool destroyed{ false };
};

