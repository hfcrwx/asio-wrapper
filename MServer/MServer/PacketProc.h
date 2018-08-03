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
	//���������ͻ��˸����������
	void NotifyOtherClient(const std::string& strName);
};

#endif