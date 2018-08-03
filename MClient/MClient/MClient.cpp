#include "MClient.h"
#include "tcp_message.hpp"
#include "packet.h"
#include "MainApp.h"



MClient::MClient(tcp_type::endpoint ep, int nServicePoolNum, int second_check)
:ClientNetwork(ep, nServicePoolNum, second_check)
{
	m_bConnected = false;

	m_pPacketProc = boost::make_shared<PacketProc>();
}


MClient::~MClient()
{

}


bool MClient::proc_connect(tcp_session_ptr &session)
{
	m_bConnected      = true;
	m_pServerSession  = session;
	return true;
}

bool MClient::proc_disconnect(tcp_session_ptr &session)
{
	m_bConnected = false;
	return true;
}

bool MClient::proc_packet(tcp_session_ptr &session, serial_packet *packet)
{
	switch(packet->get_packet_type())
	{
	case PACKET_ACK_LOGIN:
		{
			ack_login_packet *pkt = dynamic_cast<ack_login_packet*>(packet);
			m_pPacketProc->OnPacket(pkt);
		}
		break;
	case PACKET_ACK_REGISTER:
		{

		}
		break;
	case PACKET_ADD_CLIENT:
		{

		}
		break;
	case PACKET_REMOVE_CLIENT:
		{

		}
		break;
	case PACKET_ALL_CLIENTINFO:
		{
			all_client_packet *pkt = dynamic_cast<all_client_packet*>(packet);
			m_pPacketProc->OnPacket(pkt);
		}
		break;
	case PACKET_CLIENTINFO:
		{

		}
		break;
	default:
		break;
	}
	return true;
}

void MClient::proc_registerpacket()
{
	register_packet<heart_packet>(PACKET_HEART);
	register_packet<ack_login_packet>(PACKET_ACK_LOGIN);
	register_packet<ack_register_packet>(PACKET_ACK_REGISTER);
	register_packet<add_client_packet>(PACKET_ADD_CLIENT);
	register_packet<remove_client_packet>(PACKET_REMOVE_CLIENT);
	register_packet<all_client_packet>(PACKET_ALL_CLIENTINFO);
	register_packet<clientinfo_packet>(PACKET_CLIENTINFO);
}

void MClient::SendPacketToServer(serial_packet &packet)
{
	if (m_bConnected)
	{
		send_packet(m_pServerSession, packet);
	}
}