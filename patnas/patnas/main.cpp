#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
	RenderWindow window(VideoMode(256, 256), "Puzzles");
	Texture texture;
	window.setFramerateLimit(60);
	texture.loadFromFile("C:/Users/adm/source/repos/patnas/images/texture01.png");
	int widht = 64;
	int mas[6][6] = { 0 };
	Sprite sprite[17];
	int n = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			n++;
			sprite[n].setTexture(texture);
			sprite[n].setTextureRect(IntRect(i * widht, j * widht, widht, widht));
			mas[i+1][j+1] = n;
		}
	}
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.key.code == Mouse::Left)
				{
					Vector2i position = Mouse::getPosition(window);
					int x = position.x / widht+1;
					int y = position.y / widht+1;
					int dx = 0;
					int dy = 0;
					if (mas[x + 1][y] == 16)
					{
						dx=1;
						dy = 0;
					}
					if (mas[x - 1][y] == 16)
					{
						dx=-1;
						dy = 0;
					}
					if (mas[x][y + 1] == 16)
					{
						dx = 0;
						dy=1;
					}
					if (mas[x][y - 1] == 16)
					{
						dx = 0;
						dy=-1;
					}
					int temp=mas[x][y];
					mas[x][y] = 16;
					mas[x + dx][y + dy] = temp;
					sprite[16].move(-dx*widht, -dy*widht);
					float speed = 6;
					for (int i = 0; i < widht; i += speed)
					{
						sprite[temp].move(dx*speed, dy*speed);
						window.draw(sprite[16]);
						window.draw(sprite[temp]);
						window.display();
					}
				}
			}
		}
		window.clear(Color::White);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				int n = mas[i + 1][j + 1];
				sprite[n].setPosition(i * widht, j * widht);
				window.draw(sprite[n]);
			}
		}
		window.display();
	}
	return 0;
}