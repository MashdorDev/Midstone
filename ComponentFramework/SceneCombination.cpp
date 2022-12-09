// Basic include
#include "SceneCombination.h"

SceneCombination::SceneCombination()
{
	// Debug information
	Debug::Info("Created SceneCombination: ", __FILE__, __LINE__);

#pragma region Wall & Pickup Creation
	// NorthLimit
	float northWallZStart = -30.0f;
	for (int a = 0; a < 25; a++) // Until northWallZEnd
	{
		northWallZStart += 2.0f;

		Wall* wallTest = new Wall(Vec3(20.0f, 0.0f, northWallZStart), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'w');
		Wall* wallTestSOUTH = new Wall(Vec3(-24.0f, 0.0f, northWallZStart), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'w');

		theWalls.push_back(wallTest);
		theWalls.push_back(wallTestSOUTH);
	}

	// WestLimit
	float westWallXStart = 20.0f;
	for (int a = 0; a < 22; a++) // Until northWallZEnd
	{
		westWallXStart -= 2.0f;

		Wall* wallTest = new Wall(Vec3(westWallXStart, 0.0f, -30.0f), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'w');
		Wall* wallTesteast = new Wall(Vec3(westWallXStart, 0.0f, 22.0f), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'w');

		theWalls.push_back(wallTest);
		theWalls.push_back(wallTesteast);
	}

	// A'RoomWalls  DOOR
	float AWallXStart = -30.0f;
	float AWallzStart = -8.0f;
	for (int a = 0; a < 5; a++)
	{
		AWallXStart += 2.0f;
		AWallzStart += 2.0f;

		Wall* AwallTestEast;
		Wall* AwallTestNorth = new Wall(Vec3(4.0f, 0.0f, AWallXStart), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'w');
		Wall* AwallTestSouth = new Wall(Vec3(-8.0f, 0.0f, AWallXStart), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'w');

		if (AWallzStart == 2.0f)
			AwallTestEast = new Wall(Vec3(AWallzStart, 0.0f, -18.0f), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'a');
		else
			AwallTestEast = new Wall(Vec3(AWallzStart, 0.0f, -18.0f), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'w');

		theWalls.push_back(AwallTestNorth);
		theWalls.push_back(AwallTestSouth);
		theWalls.push_back(AwallTestEast);
	}

	// B'RoomWalls DOOR
	float bWallXStart = -30.0f;
	for (int a = 0; a < 5; a++)
	{
		bWallXStart += 2.0f;
		Wall* BwallTestNorth;

		if (bWallXStart == -28.0f)
			BwallTestNorth = new Wall(Vec3(-12.0f, 0.0f, bWallXStart), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'b');
		else
			BwallTestNorth = new Wall(Vec3(-12.0f, 0.0f, bWallXStart), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'w');

		theWalls.push_back(BwallTestNorth);
	}

	float bWallzStart = -12.0f;
	for (int a = 0; a < 1; a++)
	{
		bWallzStart -= 2.0f;

		Wall* BwallTest = new Wall(Vec3(bWallzStart, 0.0f, -10.0f), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'w');
		Wall* BwallTestN = new Wall(Vec3(bWallzStart, 0.0f, -18.0f), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'w');

		theWalls.push_back(BwallTest);
		theWalls.push_back(BwallTestN);
	}

	float bWallxzStart = -18.0f;
	for (int a = 0; a < 3; a++)
	{
		bWallxzStart += 2.0f;

		Wall* BwalzlTest = new Wall(Vec3(-16.0f, 0.0f, bWallxzStart), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'w');

		theWalls.push_back(BwalzlTest);
	}

	// SecurityRoomDoor
	float sWallxzStart = -12.0f;
	Wall* SwalzlTest;

	for (int a = 0; a < 5; a++)
	{
		sWallxzStart -= 2.0f;

		if (sWallxzStart == -14.0f)
			SwalzlTest = new Wall(Vec3(sWallxzStart, 0.0f, 0.0f), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 's');
		else
			SwalzlTest = new Wall(Vec3(sWallxzStart, 0.0f, 0.0f), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'w');

		theWalls.push_back(SwalzlTest);
	}

	// PowerRoomDoor
	float pWallxzStart = -12.0f;
	for (int a = 0; a < 5; a++)
	{
		Wall* PwalzlTest;

		pWallxzStart -= 2.0f;
		PwalzlTest = new Wall(Vec3(pWallxzStart, 0.0f, 10.0f), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'w');

		theWalls.push_back(PwalzlTest);
	}

	// ERoomWalls DOOR
	float EWallXStart = -10.0f;
	for (int a = 0; a < 15; a++)
	{
		EWallXStart += 2.0f;

		Wall* EwallTestNorth;

		if (EWallXStart == 12.0f)
			EwallTestNorth = new Wall(Vec3(-12.0f, 0.0f, EWallXStart), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'g');
		else
			EwallTestNorth = new Wall(Vec3(-12.0f, 0.0f, EWallXStart), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'w');

		theWalls.push_back(EwallTestNorth);
	}

	// DRoom DOORS
	float DWallZStart = -10.0f;
	for (int a = 0; a < 9; a++) // Until northWallZEnd
	{
		DWallZStart += 2.0f;

		Wall* DwallTest;
		Wall* DwallTestSOUTH;

		if (DWallZStart == -6.0f)
			DwallTest = new Wall(Vec3(8.0f, 0.0f, DWallZStart), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'd');
		else
			DwallTest = new Wall(Vec3(8.0f, 0.0f, DWallZStart), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'w');

		if (DWallZStart == -6.0f)
			DwallTestSOUTH = new Wall(Vec3(-8.0f, 0.0f, DWallZStart), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'D');
		else
			DwallTestSOUTH = new Wall(Vec3(-8.0f, 0.0f, DWallZStart), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'w');

		theWalls.push_back(DwallTest);
		theWalls.push_back(DwallTestSOUTH);
	}

	// DroomEASTWEST
	float DWallXStart = 8.0f;
	for (int a = 0; a < 7; a++)
	{
		DWallXStart -= 2.0f;

		Wall* DwallTest = new Wall(Vec3(DWallXStart, 0.0f, -10.0f), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'w');
		Wall* DwallTesteast = new Wall(Vec3(DWallXStart, 0.0f, 10.0f), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'w');

		theWalls.push_back(DwallTest);
		theWalls.push_back(DwallTesteast);
	}

	// FRoom door
	float FWallZStart = 14.0f;
	for (int a = 0; a < 3; a++)
	{
		FWallZStart += 2.0f;

		Wall* DwallTestSOUTH;
		Wall* DwallTest = new Wall(Vec3(8.0f, 0.0f, FWallZStart), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'w');

		if (FWallZStart == 20.0f)
			DwallTestSOUTH = new Wall(Vec3(-8.0f, 0.0f, FWallZStart), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'f');
		else
			DwallTestSOUTH = new Wall(Vec3(-8.0f, 0.0f, FWallZStart), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'w');

		theWalls.push_back(DwallTest);
		theWalls.push_back(DwallTestSOUTH);
	}

	// Froom
	float FWallXStart = 8.0f;
	for (int a = 0; a < 7; a++) // Until northWallZEnd
	{
		FWallXStart -= 2.0f;

		Wall* FwallTest = new Wall(Vec3(FWallXStart, 0.0f, 14.0f), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'w');

		theWalls.push_back(FwallTest);
	}

	// CRoom
	float CWallZStart = 20.0f;
	for (int a = 0; a < 3; a++)	// Until northWallZEnd
	{
		CWallZStart -= 2.0f;

		Wall* CwallTest = new Wall(Vec3(CWallZStart, 0.0f, -18.0f), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'w');
		Wall* CwallTestSOUTH;

		if (CWallZStart == 18.0f)
			CwallTestSOUTH = new Wall(Vec3(CWallZStart, 0.0f, 10.0f), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'c');
		else
			CwallTestSOUTH = new Wall(Vec3(CWallZStart, 0.0f, 10.0f), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'w');

		theWalls.push_back(CwallTest);
		theWalls.push_back(CwallTestSOUTH);
	}

	// Croom
	float CWallXStart = -18.0f;
	for (int a = 0; a < 13; a++)
	{
		CWallXStart += 2.0f;

		Wall* CwallTest = new Wall(Vec3(12.0f, 0.0f, CWallXStart), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'w');

		theWalls.push_back(CwallTest);
	}
#pragma endregion

#pragma region PickUps
	// Weapon
	Wall* wpPickup = new Wall(Vec3(6.0f, 0.0f, 16.0f), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'o');
	// Health
	Wall* hpPickup = new Wall(Vec3(-6.0f, 0.0f, -28.0f), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'h');
	// Key
	Wall* kpPickup = new Wall(Vec3(-18.0f, 0.0f, 8.0f), 0.0f, Vec3(0.0f, 1.0f, 0.0f), cameraFPS, NULL, 'k');

	// Add them to the list
	theWalls.push_back(wpPickup);
	theWalls.push_back(hpPickup);
	theWalls.push_back(kpPickup);
#pragma endregion
}

SceneCombination::~SceneCombination()
{
	// Debug information
	Debug::Info("Deleted SceneÇombination: ", __FILE__, __LINE__);
}

bool SceneCombination::OnCreate()
{
	// Debug information
	Debug::Info("Loading assets SceneCombination: ", __FILE__, __LINE__);

	// Create camera and call OnCreate
	cameraFPS = new CameraActorFPS(nullptr);
	cameraFPS->OnCreate();

	// Create the player gun and call OnCreate
	playerGun = new PlayerGun(Vec3(1.0f, -0.5f, 8.0f), 0.0f, Vec3(0, 0, 0), cameraFPS, nullptr);
	playerGun->OnCreate();

	// For every wall, call OnCreate
	for (Wall* wall : theWalls)
		wall->OnCreate();

	// Create shader
	shader = new Shader(nullptr, "shaders/multilightVert.glsl", "shaders/multilightFrag.glsl");
	if (shader->OnCreate() == false)	// Debug information
		Debug::Error("Can't load shader in SceneCombination", __FILE__, __LINE__);

	// Set light positions
	lightPos[0] = Vec3(3.0f, 0.0f, -6.5f);
	lightPos[1] = Vec3(-3.0f, 0.0f, -6.5f);
	lightPos[2] = Vec3(0.0f, 3.0f, -6.5f);
	lightPos[3] = Vec3(0.0f, -3.0f, -6.5f);

	// Set diffuse values
	diffuse[0] = Vec4(0.6f, 0.0f, 0.0f, 0.0f);
	diffuse[1] = Vec4(0.0f, 0.6f, 0.0f, 0.0f);
	diffuse[2] = Vec4(0.0f, 0.0f, 0.6f, 0.0f);
	diffuse[3] = Vec4(0.6f, 0.6f, 0.6f, 0.0f);

	// Set specular values
	specular[0] = 0.5 * diffuse[0];
	specular[1] = 0.5 * diffuse[1];
	specular[2] = 0.5 * diffuse[2];
	specular[3] = 0.5 * diffuse[3];

	CreateNodeLayout();

	// Create the graph, an empty graph
	graph = new Graph();
	if (!graph->OnCreate(nodes)) {
		cout << "Graph OnCreate false!" << endl;
		return false;
	}

	CalculateConnectionWeights();

	// Print the neighbours of give node
	printf("Neighbours of 0: \n");
	int nodeLabel;
	for (auto nodeLabel : graph->GetNeighbours(0))
		printf("Node %i, ", nodeLabel);

	// Get shortest path from node to give node
	vector<int> path = graph->Dijkstra(0, 3);
	cout << "Path size: " << path.size() << endl;
	if (path.size() > 0)
	{
		for (int i = 0; i < path.size(); i++)
			cout << "Path " << i << ": " << path[i] << endl;
	}
	else if (path.size() <= 0)
		cout << "You can't get there from here!" << endl;

	/**
	for (int i = 0; i < gridHeight; i++) {

		for (int j = 0; j < gridWidth; j++)
		{
			cout << "Tile [" << i << "][" << j << "]: ";
			tiles[i][j]->GetPos().print();
		}
	}
	/**/

	cout << "Tile Pos: "; tiles[0][0]->GetPos().print();
	cout << "Node Pos: "; tiles[0][0]->GetNode()->GetPos().print();

	// Return true so program can run
	return true;
}

void SceneCombination::OnDestroy()
{
	// Debug information
	Debug::Info("Deleting assets SceneCombination: ", __FILE__, __LINE__);

	// If camera exists, call OnDestroy and delete
	if (cameraFPS)
	{
		cameraFPS->OnDestroy();
		delete cameraFPS;
	}

	// If shader exists, call OnDestroy and delete
	if (shader)
	{
		shader->OnDestroy();
		delete shader;
	}

	if (playerGun)
	{
		playerGun->OnDestroy();
		delete playerGun;
	}
}

void SceneCombination::Render() const
{
	/// Clear the screen
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Enable depth and culling
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	// Render the camera
	cameraFPS->Render();

	// Set matrices
	glUseProgram(shader->GetProgram());
	glUniformMatrix4fv(shader->GetUniformID("projectionMatrix"), 1, GL_FALSE, cameraFPS->GetProjectionMatrix());
	glUniformMatrix4fv(shader->GetUniformID("viewMatrix"), 1, GL_FALSE, cameraFPS->GetViewMatrix());

	// Set uniforms
	glUniform3fv(shader->GetUniformID("lightPos[0]"), 10, *lightPos);
	glUniform4fv(shader->GetUniformID("diffuse[0]"), 10, *diffuse);
	glUniform4fv(shader->GetUniformID("specular[0]"), 10, *specular);

	// Render the gun of the player
	playerGun->Render();

	// Render all the walls
	for (Wall* wall : theWalls)
		wall->Render();

	for (int i = 0; i < gridHeight; i++) {

		for (int j = 0; j < gridWidth; j++)
		{
			//cout << "Tile [" << i << "][" << j << "]: ";
			if (tiles[i][j]->HasNode())
				tiles[i][j]->GetNode()->Render();
		}
	}

	// Use program 0
	glUseProgram(0);
}

void SceneCombination::Update(const float deltaTime)
{
	// Update the camera
	cameraFPS->Update(deltaTime);

	// Update the gun of the player
	playerGun->Update(deltaTime);

	// Update all the colliders
	for (Box* roomTriggerBox : roomTriggers)
	{
		// Check if the player has triggered/collided with room box
		int playerPickupCollision = Collision::TestSphereSphere(*playerColliderBox, *roomTriggerBox);
		if (playerPickupCollision == true)
		{
			// Get enemy closer to player																					
			Vec3 enemyMove2Player = VMath::normalize(cameraFPS->GetCameraFPSPos() - roomTriggerBox->enemyRoom->GetPosition());
			Vec3 enemyTranslation = enemyMove2Player * 2.0f;
			roomTriggerBox->enemyRoom->setPositionEnemy(enemyTranslation);
		}
		else  // Enemy is static or returns to enemy	
			roomTriggerBox->enemyRoom->setPositionEnemy(roomTriggerBox->enemyRoom->originalPos);
	}

	// Debug
	//cout << "CameraPos Scene: ";
	//cameraFPS->GetCameraFPSPos().print();
}

void SceneCombination::HandleEvents(const SDL_Event& sdlEvent)
{
	// Handle events of camera
	cameraFPS->HandleEvents(sdlEvent);

	// Handle events of the player gun
	playerGun->HandleEvents(sdlEvent);
}

void SceneCombination::CreateNodeLayout()
{
	// Level layout (x value = gridWidth and y value = gridHeight) (first number = y, second number = x)
	// rows = x & columns = y
	int levelData[27][23] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	};

	tiles.resize(gridHeight);

	for (int i = 0; i < gridHeight; i++)
		tiles[i].resize(gridWidth);

	Node* n;
	NodeTile* t;
	int i, j, label;
	i = 0;
	j = 0;
	label = 0;

	for (int row = 0; row < gridHeight; row++)
	{
		for (int column = 0; column < gridWidth; column++)
		{
			int id = levelData[row][column];

			// Position in pixels
			Vec3 startPos = Vec3(-25.0f, 0.0f, -31.0f);	// X = -26.0f || Z = -32.0f
			Vec3 endPos = Vec3(0.0f, 0.0f, 0.0f);

			// Set the position to have the origin top left
			endPos.x = (startPos.x + column * tileWidth + (tileWidth * 0.5f));
			endPos.y = 0.0f;
			endPos.z = (startPos.z + row * tileHeight + (tileHeight * 0.5f));

			// Transverse the position from viewport to game
			Vec3 position = Vec3(endPos.x, endPos.y, endPos.z);

			cout << "Position in function: ";
			position.print();

			// Set node
			n = new Node(label, endPos);
			nodes.push_back(n);

			// Set the background tile
			if (id == 1)
				t = new NodeTile(n, true);
			else
				t = new NodeTile(n, false);

			// Set the tile
			t->AddTile(column, row, id, label, tileWidth, tileHeight, startPos);
			tiles[row][column] = t;

			// Increase the node label
			label++;
		}
	}
}

void SceneCombination::CalculateConnectionWeights()
{
	int rows = gridHeight;
	int columns = gridWidth;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			//						i+1, j
			//		i, j-1			  i, j			 i, j+1
			//						i-1, j

			int from = tiles[i][j]->GetNode()->GetLabel();

			// Left is i, j-1
			if (j > 0 && tiles[i][j - 1]->HasNode()) {
				int to = tiles[i][j - 1]->GetNode()->GetLabel();
				graph->AddWeightConnection(from, to, tileWidth);
			}

			// Right is i, j+1
			if (j < columns - 1 && tiles[i][j + 1]->HasNode()) {
				int to = tiles[i][j + 1]->GetNode()->GetLabel();
				graph->AddWeightConnection(from, to, tileWidth);
			}

			// Above is i+1, j
			if (i < rows - 1 && tiles[i + 1][j]->HasNode()) {
				int to = tiles[i + 1][j]->GetNode()->GetLabel();
				graph->AddWeightConnection(from, to, tileWidth);
			}

			// Below is i-1, j
			if (i > 0 && tiles[i - 1][j]->HasNode()) {
				int to = tiles[i - 1][j]->GetNode()->GetLabel();
				graph->AddWeightConnection(from, to, tileWidth);
			}
		}
	}
}
