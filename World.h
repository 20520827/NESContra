#pragma once
#include "GameObject.h"
#include "Game.h"
class World
{
public:
	World();
	World(int l, int t, int r, int b);
	~World();
	void Build(World* w);
	vector<LPGAMEOBJECT> objects;
private:
	World* leftNode;
	World* rightNode;
	int left;
	int right;
	int top;
	int bottom;
};

World::World()
{
	
}

World::World(int l, int t, int r, int b)
{
	this->leftNode = NULL;
	this->rightNode = NULL;
	this->left = l;
	this->top = t;
	this->right = r;
	this->bottom = b;
}

World::~World()
{
}

void World::Build(World* w)
{
	CGame* g = CGame::GetInstance();
	if (abs(this->right - this->left) >= g->GetBackBufferWidth() / 2 && objects.size() > 0)
	{
		this->leftNode = new World(this->left, this->top, this->right / 2, this->bottom);
		this->rightNode = new World(this->right / 2, this->top, this->right, this->bottom);
		for (int i = 0; i < objects.size(); i++)
		{
			float x = -1, y = -1;
			objects[i]->GetPosition(x, y);
			if (x >= left && x <= right / 2)
			{
				leftNode->objects.push_back(this->objects[i]);
			}
			if (x > right / 2 && x <= right)
			{
				rightNode->objects.push_back(this->objects[i]);
			}
		}
		this->objects.clear();
		Build(leftNode);
		Build(rightNode);
	}
}