#ifndef ENTITY_H
#define ENTITY_H

#include <glm/glm.hpp>

class Renderer2D;

class Entity
{
public:
    Entity(glm::vec2 position, glm::vec2 size);
    virtual ~Entity() = default;

    virtual void Update(float deltaTime) = 0;
    virtual void Render(Renderer2D& renderer) = 0;

    glm::vec2 GetPosition() const;
    glm::vec2 GetSize() const;

protected:
    glm::vec2 position;
    glm::vec2 size;
};

#endif
