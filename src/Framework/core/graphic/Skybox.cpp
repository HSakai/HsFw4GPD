#include "Skybox.h"

using namespace gameplay;

namespace HsEngine
{
    Skybox* Skybox::create (const char* materialPath, const char* nodeName)
    {
        Bundle* skyboxBundle = Bundle::create ("res/skybox/skybox.gpb");
        Node* skyboxNode = skyboxBundle->loadNode ("sphere");
        Model* skyboxModel = static_cast<Model*> (skyboxNode->getDrawable ());
        skyboxModel->setMaterial (Material::create (materialPath));
        SAFE_RELEASE (skyboxBundle);

        Skybox* skybox = new Skybox (nodeName);
        skybox->addChild (skyboxNode);
        return skybox;
    }

    Skybox::Skybox (const char* id) :
        Node (id)
    {
    }

    Skybox::~Skybox ()
    {
    }
}
