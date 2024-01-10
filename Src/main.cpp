#include "Concerto/Editor/Editor.hpp"

using namespace Concerto;
int main()
{
	Editor editor;
	EWindow& window = editor.CreateWindow(800, 900, "ConcertoEditor", 0, false);

	editor.Run();
    return 0;
}