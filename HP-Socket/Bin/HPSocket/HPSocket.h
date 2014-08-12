/*
 * Copyright: JessMA Open Source (ldcsaa@gmail.com)
 *
 * Version	: 3.2.3
 * Author	: Bruce Liang
 * Website	: http://www.jessma.org
 * Project	: https://github.com/ldcsaa
 * Blog		: http://www.cnblogs.com/ldcsaa
 * Wiki		: http://www.oschina.net/p/hp-socket
 * QQ Group	: 75375912
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/******************************************************************************
Module:  HPSocket DLL

Usage:
		����һ��
		--------------------------------------------------------------------------------------
		0. Ӧ�ó������ SocketInterface.h �� HPSocket.h ͷ�ļ�
		1. ���� HP_Create_Xxx() �������� HPSocket ����
		2. ʹ����Ϻ���� HP_Destroy_Xxx() �������� HPSocket ����

		��������
		--------------------------------------------------------------------------------------
		0. Ӧ�ó������ SocketInterface.h �� HPSocket.h ͷ�ļ�
		1. ���� CXxxPtr ����ָ�룬ͨ������ָ��ʹ�� HPSocket ����

Release:
		1. x86/HPSocket.dll		- (32λ/MBCS/Release)
		2. x86/HPSocket_D.dll	- (32λ/MBCS/DeBug)
		3. x86/HPSocket_U.dll	- (32λ/UNICODE/Release)
		4. x86/HPSocket_UD.dll	- (32λ/UNICODE/DeBug)
		5. x64/HPSocket.dll		- (64λ/MBCS/Release)
		6. x64/HPSocket_D.dll	- (64λ/MBCS/DeBug)
		7. x64/HPSocket_U.dll	- (64λ/UNICODE/Release)
		8. x64/HPSocket_UD.dll	- (64λ/UNICODE/DeBug)

******************************************************************************/

#pragma once

/**************************************************/
/********* imports / exports HPSocket.dll *********/

#ifdef HPSOCKET_EXPORTS
	#define HPSOCKET_API EXTERN_C __declspec(dllexport)
#else
	#define HPSOCKET_API EXTERN_C __declspec(dllimport)
#endif

#include "SocketInterface.h"

/**************************************************/
/************** HPSocket.dll �������� **************/

// ���� ITcpServer ����
HPSOCKET_API ITcpServer* HP_Create_TcpServer(ITcpServerListener* pListener);
// ���� ITcpClient ����
HPSOCKET_API ITcpClient* HP_Create_TcpClient(ITcpClientListener* pListener);
// ���� ITcpAgent ����
HPSOCKET_API ITcpAgent* HP_Create_TcpAgent(ITcpAgentListener* pListener);
// ���� ITcpPullServer ����
HPSOCKET_API ITcpPullServer* HP_Create_TcpPullServer(ITcpServerListener* pListener);
// ���� ITcpPullClient ����
HPSOCKET_API ITcpPullClient* HP_Create_TcpPullClient(ITcpClientListener* pListener);
// ���� ITcpPullAgent ����
HPSOCKET_API ITcpPullAgent* HP_Create_TcpPullAgent(ITcpAgentListener* pListener);
// ���� IUdpServer ����
HPSOCKET_API IUdpServer* HP_Create_UdpServer(IUdpServerListener* pListener);
// ���� IUdpClient ����
HPSOCKET_API IUdpClient* HP_Create_UdpClient(IUdpClientListener* pListener);

// ���� ITcpServer ����
HPSOCKET_API void HP_Destroy_TcpServer(ITcpServer* pServer);
// ���� ITcpClient ����
HPSOCKET_API void HP_Destroy_TcpClient(ITcpClient* pClient);
// ���� ITcpAgent ����
HPSOCKET_API void HP_Destroy_TcpAgent(ITcpAgent* pAgent);
// ���� ITcpPullServer ����
HPSOCKET_API void HP_Destroy_TcpPullServer(ITcpPullServer* pServer);
// ���� ITcpPullClient ����
HPSOCKET_API void HP_Destroy_TcpPullClient(ITcpPullClient* pClient);
// ���� ITcpPullAgent ����
HPSOCKET_API void HP_Destroy_TcpPullAgent(ITcpPullAgent* pAgent);
// ���� IUdpServer ����
HPSOCKET_API void HP_Destroy_UdpServer(IUdpServer* pServer);
// ���� IUdpClient ����
HPSOCKET_API void HP_Destroy_UdpClient(IUdpClient* pClient);

// ��ȡ���������ı�
HPSOCKET_API LPCTSTR HP_GetSocketErrorDesc(EnSocketError enCode);
// ����ϵͳ�� ::GetLastError() ������ȡϵͳ�������
HPSOCKET_API DWORD SYS_GetLastError	();
// ����ϵͳ�� ::WSAGetLastError() ������ȡͨ�Ŵ������
HPSOCKET_API int SYS_WSAGetLastError();
// ����ϵͳ�� setsockopt()
HPSOCKET_API int SYS_SetSocketOption(SOCKET sock, int level, int name, LPVOID val, int len);
// ����ϵͳ�� getsockopt()
HPSOCKET_API int SYS_GetSocketOption(SOCKET sock, int level, int name, LPVOID val, int* len);
// ����ϵͳ�� ioctlsocket()
HPSOCKET_API int SYS_IoctlSocket(SOCKET sock, long cmd, u_long* arg);
// ����ϵͳ�� ::WSAIoctl()
HPSOCKET_API int SYS_WSAIoctl(SOCKET sock, DWORD dwIoControlCode, LPVOID lpvInBuffer, DWORD cbInBuffer, LPVOID lpvOutBuffer, DWORD cbOutBuffer, LPDWORD lpcbBytesReturned);

// ITcpServer ���󴴽���
struct TcpServer_Creator
{
	static ITcpServer* Create(ITcpServerListener* pListener)
	{
		return HP_Create_TcpServer(pListener);
	}

	static void Destroy(ITcpServer* pServer)
	{
		HP_Destroy_TcpServer(pServer);
	}
};

// ITcpClient ���󴴽���
struct TcpClient_Creator
{
	static ITcpClient* Create(ITcpClientListener* pListener)
	{
		return HP_Create_TcpClient(pListener);
	}

	static void Destroy(ITcpClient* pClient)
	{
		HP_Destroy_TcpClient(pClient);
	}
};

// ITcpAgent ���󴴽���
struct TcpAgent_Creator
{
	static ITcpAgent* Create(ITcpAgentListener* pListener)
	{
		return HP_Create_TcpAgent(pListener);
	}

	static void Destroy(ITcpAgent* pAgent)
	{
		HP_Destroy_TcpAgent(pAgent);
	}
};

// ITcpPullServer ���󴴽���
struct TcpPullServer_Creator
{
	static ITcpPullServer* Create(ITcpServerListener* pListener)
	{
		return HP_Create_TcpPullServer(pListener);
	}

	static void Destroy(ITcpPullServer* pServer)
	{
		HP_Destroy_TcpPullServer(pServer);
	}
};

// ITcpPullClient ���󴴽���
struct TcpPullClient_Creator
{
	static ITcpPullClient* Create(ITcpClientListener* pListener)
	{
		return HP_Create_TcpPullClient(pListener);
	}

	static void Destroy(ITcpPullClient* pClient)
	{
		HP_Destroy_TcpPullClient(pClient);
	}
};

// ITcpPullAgent ���󴴽���
struct TcpPullAgent_Creator
{
	static ITcpPullAgent* Create(ITcpAgentListener* pListener)
	{
		return HP_Create_TcpPullAgent(pListener);
	}

	static void Destroy(ITcpPullAgent* pAgent)
	{
		HP_Destroy_TcpPullAgent(pAgent);
	}
};

// IUdpServer ���󴴽���
struct UdpServer_Creator
{
	static IUdpServer* Create(IUdpServerListener* pListener)
	{
		return HP_Create_UdpServer(pListener);
	}

	static void Destroy(IUdpServer* pServer)
	{
		HP_Destroy_UdpServer(pServer);
	}
};

// IUdpClient ���󴴽���
struct UdpClient_Creator
{
	static IUdpClient* Create(IUdpClientListener* pListener)
	{
		return HP_Create_UdpClient(pListener);
	}

	static void Destroy(IUdpClient* pClient)
	{
		HP_Destroy_UdpClient(pClient);
	}
};

/**************************************************/
/************** HPSocket ��������ָ�� **************/

template<class T, class _Listener, class _Creator> class CHPSocketPtr
{
public:
	CHPSocketPtr(_Listener* pListener = nullptr)
	{
		if(pListener)
			m_pObj = _Creator::Create(pListener);
		else
			m_pObj = nullptr;
	}

	~CHPSocketPtr()
	{
		Reset();
	}

public:
	CHPSocketPtr&  Reset(T* pObj = nullptr)
	{
		if(pObj != m_pObj)
		{
			if(m_pObj)
				_Creator::Destroy(m_pObj);

			m_pObj = pObj;
		}

		return *this;
	}

	CHPSocketPtr& Attach(T* pObj)
	{
		return Reset(pObj);
	}

	T* Detach()
	{
		T* pObj	= m_pObj;
		m_pObj	= nullptr;

		return pObj;
	}

	BOOL IsValid	()	const	{return m_pObj != nullptr	;}
	T* Get			()	const	{return m_pObj				;}
	T* operator ->	()	const	{return m_pObj				;}
	operator T*		()	const	{return m_pObj				;}

	CHPSocketPtr& operator = (T* pObj)	{return Reset(pObj)	;}

private:
	CHPSocketPtr(const CHPSocketPtr&);
	CHPSocketPtr& operator = (const CHPSocketPtr&);

private:
	T* m_pObj;
};

// ITcpServer ��������ָ��
typedef CHPSocketPtr<ITcpServer, ITcpServerListener, TcpServer_Creator>			CTcpServerPtr;
// ITcpClient ��������ָ��
typedef CHPSocketPtr<ITcpClient, ITcpClientListener, TcpClient_Creator>			CTcpClientPtr;
// ITcpAgent ��������ָ��
typedef CHPSocketPtr<ITcpAgent, ITcpAgentListener, TcpAgent_Creator>			CTcpAgentPtr;
// ITcpPullServer ��������ָ��
typedef CHPSocketPtr<ITcpPullServer, ITcpServerListener, TcpPullServer_Creator>	CTcpPullServerPtr;
// ITcpPullClient ��������ָ��
typedef CHPSocketPtr<ITcpPullClient, ITcpClientListener, TcpPullClient_Creator>	CTcpPullClientPtr;
// ITcpPullAgent ��������ָ��
typedef CHPSocketPtr<ITcpPullAgent, ITcpAgentListener, TcpPullAgent_Creator>	CTcpPullAgentPtr;
// IUdpServer ��������ָ��
typedef CHPSocketPtr<IUdpServer, IUdpServerListener, UdpServer_Creator>			CUdpServerPtr;
// IUdpClient ��������ָ��
typedef CHPSocketPtr<IUdpClient, IUdpClientListener, UdpClient_Creator>			CUdpClientPtr;