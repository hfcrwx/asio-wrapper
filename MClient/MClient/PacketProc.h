#ifndef _PACKETPROC_H
#define _PACKETPROC_H

#include "packet.h"

class PacketProc
{
public:
	PacketProc();
	~PacketProc();
public:
	void OnPacket(ack_login_packet* packet);
	void OnPacket(ack_register_packet* packet);
	void OnPacket(add_client_packet* packet);
	void OnPacket(remove_client_packet* packet);
	void OnPacket(all_client_packet* packet);
	void OnPacket(clientinfo_packet* packet);
};


#endif
