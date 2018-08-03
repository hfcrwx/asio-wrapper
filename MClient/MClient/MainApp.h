#ifndef _MAINAPP_H
#define _MAINAPP_H

#include <boost/pool/detail/singleton.hpp>
using boost::details::pool::singleton_default;

using namespace boost;

#include <boost/shared_ptr.hpp>
#include <string>
class serial_packet;

using namespace std;

#include "MClient.h"


class MainApp
{
public:
	MainApp();
	~MainApp();
public:
	void InitAppInstance();

public:
	void ConnectServer(std::string strIP, int nPort = PORT_NUM);
	void SendPacket(serial_packet &packet);
private:
	boost::shared_ptr<MClient> m_pClient;

};

//创建单件
typedef singleton_default<MainApp> theApp;


#endif