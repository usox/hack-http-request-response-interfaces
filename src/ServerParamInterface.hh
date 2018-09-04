<?hh // strict
/*
 *  Copyright (c) 2014 PHP Framework Interoperability Group
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 *
 *  Portions Copyright (c) 2018-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the MIT license found in the
 *  LICENSE file in the root directory of this source tree.
 *
 */

namespace Facebook\Experimental\Http\Message;

interface ServerParamInterface {

	/**
	 * The filename of the currently executing script, relative to the document root.
	 */
	public function getPhpSelf(): string;

	/**
	 * Vector of arguments passed to the script. When the script is run on the command line,
	 * this gives C-style access to the command line parameters. When called via the GET
	 * method, this will return the query string.
	 */
	public function getArgV(): vec<string>;

	/**
	 * Returns the number of command line parameters passed to the script (if run on the
	 * command line).
	 */
	public function getArgC(): int;

	/**
	 * Returns the size of the message-body attached to the request, if any.
	 */
	public function getContentLength(): int;

	/**
	 * Will return the Internet Media Type of the message-body.
	 */
	public function getContentType(): string;

	/**
	 * What revision of the CGI specification the server is using; i.e. 'CGI/1.1'.
	 */
	public function getGatewayInterface(): string;

	/**
	 * The IP address of the server under which the current script is executing.
	 */
	public function getServerAddr(): string;

	/**
	 * The name of the server host under which the current script is executing.
	 * If the script is running on a virtual host, this will be the value defined for that virtual host.
	 */
	public function getServerName(): string;

	/**
	 * Server identification string, given in the headers when responding to requests.
	 */
	public function getServerSoftware(): string;

	/**
	 * Name and revision of the information protocol via which the page was requested; i.e. 'HTTP/1.0';
	 */
	public function getServerProtocol(): string;

	/**
	 * Which request method was used to access the page; i.e. 'GET', 'HEAD', 'POST', 'PUT'.
	 */
	public function getRequestMethod(): HTTPMethod;

	/**
	 * The timestamp of the start of the request.
	 */
	public function getRequestTime(): int;

	/**
	 * The timestamp of the start of the request, with microsecond precision.
	 */
	public function getRequestTimeFloat(): float;

	/**
	 * The query string, if any, via which the page was accessed.
	 */
	public function getQueryString(): string;

	/**
	 * The document root directory under which the current script is executing, as defined in the server's
	 * configuration file.
	 */
	public function getDocumentRoot(): string;

	/**
	 * Contents of the Accept: header from the current request, if there is one.
	 */
	public function getHttpAccept(): string;

	/**
	 * Contents of the Accept-Charset: header from the current request, if there is one.
	 * Example: 'iso-8859-1,*,utf-8'.
	 */
	public function getHttpAcceptCharset(): string;

	/**
	 * Contents of the Accept-Encoding: header from the current request, if there is one.
	 * Example: 'gzip'.
	 */
	public function getHttpAcceptEncoding(): string;

	/**
	 * Contents of the Accept-Language: header from the current request, if there is one.
	 * Example: 'en'.
	 */
	public function getHttpAcceptLanguage(): string;

	/**
	 * Contents of the Connection: header from the current request, if there is one.
	 * Example: 'Keep-Alive'.
	 */
	public function getHttpConnection(): string;

	/**
	 * Contents of the Host: header from the current request, if there is one.
	 */
	public function getHttpHost(): string;

	/**
	 * The address of the page (if any) which referred the user agent to the current page.
	 */
	public function getHttpReferer(): string;

	/**
	 * Contents of the User-Agent: header from the current request, if there is one.
	 */
	public function getHttpUserAgent(): string;

	/**
	 * Set to a non-empty value if the script was queried through the HTTPS protocol.
	 */
	public function getHttps(): string;

	/**
	 * The IP address from which the user is viewing the current page.
	 */
	public function getRemoteAddr(): string;

	/**
	 * The Host name from which the user is viewing the current page.
	 */
	public function getRemoteHost(): string;

	/**
	 * The port being used on the user's machine to communicate with the web server.
	 */
	public function getRemotePort(): int;

	/**
	 * The authenticated user.
	 */
	public function getRemoteUser(): string;

	/**
	 * The authenticated user if the request is internally redirected.
	 */
	public function getRedirectRemoteUser(): string;

	/**
	 * The absolute pathname of the currently executing script.
	 */
	public function getScriptFilename(): string;

	/**
	 * The value given to the SERVER_ADMIN (for Apache) directive in the web server
	 * configuration file. If the script is running on a virtual host, this will
	 * be the value defined for that virtual host.
	 */
	public function getServerAdmin(): string;

	/**
	 * The port on the server machine being used by the web server for communication.
	 */
	public function getServerPort(): int;

	/**
	 * Returns a string containing the server version and virtual host name which are
	 * added to server-generated pages, if enabled.
	 */
	public function getServerSignature(): string;

	/**
	 * Filesystem- (not document root-) based path to the current script, after the
	 * server has done any virtual-to-real mapping.
	 */
	public function getPathTranslated(): string;

	/**
	 * Returns the current script's path. This is useful for pages which need to
	 * point to themselves.
	 */
	public function getScriptName(): string;

	/**
	 * The URI which was given in order to access this page; for instance, '/index.html'.
	 */
	public function getRequestUri(): string;

	/**
	 * When doing Digest HTTP authentication this variable is set to the
	 * 'Authorization' header sent by the client.
	 */
	public function getPhpAuthDigest(): string;

	/**
	 * When doing HTTP authentication this variable is set to the username provided
	 * by the user.
	 */
	public function getPhpAuthUser(): string;

	/**
	 * When doing HTTP authentication this variable is set to the password provided
	 * by the user.
	 */
	public function getPhpAuthPw(): string;

	/**
	 * When doing HTTP authentication this variable is set to the authentication type.
	 */
	public function getAuthType(): string;

	/**
	 * Returns any client-provided pathname information trailing the actual script
	 * filename but preceding the query string, if available.
	 */
	public function getPathInfo(): string;

	/**
	 * Original version of 'PATH_INFO' before processed.
	 */
	public function getOrigPathInfo(): string;
}
