#include <SFML/Graphics.hpp>
#include <screens.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main() {
	vector<Screen*> screens;
	int selectedScreen = 0;

	RenderWindow app(VideoMode(800,1080), "Nene Quest", Style::Close | Style::Titlebar);
    app.setFramerateLimit(60);

	screens.push_back(new Menu);
	screens.push_back(new Game);
	screens.push_back(new GameOver(ONE_PLAYER));
	screens.push_back(new GameOver(TWO_PLAYER));

	while (selectedScreen >= 0)
		selectedScreen = screens[selectedScreen]->run(app);
		
	return EXIT_SUCCESS;
}
