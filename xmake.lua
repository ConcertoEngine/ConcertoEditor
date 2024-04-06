add_rules("mode.debug")
add_rules("plugin.vsxmake.autoupdate")

add_repositories("Concerto-xrepo https://github.com/ConcertoEngine/xmake-repo.git main")

add_requires("ConcertoCore", {configs = { debug = is_mode("debug"), with_symbols = true}})
add_requires("juce", {configs = { debug = is_mode("debug"), with_symbols = true, core = true, graphics = true, gui_basics = true, gui_extra = true}})

target("ConcertoEditor")
    set_kind("binary")
    set_languages("cxx20")
    if is_mode("debug") then
        set_symbols("debug")
    end
    add_packages("ConcertoCore", "juce")
    add_files("Src/**.cpp")
    add_includedirs("Include", "Include/Concerto/Editor")
    add_headerfiles("Include/Concerto/Editor/**.hpp")
    add_defines("CONCERTO_EDITOR_BUILD")