#include "Reamor.h"

Reamor::Reamor()
{
}

Reamor::~Reamor()
{
}

void Reamor::moveUp() { m_drawable.rect.y -= m_speed; }
void Reamor::moveDown() { m_drawable.rect.y += m_speed; }
void Reamor::moveLeft() { m_drawable.rect.x -= m_speed; }
void Reamor::moveRight() { m_drawable.rect.x += m_speed; }
