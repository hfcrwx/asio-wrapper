#ifndef _MCLIENT_H
#define _MCLIENT_H

#include "ClientNetwork.h"
#include "PacketProc.h"

class tcp_session;
class MClient:public ClientNetwork
{
public:
	MClient(tcp_type::endpoint ep, int nServicePoolNum = 4, int second_check = 1);
	~MClient();
public:
	bool proc_connect(tcp_session_ptr &session);
	bool proc_disconnect(tcp_session_ptr &session);
	bool proc_packet(tcp_session_ptr &session, serial_packet *packet);
	void proc_registerpacket();
public:
	void SendPacketToServer(serial_packet &packet);
private:
	tcp_session_ptr m_pServerSession;
	bool m_bConnected;

	boost::shared_ptr<PacketProc> m_pPacketProc;
};


#endif