/*#include "Smurf.h"
#include "Texturemanager.h"

Smurf::Smurf(Properties* props) : ObjectGame(props){
    row = 1;
    framecount = 10;
}

void Smurf::Draw() {
    Texturemanager::GetInstance()->DrawFrame("smurf", m_Transform->X, m_Transform->Y, m_Width, m_Height, row, frame);
}

void Smurf::Clean() {
}

void Smurf::Update(float dt) {
    frame = (SDL_GetTicks() / 100) % framecount;
}

void Smurf::MoveForward() {
    m_Transform->X += 5;
}

void Smurf::MoveBackward() {
    m_Transform->X -= 5;
}

void Smurf::Jump() {
}*/
