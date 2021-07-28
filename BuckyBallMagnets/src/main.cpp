#include "classes/graphics/UIManager.h"
#include "classes/scene/Scene.h"

int main() {
	UIManager ui{ 800, 800 };
	Scene scene{};
	
	while (ui.isOpen()) {
		ui.draw(scene);
		ui.update();
	}
	
	return 0;
}