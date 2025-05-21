-- set minimum xmake version
set_xmakever("2.8.2")

-- set project
set_project("commonlibob64")
set_languages("c++23")
set_warnings("allextra")
set_encodings("utf-8")

-- add repositories
add_repositories("libxse-xrepo https://github.com/libxse/libxse-xrepo")

-- add rules
add_rules("mode.debug", "mode.releasedbg")

-- make custom rules available
includes("xmake-rules.lua")

-- define options
option("commonlib_ini", function()
    set_default(false)
    set_description("enable ini config support for REX")
end)

option("commonlib_json", function()
    set_default(false)
    set_description("enable json config support for REX")
end)

option("commonlib_toml", function()
    set_default(false)
    set_description("enable toml config support for REX")
end)

option("commonlib_xbyak", function()
    set_default(false)
    set_description("enable xbyak support for trampoline")
end)

-- require packages
add_requires("commonlib-shared 4830431543103648ac6ff53ff74ae945bc85b70f", { configs = {
    ini = has_config("commonlib_ini"),
    json = has_config("commonlib_json"),
    toml = has_config("commonlib_toml"),
    xbyak = has_config("commonlib_xbyak")
}})

-- define targets
target("commonlibob64", function()
    -- set target kind
    set_kind("static")

    -- set build by default
    set_default(os.scriptdir() == os.projectdir())

    -- add packages
    add_packages("commonlib-shared", { public = true })

    -- add source files
    add_files("src/**.cpp")

    -- add header files
    add_includedirs("include", { public = true })
    add_headerfiles(
        "include/(OBSE/**.h)",
        "include/(RE/**.h)"
    )

    -- add extra files
    add_extrafiles("res/commonlibob64.natvis")

    -- set precompiled header
    set_pcxxheader("include/OBSE/Impl/PCH.h")

    -- add flags
    add_cxxflags("/EHsc", "/permissive-", { public = true })

    -- add flags (cl)
    add_cxxflags(
        "cl::/bigobj",
        "cl::/cgthreads8",
        "cl::/diagnostics:caret",
        "cl::/external:W0",
        "cl::/fp:contract",
        "cl::/fp:except-",
        "cl::/guard:cf-",
        "cl::/Zc:preprocessor",
        "cl::/Zc:templateScope"
    )

    -- add flags (cl: disable warnings)
    add_cxxflags(
        "cl::/wd4200", -- nonstandard extension used : zero-sized array in struct/union
        "cl::/wd4201", -- nonstandard extension used : nameless struct/union
        "cl::/wd4324", -- structure was padded due to alignment specifier
        { public = true }
    )

    -- add flags (cl: warnings -> errors)
    add_cxxflags(
        "cl::/we4715", -- not all control paths return a value
        { public = true }
    )
end)
