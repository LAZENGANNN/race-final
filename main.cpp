#include "settings.h"
#include "road.h"
#include "player.h"
#include "obstacle.h"
#include "ctime"
#include "textObj.h"
#include "functions.h"

using namespace sf;

int main()
{
	srand(time(nullptr));
	// Îáúåêò, êîòîðûé, ñîáñòâåííî, ÿâëÿåòñÿ ãëàâíûì îêíîì ïðèëîæåíèÿ
	RenderWindow window(
		VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		WINDOW_TITLE,
		Style::Titlebar | Style::Close
	);
	window.setPosition(Vector2i{ (1920 - (int)WINDOW_WIDTH) / 2, 0 });
	window.setFramerateLimit(FPS);

	RoadLayer grass1, grass2;
	RoadLayer road1, road2;
	roadLayerInit(grass1, Vector2f{ 0.f,0.f }, "grass.jpg", 0.f);
	roadLayerInit(grass2, Vector2f{ 0.f,-WINDOW_HEIGHT }, "grass.jpg", 0.f);
	roadLayerInit(road1, Vector2f{ ROAD_OFFSET,0.f }, "road.jpg", ROAD_OFFSET);
	roadLayerInit(road2, Vector2f{ ROAD_OFFSET,-WINDOW_HEIGHT }, "road.jpg", ROAD_OFFSET);
	Player player;
	playerInit(player, PLAYER_START_POS, "car1.png");
	Obstacle box;
	Obstacle oil;
	Obstacle obsCar;
	obstacleInit(box, "box.png");
	obstacleInit(oil, "oil.png");
	obstacleInit(obsCar, "obsCar.png");
	int HP = 42;
	int score = 0;
	TextObj scoreText;
	textInit(scoreText, score);



	while (window.isOpen())
	{


		// Îáðàáàòûâàåì î÷åðåäü ñîáûòèé â öèêëå
		Event event;
		while (window.pollEvent(event))
		{
			// Ïîëüçîâàòåëü íàæàë íà «êðåñòèê» è õî÷åò çàêðûòü îêíî?
			if (event.type == Event::Closed)
				// òîãäà çàêðûâàåì åãî
				window.close();
		}
		//Update
		roadLayerUpdate(grass1);
		roadLayerUpdate(grass2);
		roadLayerUpdate(road1);
		roadLayerUpdate(road2);
		playerUpdate(player);
		obstacleUpdate(box);
		obstacleUpdate(oil);
		obstacleUpdate(obsCar);
		//проверка столкновения игрока и препятствий
		FloatRect playerHitBox = player.sprite.getGlobalBounds();
		FloatRect boxHitBox = box.sprite.getGlobalBounds();
		FloatRect oilHitBox = oil.sprite.getGlobalBounds();
		FloatRect obsObsHitBox = obsCar.sprite.getGlobalBounds();
		/*checkClolisions(playerHitBox, obs1HitBox, obs2HitBox, obs3HitBox, window);*/
		if (playerHitBox.intersects(boxHitBox)) {
			score -= 2;
		}
		if (playerHitBox.intersects(oilHitBox)) {
			score--;
		}
		if (playerHitBox.intersects(obsObsHitBox)) {
			window.close();
		}
		
		textUpdate(scoreText, score);

		score  = scoreCount(player, box, score);
		score = scoreCount(player, oil, score);
		score = scoreCount(player, obsCar, score);

		/*if (playerHitBox.intersects(boxHitBox)) {
			HP-= 14;
		}
		if (playerHitBox.intersects(oilHitBox)) {
			HP-= 14;
		}
		if (playerHitBox.intersects(obs3HitBox)) {
			HP -= 14;
		}*/
		if (score <= -1) window.close();

		// Îòðèñîâêà îêíà
		window.clear();
		roadLayeDraw(window, grass1);
		roadLayeDraw(window, grass2);
		roadLayeDraw(window, road1);
		roadLayeDraw(window, road2);
		playerDraw(window, player);
		obstacleDraw(window, box);
		obstacleDraw(window, oil);
		obstacleDraw(window, obsCar);
		textDraw(window, scoreText);
		window.display();
	}
	return 0;
}
