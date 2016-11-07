//
// SSLManager.h
//
// $Id: //poco/1.3/NetSSL_OpenSSL/include/Poco/Net/SSLManager.h#4 $
//
// Library: NetSSL_OpenSSL
// Package: SSLCore
// Module:  SSLManager
//
// Definition of the SSLManager class.
//
// Copyright (c) 2006-2009, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef NetSSL_SSLManager_INCLUDED
#define NetSSL_SSLManager_INCLUDED


#include "Poco/Net/NetSSL.h"
#include "Poco/Net/VerificationErrorArgs.h"
#include "Poco/Net/Context.h"
#include "Poco/Net/PrivateKeyFactoryMgr.h"
#include "Poco/Net/CertificateHandlerFactoryMgr.h"
#include "Poco/Net/InvalidCertificateHandler.h"
#include "Poco/BasicEvent.h"
#include "Poco/SharedPtr.h"
#include "Poco/Mutex.h"
#include <openssl/ssl.h>


namespace Poco {
namespace Net {


class Context;


class NetSSL_API SSLManager
	/// SSLManager is a singleton for holding the default server/client 
	/// Context and PrivateKeyPassphraseHandler.
	///
	/// Either initialize via Poco::Util::Application or via the
	/// initialize methods of the singleton. Note that the latter initialization must happen very early
	/// during program startup before somebody calls defaultClientContext()/defaultServerContext() 
	/// or any of the passPhraseHandler methods (which tries to auto-initialize
	/// the context and passphrase handler based on an Poco::Util::Application configuration).
	///
	/// An exemplary documentation which sets either the server or client default context and creates 
	/// a PrivateKeyPassphraseHandler that reads the password from the XML file looks like this:
	///
	///    <AppConfig>
	///       <openSSL>
	///          <server|client>
	///            <privateKeyFile>mycert.key</privateKeyFile>
	///            <certificateFile>mycert.crt</certificateFile>
	///            <caConfig>rootcert.pem</caConfig>
	///            <verificationMode>relaxed</verificationMode>
	///            <verificationDepth>9</verificationDepth>
	///            <loadDefaultCAFile>true</loadDefaultCAFile>
	///            <cypherList>ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH</cypherList>
	///            <privateKeyPassphraseHandler>
	///                <name>KeyFileHandler</name>
	///                <options>
	///                    <password>test</password>
	///                </options>
	///            </privateKeyPassphraseHandler>
	///            <invalidCertificateHandler>
	///                 <name>ConsoleCertificateHandler</name>
	///                 <options>
	///                 </options>
	///            </invalidCertificateHandler>
	///            <cacheSessions>true</cacheSessions>
	///          </server|client>
	///       </openSSL>
	///    </AppConfig>
{
public:
	typedef Poco::SharedPtr<PrivateKeyPassphraseHandler> PrivateKeyPassphraseHandlerPtr;
	typedef Poco::SharedPtr<InvalidCertificateHandler> InvalidCertificateHandlerPtr;

	Poco::BasicEvent<VerificationErrorArgs> ServerVerificationError;
		/// Thrown whenever a certificate error is detected by the server during a handshake.

	Poco::BasicEvent<VerificationErrorArgs> ClientVerificationError;
		/// Thrown whenever a certificate error is detected by the client during a handshake.

	Poco::BasicEvent<std::string> PrivateKeyPassPhrase;
		/// Thrown when a encrypted certificate is loaded. Not setting the password
		/// in the event parameter will result in a failure to load the certificate.
		///
		/// Per default the SSLManager checks the configuration.xml file (path openSSL.privateKeyPassphraseHandler.name)
		/// for which default delegate it should register. If nothing is configured,
		/// a KeyConsoleHandler is used.

	static SSLManager& instance();
		/// Returns the instance of the SSLManager singleton.

	void initializeServer(PrivateKeyPassphraseHandlerPtr ptrPassPhraseHandler, InvalidCertificateHandlerPtr ptrHandler, Context::Ptr ptrContext);
		/// Initializes the server side of the SSLManager with a default passphrase handler, a default invalid certificate handler and a default context. If this method
		/// is never called the SSLmanager will try to initialize its members from an application configuration.
		///
		/// Note: ALWAYS create the handlers before you create the context!
		///
		/// Valid initialization code would be:
		///    SharedPtr<PrivateKeyPassphraseHandler> ptrConsole = new KeyConsoleHandler();
		///    SharedPtr<InvalidCertificateHandler> ptrCert = new ConsoleCertificateHandler();
		///    Context::Ptr ptrContext = new Context("any.pem", "rootcert.pem", Context::Relaxed, 9, false, "ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH");
		///
		/// This method can only be called if no defaultContext is set yet.

	void initializeClient(PrivateKeyPassphraseHandlerPtr ptrPassPhraseHandler, InvalidCertificateHandlerPtr ptrHandler, Context::Ptr ptrContext);
		/// Initializes the client side of the SSLManager with a default passphrase handler, a default invalid certificate handler and a default context. If this method
		/// is never called the SSLmanager will try to initialize its members from an application configuration.
		///
		/// Note: ALWAYS create the handlers before you create the context!
		///
		/// Valid initialization code would be:
		///    SharedPtr<PrivateKeyPassphraseHandler> ptrConsole = new KeyConsoleHandler();
		///    SharedPtr<InvalidCertificateHandler> ptrCert = new ConsoleCertificateHandler();
		///    Context::Ptr ptrContext = new Context("any.pem", "rootcert.pem", Context::Relaxed, 9, false, "ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH");
		///
		/// This method can only be called if no defaultContext is set yet.

	Context::Ptr defaultServerContext();
		/// Returns the default context used by the server. The first call to this method initializes the defaultContext
		/// from an application configuration.

	Context::Ptr defaultClientContext();
		/// Returns the default context used by the client. The first call to this method initializes the defaultContext
		/// from an application configuration.

	PrivateKeyPassphraseHandlerPtr serverPassPhraseHandler();
		/// Returns the configured passphrase handler of the server. If none is set, the method will create a default one
		/// from an application configuration

	InvalidCertificateHandlerPtr serverCertificateHandler();
		/// Returns an initialized certificate handler (used by the server to verify client cert) which determines how invalid certificates are treated.
		/// If none is set, it will try to auto-initialize one from an application configuration.

	PrivateKeyPassphraseHandlerPtr clientPassPhraseHandler();
		/// Returns the configured passphrase handler of the client. If none is set, the method will create a default one
		/// from an application configuration

	InvalidCertificateHandlerPtr clientCertificateHandler();
		/// Returns an initialized certificate handler (used by the client to verify server cert) which determines how invalid certificates are treated.
		/// If none is set, it will try to auto-initialize one from an application configuration.

	PrivateKeyFactoryMgr& privateKeyFactoryMgr();
		/// Returns the private key factory manager which stores the 
		/// factories for the different registered passphrase handlers for private keys.

	CertificateHandlerFactoryMgr& certificateHandlerFactoryMgr();
		/// Returns the CertificateHandlerFactoryMgr which stores the 
		/// factories for the different registered certificate handlers.

	static const std::string CFG_SERVER_PREFIX;
	static const std::string CFG_CLIENT_PREFIX;

protected:
	static int verifyClientCallback(int ok, X509_STORE_CTX* pStore);
		/// The return value of this method defines how errors in
		/// verification are handled. Return 0 to terminate the handshake,
		/// or 1 to continue despite the error.

	static int verifyServerCallback(int ok, X509_STORE_CTX* pStore);
		/// The return value of this method defines how errors in
		/// verification are handled. Return 0 to terminate the handshake,
		/// or 1 to continue despite the error.

	static int privateKeyPasswdCallback(char* pBuf, int size, int flag, void* userData);
		/// Method is invoked by OpenSSL to retrieve a passwd for an encrypted certificate.
		/// The request is delegated to the PrivatekeyPassword event. This method returns the
		/// length of the password.

private:
	SSLManager();
		/// Creates the SSLManager.

	~SSLManager();
		/// Destroys the SSLManager.

	void initDefaultContext(bool server);
		/// Inits the default context, the first time it is accessed.

	void initEvents(bool server);
		/// Registers delegates at the events according to the configuration.

	void initPassPhraseHandler(bool server);
		/// Inits the passphrase handler.

	void initCertificateHandler(bool server);
		/// Inits the certificate handler.

	static int verifyCallback(bool server, int ok, X509_STORE_CTX* pStore);
		/// The return value of this method defines how errors in
		/// verification are handled. Return 0 to terminate the handshake,
		/// or 1 to continue despite the error.

	PrivateKeyFactoryMgr           _factoryMgr;
	CertificateHandlerFactoryMgr   _certHandlerFactoryMgr;
	Context::Ptr                   _ptrDefaultServerContext;
	PrivateKeyPassphraseHandlerPtr _ptrServerPassPhraseHandler;
	InvalidCertificateHandlerPtr   _ptrServerCertificateHandler;
	Context::Ptr                   _ptrDefaultClientContext;
	PrivateKeyPassphraseHandlerPtr _ptrClientPassPhraseHandler;
	InvalidCertificateHandlerPtr   _ptrClientCertificateHandler;
	Poco::FastMutex                _mutex;

	static const std::string CFG_PRIV_KEY_FILE;
	static const std::string CFG_CERTIFICATE_FILE;
	static const std::string CFG_CA_LOCATION;
	static const std::string CFG_VER_MODE;
	static const Context::VerificationMode VAL_VER_MODE;
	static const std::string CFG_VER_DEPTH;
	static const int         VAL_VER_DEPTH;
	static const std::string CFG_ENABLE_DEFAULT_CA;
	static const bool        VAL_ENABLE_DEFAULT_CA;
	static const std::string CFG_CYPHER_LIST;
	static const std::string VAL_CYPHER_LIST;
	static const std::string CFG_DELEGATE_HANDLER;
	static const std::string VAL_DELEGATE_HANDLER;
	static const std::string CFG_CERTIFICATE_HANDLER;
	static const std::string VAL_CERTIFICATE_HANDLER;
	static const std::string CFG_CACHE_SESSIONS;

	friend class Poco::SingletonHolder<SSLManager>;
	friend class Context;
};


//
// inlines
//
inline PrivateKeyFactoryMgr& SSLManager::privateKeyFactoryMgr()
{
	return _factoryMgr;
}


inline CertificateHandlerFactoryMgr& SSLManager::certificateHandlerFactoryMgr()
{
	return _certHandlerFactoryMgr;
}


inline int SSLManager::verifyServerCallback(int ok, X509_STORE_CTX* pStore)
{
	return SSLManager::verifyCallback(true, ok, pStore);
}


inline int SSLManager::verifyClientCallback(int ok, X509_STORE_CTX* pStore)
{
	return SSLManager::verifyCallback(false, ok, pStore);
}


} } // namespace Poco::Net


#endif // NetSSL_SSLManager_INCLUDED
