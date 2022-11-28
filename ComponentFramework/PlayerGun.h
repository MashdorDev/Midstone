#ifndef PLAYER_GUN_H
#define	PLAYER_GUN_H

#include <SDL.h>

#include "Actor.h"
#include "Shader.h"
#include "Scene.h"
#include "Debug.h"
#include "MMAth.h"
#include "CameraActor.h"
#include "Bullet.h"

using namespace MATH;
using namespace std;

class PlayerGun : public Actor
{
private:
	// Position & Rotation
	Vec3 position;
	float rotation;
	Vec3 rotationAxis;
	Vec3 offset;

	// Model
	Actor* model_3D;
	Shader* shader;

	// Player
	CameraActor* camera;

	// Bullets
	vector<Bullet*> spawnedBullets;
	int bulletLabel = 0;

public:
	//PlayerGun(Vec3 offset_, float spawnRotation_, Vec3 spawnRotationAxis_, CameraActor* camera_, Component* parent_);
	PlayerGun(Vec3 offset_, float spawnRotation_, Vec3 spawnRotationAxis_, CameraActor* camera_, Component* parent_);
	~PlayerGun();

	bool OnCreate();
	void OnDestroy();
	void Render();
	void Update(float deltaTime);
	void HandleEvents(const SDL_Event& sdlEvent);

	void SpawnBullet(Vec3 velocity_);
	void DestroyBullet(int label);
};

#endif // !PLAYER_GUN_H