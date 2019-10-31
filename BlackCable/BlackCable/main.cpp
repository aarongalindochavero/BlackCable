#include "GameStateManager.h"
#include "Menu.h"
int main(int argc, char* argv[])
{
	auto gameStateManager = GameStateManager::getPtr();
	//gameStateManager->SetState(new Menu());
	gameStateManager.GameLoop();
	return 0
}
//1.-Dejar compilando el projecto
//2.-Hacer una clase piramide piramide con textura
//3.-Hacer una clase transform que permita parametrizar scala,translacion y rotacion la clase debara tener los metodos:
//		setTranslation(x,y,z)
//		setScale(x,y,z)
//		setRotation(x,y,z)
//4.-Hacer que la variables del color y posicion de las luces de ambient, difuse, especular sean configurables desde el programa
//5.-Al final la piramide debe estar rotando en el eje Z, transladada y escalada la mitad de su tamaño,
//ademas la luz debe estar moviendose de izquierda a derecha y cambiando de color cada cierto tiempo.