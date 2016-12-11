#include<SFML/Graphics.hpp>

class Animation
{
public:
	void init(sf::Texture* texture, sf::Vector2u frames, float rate);
	~Animation();
	void Update(float delta, int row);
public:
	sf::IntRect uvRect;
private:
	sf::Vector2u m_frames;
	sf::Vector2u current;
	float totalT;
	float switchT;
};

