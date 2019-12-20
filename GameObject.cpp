#include "GameObject.h"


GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
}

CellPosition GameObject::GetPosition() const
{
	return position;
}

bool GameObject::IsOverlaping(GameObject* newObj)
{
	return false;
}

GameObject::~GameObject()
{
}