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


//处理用户登录包
void PacketProc::OnPacket(tcp_session_ptr &session, login_packet *packet)
{
}



//告诉其它客户端该玩家已登录
void PacketProc::NotifyOtherClient(const std::string& strName)
{

}