#include "collisions.h"
#include "Character.h"

collisions* collisions::m_instance = nullptr;

collisions::collisions()
{

}

collisions::~collisions()
{
	m_instance = nullptr;
}

collisions* collisions::Instance()
{
	if (!m_instance) 
	{
		m_instance = new collisions;
	}
	return m_instance;
}

bool collisions::Circle(Character* Character1, Character* Character2)
{
	Vector2D vec = Vector2D(Character1->GetPosition().x - Character2->GetPosition().x, (Character1->GetPosition().y - Character2->GetPosition().y));
	double distance = sqrt((vec.x * vec.x) + (vec.y * vec.y));
	double combined_distance = (Character1->GetCollisionradius() + Character2->GetCollisionradius());
	return distance < combined_distance;
}

bool collisions::box(Rect2D rect1, Rect2D rect2)
{
	if (rect1.x + (rect1.width / 2) > rect2.x && rect1.x + (rect1.width / 2) < rect2.x + rect2.width && rect1.y + (rect1.height / 2) > rect2.y && rect1.y + (rect1.height / 2) < rect2.y + rect2.height) 
	{
		return true;
	}
	return false;
}






