//
// Created by arthur on 10/01/2024.
//

#ifndef CONCERTO_EDITOR_EDITOR_HPP
#define CONCERTO_EDITOR_EDITOR_HPP

#include <string_view>
#include <vector>

#include <Concerto/Core/Assert.hpp>
#include <AppCore/App.h>

#include "Concerto/Editor/Export.hpp"
#include "Concerto/Editor/EWindow.hpp"

namespace Concerto
{
	class CONCERTO_EDITOR_API Editor
	{
	public:
		Editor();
		~Editor() = default;
		Editor(Editor&&) = delete;
		Editor(const Editor&) = delete;

		Editor& operator=(Editor&&) = delete;
		Editor& operator=(const Editor&) = delete;

		static Editor* Instance();

		EWindow& CreateWindow(UInt32 width, UInt32 height, std::string_view title, UInt32 flags, bool fullscreen = false);
		void Run() const;
	private:
		static Editor* _instance;
		ultralight::RefPtr<ultralight::App> _app;
		std::vector<EWindow> _windows;
	};
}

#endif //CONCERTO_EDITOR_EDITOR_HPP
