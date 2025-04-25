-- set minimum xmake version
set_xmakever("2.8.2")

-- set project
set_project("commonlibob64")
set_languages("c++23")
set_warnings("allextra")
set_encodings("utf-8")

-- add rules
add_rules("mode.debug", "mode.releasedbg")

-- require packages
add_requires("rsm-mmio")
add_requires("spdlog", { configs = { header_only = false, wchar = true, std_format = true } })

-- include subprojects
includes("CommonLibOB64")
