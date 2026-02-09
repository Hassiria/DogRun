#include "entities/Entity.h"

Entity::Entity(glm::vec2 position, glm::vec2 size)
    : position(position), size(size)
{
}

glm::vec2 Entity::GetPosition() const
{
    return position;
}

glm::vec2 Entity::GetSize() const
{
    return size;
}
