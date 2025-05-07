#pragma once

namespace RE::UE
{
	namespace EAcceptConnection
	{
		enum class Type : std::int8_t;
	}

	class FInBunch;
	class UChannel;
	class UNetConnection;

	class FNetworkNotify
	{
	public:
		// add
		virtual EAcceptConnection::Type NotifyAcceptingConnection() = 0;                                     // 00
		virtual void                    NotifyAcceptedConnection(UNetConnection*) = 0;                       // 01
		virtual bool                    NotifyAcceptingChannel(UChannel*) = 0;                               // 02
		virtual void                    NotifyControlMessage(UNetConnection*, std::uint8_t, FInBunch*) = 0;  // 03
	};
	static_assert(sizeof(FNetworkNotify) == 0x08);
}
