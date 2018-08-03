#include "PacketProc.h"
#include "MainApp.h"



PacketProc::PacketProc()
{

}

PacketProc::~PacketProc()
{

}


void PacketProc::OnPacket(ack_login_packet* packet)
{
	std::string strCodeString = GetAckCodeString(packet->m_code);
}

void PacketProc::OnPacket(ack_register_packet* packet)
{

}

void PacketProc::OnPacket(add_client_packet* packet)
{

}

void PacketProc::OnPacket(remove_client_packet* packet)
{

}

void PacketProc::OnPacket(all_client_packet* packet)
{

}

void PacketProc::OnPacket(clientinfo_packet* packet)
{

}
