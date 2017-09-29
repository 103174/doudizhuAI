//////////////////////////////////////////////////////////////
// Utils.h
#ifndef __INC_UTILS_DEF_H__
#define __INC_UTILS_DEF_H__

#pragma once

#include <iostream>
using namespace std;


#define round(f) (((f) > 0 ? (f) + 0.5 : (f) - 0.5))

// print a message while compiling
// usage: #pragma mesage(__FILELINE__, "message-text")
#define __STR2__(x) #x
#define __STR1__(x) __STR2__(x)
#define __FILELINE__ __FILE__ "("__STR1__(__LINE__)") : "

// singleton
#define DECLARE_SINGLETON(x)	\
static x *m_pInstance;			\
static x *Instance()			\
{								\
	if (!m_pInstance)			\
		m_pInstance =	new x;	\
	return m_pInstance;			\
}								\
static void ReleaseInstance()	\
{								\
	delete(m_pInstance);			\
	m_pInstance = NULL;			\
}

#define IMPLEMENT_SINGLETON(x)	x *x::m_pInstance = NULL;

#define DEFINE_REGISTERED_MESSAGE(message)	UINT message = ::RegisterWindowMessage("9CAF76A6-1449-11d4-BC50-00400533C4C1:"#message);
#define DEFINE_CLIPBOARD_FORMAT(format)		UINT format = ::RegisterClipboardFormat("9CAF76A6-1449-11d4-BC50-00400533C4C1:"#format);


#endif //__INC_UTILS_DEF_H__