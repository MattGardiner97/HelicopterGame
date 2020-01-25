#pragma once

#include <string>

namespace Constants {
	const float WINDOW_WIDTH = 640;
	const float WINDOW_HEIGHT = 480;

	const std::string HELICOPTER_IMAGE_NAME = "helicopter.png";
	const std::string BACKGROUND_IMAGE_NAME = "background.png";
	const std::string OBSTACLE_IMAGE_NAME = "obstacle.png";
	const std::string FONT_NAME = "Montserrat-Regular.ttf";

	const float GRAVITY = 9.81;
	const float HELICOPTER_VERTICAL_ACCELERATION = 22.5;
	const float HELICOPTER_STARTING_POSITION = 25;
	const float	BACKGROUND_SCROLL_SPEED = 50;

	const int OBSTACLE_PAIRS_TO_GENERATE = 5;
	const int OBSTACLE_WIDTH = 25;
	const int OBSTACLE_HEIGHT = 641;

	const int HELICOPTER_SIZE = 25;

}