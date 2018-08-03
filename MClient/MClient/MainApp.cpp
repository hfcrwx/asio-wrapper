#include "MainApp.h"
#include "MClient.h"

#include <boost/make_shared.hpp>

MainApp::MainApp()
{
	
}


MainApp::~MainApp()
{

}


void MainApp::ConnectServer(std::string strIP, int nPort)
{
	if (!m_pClient)
	{
		ip::tcp::endpoint ep(ip::address::from_string(strIP), nPort);
		m_pClient = boost::make_shared<MClient>(ep);
	}
	m_pClient->Start();
}

void MainApp::SendPacket(serial_packet &packet)
{
	if (m_pClient)
	{
		m_pClient->SendPacketToServer(packet);
	}
}

void MainApp::InitAppInstance()
{
	ConnectServer("127.0.0.1");
}
