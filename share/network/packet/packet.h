#ifndef _LOGIN_PACKET_H
#define _LOGIN_PACKET_H

#include "serial_packet.h"
#include <boost/serialization/vector.hpp>
using namespace boost;
#include "ack_code.h"

//////////////////////////////////////////////////////////////////////////
//��������
class heart_packet:public serial_packet
{
	_SERIALIZATION_PACKET()
public:
	heart_packet():serial_packet(PACKET_HEART){}
private:
	template<class Archive>
	void serialize( Archive & ar, const unsigned int version)
	{
		ar & m_nHour & m_nMin & m_nSec & m_nMilSec;
	}
public:
	int m_nHour;
	int m_nMin;
	int m_nSec;
	int m_nMilSec;
};

//////////////////////////////////////////////////////////////////////////
//��¼��
class login_packet:public serial_packet
{
	_SERIALIZATION_PACKET()
public:
	login_packet():serial_packet(PACKET_LOGIN){}
private:
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & m_strName & m_strPwd;
	}
public:
	std::string m_strName;
	std::string m_strPwd;
};


//////////////////////////////////////////////////////////////////////////
//��¼�ظ���
class ack_login_packet:public serial_packet
{
	_SERIALIZATION_PACKET()
public:
	ack_login_packet():serial_packet(PACKET_ACK_LOGIN){}
private:
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & m_code;
	}
public:
	//bool m_bLoginSuccess;   //true �ɹ�   false ʧ��
	ack_code   m_code;
};


//////////////////////////////////////////////////////////////////////////
//ע���
class register_packet:public serial_packet
{
	_SERIALIZATION_PACKET()
public:
	register_packet():serial_packet(PACKET_REGISTER){}
private:
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & m_strName & m_strPwd;
	}
public:
	std::string m_strName;
	std::string m_strPwd;
};


//////////////////////////////////////////////////////////////////////////
//ע��ظ���
class ack_register_packet:public serial_packet
{
	_SERIALIZATION_PACKET()
public:
	ack_register_packet():serial_packet(PACKET_ACK_REGISTER){}
private:
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & m_code;
	}
public:
	ack_code m_code;
};


//ע��
class logout_packet: public serial_packet
{
	_SERIALIZATION_PACKET()
public:
	logout_packet():serial_packet(PACKET_LOGOUT){}
private:
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & m_strName;
	}
public:
	std::string m_strName;
};

//////////////////////////////////////////////////////////////////////////
//֪ͨ�������������Ҽ���
class add_client_packet: public serial_packet
{
	_SERIALIZATION_PACKET()
public:
	add_client_packet():serial_packet(PACKET_ADD_CLIENT){}
private:
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & m_strName;
	}
public:
	std::string m_strName;
};


//////////////////////////////////////////////////////////////////////////
////֪ͨ�������������˳�
class remove_client_packet: public serial_packet
{
	_SERIALIZATION_PACKET()
public:
	remove_client_packet():serial_packet(PACKET_REMOVE_CLIENT){}
private:
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & m_strName;
	}
public:
	std::string m_strName;
};

//////////////////////////////////////////////////////////////////////////
////ĳһ����ҵ���Ϣ
class clientinfo_packet: public serial_packet
{
	_SERIALIZATION_PACKET()
public:
	clientinfo_packet():serial_packet(PACKET_CLIENTINFO){}
private:
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & m_strName;
	}
public:
	std::string m_strName;
};


//��������б�
class all_client_packet: public serial_packet
{
	_SERIALIZATION_PACKET()
public:
	all_client_packet():serial_packet(PACKET_ALL_CLIENTINFO){}
private:
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & m_vClientInfo;
	}
public:
	std::vector<clientinfo_packet> m_vClientInfo;
};



#endif