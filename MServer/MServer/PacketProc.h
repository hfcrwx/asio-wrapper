#ifndef _PACKETPROC_H
#define _PACKETPROC_H

#include "MServer.h"

class login_packet;
class PacketProc
{
public:
	PacketProc();
	~PacketProc();
public:
	void OnPacket(tcp_session_ptr &session, login_packet *packet);

private:
	//告诉其它客户端该玩家已连接
	void NotifyOtherClient(const std::string& strName);
};

#endif