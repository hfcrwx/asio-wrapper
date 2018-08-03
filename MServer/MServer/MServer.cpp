#include "MServer.h"
#include "packet.h"
#include "PacketProc.h"

MServer::MServer(int nPort):ServerNetwork(nPort)
{
	m_pPacketProc = boost::make_shared<PacketProc>();
	std::cout<<"start MServer..."<<std::endl;
}


MServer::~MServer()
{

}

bool MServer::proc_connect(tcp_session_ptr &session)
{
	std::cout<<"proc_connect"<<std::endl;
	return true;
}


bool MServer::proc_disconnect(tcp_session_ptr &session)
{
	std::cout<<"proc_disconect"<<std::endl;
	return true;
}


bool MServer::proc_packet(tcp_session_ptr &session, serial_packet *packet)
{
	switch(packet->get_packet_type())
	{
	case PACKET_REGISTER:
		{
			
		}
		break;
	case PACKET_LOGIN:
		{
			login_packet *pkt = dynamic_cast<login_packet*>(packet);
			m_pPacketProc->OnPacket(session, pkt);
		}
		break;
	case PACKET_LOGOUT:
		{

		}
		break;

	default:
		break;
	}
	return true;
}



void MServer::proc_registerpacket()
{
	register_packet<login_packet>(PACKET_LOGIN);
}

void MServer::SendPacket(tcp_session_ptr& session, serial_packet& packet)
{
	send_packet(session, packet);
}