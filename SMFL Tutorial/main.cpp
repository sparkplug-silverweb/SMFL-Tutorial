#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Animator.h"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "AssetManager");
	AssetManager manager;

	auto wSize = window.getSize();
	sf::View view(sf::FloatRect(0, 0, wSize.x, wSize.y));
	view.setCenter(sf::Vector2f(0, 0));
	//Initialize view
	window.setView(view);



	sf::Vector2i spriteSize(46, 46);
	sf::Sprite sprite;
	sprite.setOrigin(0, 0);
	sprite.setScale(3, 3);
	Animator animator(sprite);

	auto& HeroAnimation1 = animator.CreateAnimation("HeroAnimation1", "player-spritemap-v9.png", sf::seconds(1), true);
	HeroAnimation1.AddFrames(sf::Vector2i(0, 0), spriteSize, 8);

	
	auto& HeroAnimation2 = animator.CreateAnimation("HeroAnimation2", "player-spritemap-v9.png", sf::seconds(1), true);
	HeroAnimation2.AddFrames(sf::Vector2i(0, 49), spriteSize, 6);


	auto& HeroAnimation3 = animator.CreateAnimation("HeroAnimation3", "player-spritemap-v9.png", sf::seconds(1), true);
	HeroAnimation3.AddFrames(sf::Vector2i(0, 103), spriteSize, 6);


	auto& HeroAnimation4 = animator.CreateAnimation("HeroAnimation4", "player-spritemap-v9.png", sf::seconds(1), true);
	HeroAnimation4.AddFrames(sf::Vector2i(0, 150), spriteSize, 8);


	sf::Music music;
	if (!music.openFromFile("1.ogg"))
		return -1;
	music.setLoop(true);
	music.play();



	sf::Clock clock;
	while (window.isOpen())
	{
		//Returns the elapsed time and restarts the clock
		sf::Time deltaTime = clock.restart();

		sf::Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::EventType::Closed)
				window.close();
			
			
			
			if (ev.type == sf::Event::KeyPressed)
			{
				if (ev.key.code == sf::Keyboard::Key::Up)
					animator.SwitchAnimation("HeroAnimation1");
				else if (ev.key.code == sf::Keyboard::Key::Down)
					animator.SwitchAnimation("HeroAnimation2");
				else if (ev.key.code == sf::Keyboard::Key::Left)
					animator.SwitchAnimation("HeroAnimation3");
				else if (ev.key.code == sf::Keyboard::Key::Right)
					animator.SwitchAnimation("HeroAnimation4");
			}
		}

		animator.Update(deltaTime);

		window.clear(sf::Color::Black);

		window.draw(sprite);

		window.display();
	}

	//After main() returns, the manager is destroyed
	return 0;
}

