#include "OBSE/Logger.h"
#include "OBSE/API.h"

#include "REX/W32/OLE32.h"
#include "REX/W32/SHELL32.h"

namespace OBSE::log
{
	std::optional<std::filesystem::path> log_directory()
	{
		wchar_t*                                                       buffer{ nullptr };
		const auto                                                     result = REX::W32::SHGetKnownFolderPath(REX::W32::FOLDERID_Documents, REX::W32::KF_FLAG_DEFAULT, nullptr, std::addressof(buffer));
		std::unique_ptr<wchar_t[], decltype(&REX::W32::CoTaskMemFree)> knownPath(buffer, REX::W32::CoTaskMemFree);
		if (!knownPath || result != 0) {
			REX::ERROR("failed to get known folder path"sv);
			return std::nullopt;
		}

		std::filesystem::path path = knownPath.get();
		path /= std::format("My Games/{}/OBSE/Logs", OBSE::GetSaveFolderName());
		return path;
	}
}
