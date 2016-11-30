#include "Animation.h"



Animation::Animation(sf::Texture* texture, sf::Vector2u frames, float rate)
{
	m_frames = frames;
	switchT = rate;
	totalT = 0.0f;
	current.x = 0;

	uvRect.width = texture->getSize().x / float(frames.x);
	uvRect.height = texture->getSize().y / float(frames.y);
}


Animation::~Animation()
{
}

void Animation::Update(float delta, int row)
{
	current.y = row;
	totalT += delta;
	if (totalT >= switchT) {
		totalT -= switchT;
		current.x++;
	}
	if (current.x >= m_frames.x) {
		current.x = 0;
	}
	uvRect.left = current.x * uvRect.width;
	uvRect.top = current.y * uvRect.height;
}