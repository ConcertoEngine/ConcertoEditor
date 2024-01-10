//
// Created by arthur on 06/01/2024.
//

#ifndef CONCERTO_EDITOR_WINDOW_HPP
#define CONCERTO_EDITOR_WINDOW_HPP

#include <string_view>

#include <Ultralight/RefPtr.h>
#include <AppCore/Window.h>

#include "Concerto/Editor/Export.hpp"

namespace ultralight
{
	class Monitor;
	class Window;
}

namespace Concerto
{
	class CONCERTO_EDITOR_API EWindow
	{
	public:
		enum class Flag
		{
			Borderless = 1 << 0,
			Titled = 1 << 1,
			Resizable = 1 << 2,
			Maximizable = 1 << 3,
			Hidden = 1 << 4,
		};

		EWindow(ultralight::Monitor* monitor, UInt32 width, UInt32 height, std::string_view title, UInt32 flags, bool fullscreen = false);
	private:
		ultralight::RefPtr<ultralight::Window> _window;
	};
}

#endif //CONCERTO_EDITOR_WINDOW_HPP