#ifndef _PACKET_TYPE_H
#define _PACKET_TYPE_H

//�������Ҫ���������л��������ͣ�ͨ����������ʶ���
//�¼ӵİ�Ӧ���ڴ˴������Ӧ�İ�����

typedef enum empacket_type
{
	PACKET_DEFAULT = 0xffff,
	PACKET_HEART = 0x8000,
	
	PACKET_LOGIN,
	PACKET_ACK_LOGIN,

	PACKET_LOGOUT,
	PACKET_ACK_LOGOUT,

	PACKET_REGISTER,
	PACKET_ACK_REGISTER,

	PACKET_ADD_CLIENT,     
	PACKET_REMOVE_CLIENT,

	PACKET_CLIENTINFO,

	PACKET_ALL_CLIENTINFO,
	
	PACKET_DISCONNECT,
}packet_type;




#endif