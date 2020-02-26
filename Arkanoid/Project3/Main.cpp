#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include"Ball.h"
#include"Paddle.h"
#include"Block.h"

using namespace sf;
using namespace std;

template <class T1, class T2> bool isIntersecting(T1& A, T2& B)
{
	return A.right() >= B.left() && A.left() <= B.right()
		&& A.bottom() >= B.top() && A.top() <= B.bottom();
}

bool collisionTest(Paddle& paddle, Ball& ball)
{
	if (!isIntersecting(paddle, ball)) return false;

	ball.moveUp();

	if (ball.getPosition().x < paddle.getPosition().x)
	{
		ball.moveLeft();
	}
	else if (ball.getPosition().x > paddle.getPosition().x)
	{
		ball.moveRight();
	}



}

bool collisionTest(Block& block, Ball& ball)
{
	if (!isIntersecting(block, ball)) return false;

	block.destroy();

	float overlapLeft{ ball.right() - block.left() };
	float overlapRight{ ball.right() - ball.left() };
	
	float overlapTop{ ball.bottom() - block.top() };
	float overlapBottom{ block.bottom() - ball.top() };

	bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
	bool ballFromTop(abs(overlapTop) < abs(overlapBottom));
	
	float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
	float minOverlapY{ ballFromTop ? overlapTop : overlapBottom };

	if (abs(minOverlapX) < abs(minOverlapY))
	{
		ballFromLeft ? ball.moveLeft() : ball.moveRight();
	}
	else
	{
		ballFromTop ? ball.moveUp() : ball.moveDown();
	}
}

int main()
{
	Paddle paddle(400, 550);
	Ball ball(400, 300);
	unsigned blocksX{ 10 }, blocksY{ 4 }, blockWidth{ 60 }, blockHeight{ 20 };
	vector<Block> blocks;

	for (int i = 0; i < blocksY; i++)
	{
		for (int j = 0; j < blocksX; j++)
		{
			blocks.emplace_back((j + 1) * (blockWidth + 10), (i + 2) * (blockHeight + 5), blockWidth, blockHeight);
		}
	}

	RenderWindow window{ VideoMode{800, 600}, "Arkanoid tutorial" };
	window.setFramerateLimit(60);
	Event event;				//interakcja z programem
	while (true)				//glowna petla
	{
		window.clear(Color::Black);
		window.pollEvent(event);

		if (event.type == Event::Closed)
		{
			window.close();
			break;

		}
		ball.update();
		paddle.update();
		collisionTest(paddle, ball);

		for (auto& block : blocks) if (collisionTest(block, ball)) break;

		auto iterator = remove_if(begin(blocks), end(blocks), [](Block& block){return block.isDestroyed();});
		blocks.erase(iterator, end(blocks));
	

		window.draw(ball);
		window.draw(paddle);

		for (auto& block : blocks)
			window.draw(block);
		window.display();


	}

	return 0;
}