#pragma once

#include <string>

namespace Constants {
	const float WINDOW_WIDTH = 640;
	const float WINDOW_HEIGHT = 480;

	const std::string HELICOPTER_IMAGE_NAME = "helicopter.png";
	const std::string BACKGROUND_IMAGE_NAME = "background.png";
	const std::string OBSTACLE_IMAGE_NAME = "obstacle.png";

	const float GRAVITY = 9.81;
	const float HELICOPTER_VERTICAL_ACCELERATION = 27.5;
	const float HELICOPTER_HORIZONTAL_VELOCITY = 75;

	const int OBSTACLES_TO_GENERATE = 10;
	const int OBSTACLE_WIDTH = 25;
	const int OBSTACLE_HEIGHT = 75;;
}