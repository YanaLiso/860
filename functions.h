#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
#include "ball.h"
#include "rowbrick.h"

/*void rectInit(sf::RectangleShape& rect, const sf::Color rectColor, const sf::Vector2f rectStartPosition) {
	rect.setSize(BAT_SIZE);
	rect.setFillColor(rectColor);
	rect.setPosition(rectStartPosition);
}*/

bool pointInRect(sf::RectangleShape rect, sf::Vector2f point) {
	return	rect.getPosition().x <= point.x &&
		point.x <= rect.getPosition().x + rect.getSize().x &&
		rect.getPosition().y <= point.y &&
		point.y <= rect.getPosition().y + rect.getSize().y;
}

void ballCollidedWithBricks(Ball& ball, Brickrow& brickrow) {
	sf::Vector2f midLeft{
		ball.shape.getPosition().x,
		ball.shape.getPosition().y + BALL_RADIUS
	};
	sf::Vector2f midTop{
		ball.shape.getPosition().x + BALL_RADIUS,
		ball.shape.getPosition().y
	};
	sf::Vector2f midBottom{
		ball.shape.getPosition().x + BALL_RADIUS,
		ball.shape.getPosition().y + 2 * BALL_RADIUS
	};
	sf::Vector2f midRight{
		ball.shape.getPosition().x + 2 * BALL_RADIUS,
		ball.shape.getPosition().y + BALL_RADIUS
	};
	for (int i = 0; i < brickrow.size; i++) {
		if (pointInRect(brickrow.brickArr[i].shape, midTop)) {
			std::swap(
				brickrow.brickArr[i],
				brickrow.brickArr[brickrow.size - 1]
			);
			brickrow.size--;
			ball.speedY = -ball.speedY;
			break;
		}
	}
	for (int i = 0; i < brickrow.size; i++) {
		if (pointInRect(brickrow.brickArr[i].shape, midLeft)) {

			std::swap(
				brickrow.brickArr[i],
				brickrow.brickArr[brickrow.size - 1]
			);
			brickrow.size--;
			ball.speedY = -ball.speedY;
			break;
		}
	}
	for (int i = 0; i < brickrow.size; i++) {
		if (pointInRect(brickrow.brickArr[i].shape, midBottom)) {
			std::swap(
				brickrow.brickArr[i],
				brickrow.brickArr[brickrow.size - 1]
			);
			brickrow.size--;
			ball.speedY = -ball.speedY;
	        break;
		}
	}
			for (int i = 0; i < brickrow.size; i++) {
				if (pointInRect(brickrow.brickArr[i].shape, midRight)) {
					std::swap(
						brickrow.brickArr[i],
						brickrow.brickArr[brickrow.size - 1]
					);
					brickrow.size--;
					ball.speedY = -ball.speedY;
					break;
				}
			}
		}