class Ball
{
	public:
		Ball(sf::Vector2f);
		~Ball() {};
		int setPosition(sf::Vector2f);
		int setColor(sf::Color);
		sf::Vector2f getPosition();
		sf::Color getColor();
		void draw(sf::RenderWindow& win1);
		sf::Vector2f getVelocity() { return itsVelocity; };
		float getVelocityX() { return itsVelocity.x; };
		float getVelocityY() { return itsVelocity.y; };
		void setVelocityX(float x) { itsVelocity.x = x; };
		void setVelocityY(float y) { itsVelocity.y = y; };

	private:
		sf::Vector2f itsPosition;
		sf::CircleShape shape; 
		sf::Color shapeColor;
		sf::Vector2f itsVelocity;
};

Ball::Ball(sf::Vector2f pos)
{
	shape.setFillColor(sf::Color::White);
	shape.setPosition(pos);
	shape.setRadius(10.f);
	shape.setOutlineColor(sf::Color::Green);
	itsVelocity = sf::Vector2f(-10, -10);
	itsPosition = pos;
}

int Ball::setPosition(sf::Vector2f x)
{
	itsPosition = x;
	shape.setPosition(x);
	return 1;
}

sf::Vector2f Ball::getPosition()
{
	return itsPosition;
}

int Ball::setColor(sf::Color x)
{
	shapeColor = x;
	shape.setFillColor(x);
	return 1;
}

sf::Color Ball::getColor()
{
	return shapeColor;
}

void Ball::draw(sf::RenderWindow& win1)
{
	win1.draw(shape);
}

