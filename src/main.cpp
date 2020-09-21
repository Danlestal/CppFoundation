#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#undef RAYGUI_IMPLEMENTATION            // Avoid including raygui implementation again

#include "./engine/events/EventManager.hpp"
#include "./engine/events/TickEventData.hpp"
#include "./engine/IdentifierProvider.hpp"
#include "./engine/RandomIdProvider.hpp"
#include "./engine/KeyboardInputManager.hpp"
#include "./engine/Scene.hpp"
#include "./engine/systems/LogicSystem.hpp"
#include "./engine/systems/RenderSystem.hpp"
#include "./engine/systems/PhysicsSystem.hpp"
#include "./engine/systems/UIRenderingSystem.hpp"
#include "./game/ActorFactory.hpp"
#include "./engine/DebugProbe.hpp"



int main(void) {
    Vector2D nativeResolution = {1024, 768};
    InitWindow(nativeResolution.x, nativeResolution.y, "Invaders");
    bool editMode = true;


    SetTargetFPS(60);
    EventManager* eventManager = new EventManager();
    Scene* scene = new Scene(eventManager);
    RenderSystem* view = new RenderSystem(scene);
    LogicSystem* logic = new LogicSystem(scene);
    PhysicsSystem* phys = new PhysicsSystem(scene);
    IdentifierProvider *idProvider = new RandomIdProvider();

    // ALL THIS CRAPOLA SHOULD BE PLACED INSIDE THE MECHANISM TO
    // PARSE THE XML FROM THE SCENE
    ResourceManager resources = ResourceManager();
    resources.loadTexture("xenon2_textures", "./resources/xenon2_sprites.png");
    ActorFactory *factory = new ActorFactory(idProvider, scene, eventManager, resources, nativeResolution);
    Actor* spaceShip = factory->createPlayerSpaceship();
    scene->addActor(spaceShip);
    std::vector<Actor*> boundaries = factory->createBoundaries();
    for (auto it = boundaries.begin(); it != boundaries.end(); ++it) {
         Actor* actor = (*it);
         scene->addActor(actor);
    }
    // scene->addActor(factory->createInvader());
    // scene->addActor(factory->createScoreboard());
    // PARSE THE XML FROM THE SCENE END

    Vector2 cameraOffset = { nativeResolution.x/2, nativeResolution.y/2 };
    Camera2D rayCamera;
    rayCamera.target = cameraOffset;
    rayCamera.offset = cameraOffset;
    rayCamera.rotation = 0.0f;
    rayCamera.zoom = 1.0f;
    Actor* camera = factory->createCameraComponent(&rayCamera);
    scene->addActor(camera);

    UIRenderingSystem* editorView = new UIRenderingSystem(scene, camera, cameraOffset);
    editorView->init();

    KeyboardInputManager inputManager = KeyboardInputManager(eventManager);
    TickEventData* tick = new TickEventData();
    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_F1)) {
             editMode = !editMode;
        }

        eventManager->update();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode2D(rayCamera);
        view->draw();
        if (editMode) {
            editorView->draw();
            inputManager.proccessEditorInput(camera->getId());
        } else {
            inputManager.proccessPlayerInput(spaceShip->getId());
            logic->updateLogic();
        }
        eventManager->queueEvent(tick);
        EndDrawing();
    }
    CloseWindow();

    delete phys;
    delete idProvider;
    delete logic;
    delete view;
    delete eventManager;
    delete scene;

    return 0;
}
