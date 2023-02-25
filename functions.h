#pragma once
#include "settings.h"
#include "functions.h"
#include "player.h"
#include "obstacle.h"
#include "road.h"

int scoreCount(Player& player, Obstacle obs, int score) {
	if (player.sprite.getPosition().y + PLAYER_HEIGHT < obs.sprite.getPosition().y + OBS_HEIGHT) {
		score++;
	}
	return score;
}
//
//void checkClolisions(sf::FloatRect& playerHitBox,sf::FloatRect& obs1HitBox, sf::FloatRect& obs2HitBox, sf::FloatRect& obs3HitBox, sf::RenderWindow& window) {
//	if (playerHitBox.intersects(obs1HitBox)) {
//		window.close();
//	}
//	if (playerHitBox.intersects(obs2HitBox)) {
//		window.close();
//	}
//	if (playerHitBox.intersects(obs3HitBox)) {
//		window.close();
//	}
//}

//float speedControl(RoadLayer layer, float speed) {
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
//		speed++;
//		return speed;
//	};
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
//		speed--;
//		return speed;
//	};
//}