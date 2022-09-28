#include "StageState.h"
#include "Sound.h"
#include "TileMap.h"
#include "Game.h"
#include "Text.h"
#include "Camera.h"
#include "HealthBox.h"
#include "InputManager.h"
#include "CameraFollower.h"
#include "Alien.h"
#include "PenguinBody.h"
#include "Collision.cpp"
#include "TitleState.h"
#include "EndState.h"
#include "GameData.h"

StageState::StageState() : State(), backgroundMusic("assets/audio/stageState.ogg")
{
	// Background
	GameObject *bg = new GameObject();
	bg->AddComponent(new Sprite(*bg, "assets/img/ocean.jpg", 1, 1.0));
	bg->AddComponent(new CameraFollower(*bg));
	bg->box.x = 0;
	bg->box.y = 0;
	AddObject(bg);

	GameObject *tileMap = new GameObject();
	TileSet *tileSet = new TileSet(*tileMap, 64, 64, "assets/img/tileset.png");
	tileMap->AddComponent(new TileMap(*tileMap, "assets/map/tileMap.txt", tileSet));
	tileMap->box.x = 0;
	tileMap->box.y = 0;
	AddObject(tileMap);

	GameObject *penguin = new GameObject();
	PenguinBody *penguinBody = new PenguinBody(*penguin);
	penguin->AddComponent(penguinBody);
	penguin->box.x = 704;
	penguin->box.y = 640;
	AddObject(penguin);
	Camera::Follow(penguin);

	int newX;
	int newY;

	int maxAliens = (int)(((float)rand() / RAND_MAX) * (6 - 1) + 1);
	float newOffset;
	GameObject *alien;

	for (int i = 0; i < maxAliens; i++)
	{
		alien = new GameObject();
		newOffset = ((((float)rand()) / RAND_MAX) + i) / pow(10, i);
		alien->AddComponent(new Alien(*alien, newOffset));
		newX = (int)(((float)rand() / RAND_MAX) * (1340 + 40) - 40);
		newY = (int)(((float)rand() / RAND_MAX) * (1280 + 10) - 10);
		alien->box.x = newX - alien->box.w / 2;
		alien->box.y = newY - alien->box.h / 2;
		AddObject(alien);
	}
}

StageState::~StageState()
{
	objectArray.clear();
}

void StageState::Start()
{
	LoadAssets();
	StartArray();
	backgroundMusic.Play();
	started = true;
}

void StageState::LoadAssets()
{
}

void StageState::Pause()
{
	backgroundMusic.Stop();
}

void StageState::Resume()
{
	backgroundMusic.Play();
}

void StageState::Update(float dt)
{
	// update camera
	Camera::Update(dt);

	// check if quit was requested
	if (InputManager::GetInstance().QuitRequested())
	{
		quitRequested = true;
	}

	if (InputManager::GetInstance().KeyPress(ESCAPE_KEY))
	{
		this->Pause();
		popRequested = true;
	}

	// Update every object
	UpdateArray(dt);

	// if (newPos.x > 0 && newPos.x < 1408 && newPos.y > 0 && newPos.y < 1280)
	// {
	//     associated.box = newPos;
	// }
	// (rand() / RAND_MAX) * (maxScale - minScale) + minScale
	srand(time(NULL));
	float chance = ((float)rand() / RAND_MAX) * 10;
	if (chance > 7 && QueryObjectsBy("HealthBox").size() < 1)
	{
		GameObject *health = new GameObject();
		health->AddComponent(new HealthBox(*health));
		int newX = (int)(((float)rand() / RAND_MAX) * (1400 - 20) + 20);
		int newY = (int)(((float)rand() / RAND_MAX) * (1280 - 20) + 20);
		health->box.x = newX - health->box.w / 2;
		health->box.y = newY - health->box.h / 2;
		AddObject(health);
	}

	// check collidable objects
	// TODO: improve here
	std::vector<std::weak_ptr<GameObject>> collidable = QueryObjectsBy("Collider");
	for (unsigned i = 0; i < collidable.size(); i++)
	{
		for (unsigned j = i + 1; j < collidable.size(); j++)
		{
			if (Collision::IsColliding(collidable[i].lock()->box, collidable[j].lock()->box, collidable[i].lock()->angleDeg * PI / 180, collidable[j].lock()->angleDeg * PI / 180))
			{
				GameObject *g1 = collidable[i].lock().get();
				GameObject *g2 = collidable[j].lock().get();
				g1->NotifyCollision(*g2);
				g2->NotifyCollision(*g1);
			}
		}
	}

	// Check if object is dead
	for (unsigned i = 0; i < objectArray.size(); i++)
	{
		if (objectArray[i]->IsDead())
		{
			objectArray.erase(objectArray.begin() + i);
		}
	}

	if (Alien::alienCount <= 0)
	{
		GameData::playerVictory = true;
		popRequested = true;
		Game::GetInstance().Push(new EndState());
	}

	if (PenguinBody::player == nullptr)
	{
		GameData::playerVictory = false;
		popRequested = true;
		Game::GetInstance().Push(new EndState());
	}
}

void StageState::Render()
{
	// Render every object
	RenderArray();
}
