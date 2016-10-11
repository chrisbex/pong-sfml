class Paddle
{
public:
	Paddle(sf::Vector2f pos);
	~Paddle() {};
	void setPosition(sf::Vector2f pos);
	void setColor(sf::Color color);
	sf::Vector2f getPosition();
	sf::Color getColor();
	void draw(sf::RenderWindow& win1);

private:
	sf::Vector2f itsPosition;
	sf::Color itsColor;
	sf::RectangleShape shape;
};

Paddle::Paddle(sf::Vector2f pos)
{
	shape.setPosition(pos);
	shape.setFillColor(sf::Color::White);
	shape.setSize(sf::Vector2f(10, 60));
}

void Paddle::setPosition(sf::Vector2f pos)
{
	itsPosition = pos;
}

void Paddle::setColor(sf::Color color)
{
	itsColor = color;
}

sf::Vector2f Paddle::getPosition()
{
	return itsPosition;
}

sf::Color Paddle::getColor()
{
	return itsColor;
}

void Paddle::draw(sf::RenderWindow& win1)
{
	win1.draw(shape);
}