#include "PacketProc.h"
#include "packet.h"
#include <iostream>

#include "MainApp.h"

PacketProc::PacketProc()
{

}


PacketProc::~PacketProc()
{

}


//�����û���¼��
void PacketProc::OnPacket(tcp_session_ptr &session, login_packet *packet)
{
}



//���������ͻ��˸�����ѵ�¼
void PacketProc::NotifyOtherClient(const std::string& strName)
{

}