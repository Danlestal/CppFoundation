#include <iostream>
#include "raylib.h"


#include "./engine/events/EventManager.hpp"
#include "./engine/events/TickEventData.hpp"
#include "./engine/IdentifierProvider.hpp"
#include "./engine/RandomIdProvider.hpp"
#include "./engine/KeyboardInputManager.hpp"
#include "./engine/Scene.hpp"
#include "./engine/systems/LogicSystem.hpp"
#include "./engine/systems/RenderSystem.hpp"
#include "./engine/systems/PhysicsSystem.hpp"
#include "./game/ActorFactory.hpp"
#include "./engine/DebugProbe.hpp"



int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib");

    SetTargetFPS(60);
    EventManager* eventManager = new EventManager();
    Scene* scene = new Scene(eventManager);
    RenderSystem* view = new RenderSystem(scene);
    LogicSystem* logic = new LogicSystem(scene);
    PhysicsSystem* phys = new PhysicsSystem(scene, eventManager);
    phys->init();  // This should be called inside the constructor. Probably.

    // ALL THIS CRAPOLA SHOULD BE PLACED INSIDE THE MECHANISM TO
    // PARSE THE XML FROM THE SCENE
    IdentifierProvider *idProvider = new RandomIdProvider();
    ActorFactory *factory = new ActorFactory(idProvider, scene, eventManager);

    Actor* spaceShip = factory->createPlayerSpaceship();
    scene->addActor(spaceShip);
    std::vector<Actor*> boundaries = factory->createBoundaries(400, 420);
    for (auto it = boundaries.begin(); it != boundaries.end(); ++it) {
        Actor* actor = (*it);
        scene->addActor(actor);
    }
    // PARSE THE XML FROM THE SCENE END
    KeyboardInputManager inputManager = KeyboardInputManager(spaceShip->getId(), eventManager);
    DebugProbe probe = DebugProbe(spaceShip);

    TickEventData* tick = new TickEventData();
    while (!WindowShouldClose()) {
        inputManager.proccessInput();
        eventManager->update();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        view->draw();
        logic->updateLogic();
        probe.display();
        EndDrawing();
        eventManager->queueEvent(tick);
    }
    CloseWindow();

    return 0;
}
